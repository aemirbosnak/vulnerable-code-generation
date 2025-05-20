//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

static void connection_handler(int clientfd) {
  int remote_socket_fd = -1;
  char buffer[BUFFER_SIZE];
  struct sockaddr_in remote_addr;
  socklen_t remote_addr_len = sizeof(remote_addr);

  memset(&remote_addr, 0, sizeof(struct sockaddr_in));
  while (recv(clientfd, buffer, BUFFER_SIZE, 0) > 0) {
    char* newline_pos = strchr(buffer, '\n');
    if (newline_pos != NULL) {
      *newline_pos = '\0';
    }

    char* request_host = strtok(buffer, " ");
    char* request_port = strtok(NULL, ":");
    char* request_method = strtok(NULL, " ");
    char* request_path = strtok(NULL, " ");
    if (strncmp(request_path, "http", 4) == 0) {
      request_path += 4;
      request_path = strstr(request_path, "//") + 2;
    }
    char* request_path_end = strrchr(request_path, ' ');
    if (request_path_end != NULL) {
      *request_path_end = '\0';
    }

    remote_socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (remote_socket_fd < 0) {
      perror("Failed to create remote socket");
      break;
    }

    struct hostent* remote_host = gethostbyname(request_host);
    if (remote_host == NULL) {
      perror("Failed to get remote host");
      break;
    }

    memcpy(&remote_addr.sin_addr.s_addr, remote_host->h_addr_list[0], sizeof(remote_addr.sin_addr.s_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(request_port == NULL ? 80 : atoi(request_port));

    if (connect(remote_socket_fd, (struct sockaddr*) &remote_addr, sizeof(remote_addr)) < 0) {
      perror("Failed to connect remote socket");
      break;
    }

    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "%s %s HTTP/1.0\n\n", request_method, request_path);

    if (send(remote_socket_fd, request, strlen(request), 0) < 0) {
      perror("Failed to send request");
      break;
    }

    int received_bytes = -1;
    while ((received_bytes = recv(remote_socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {
      if (send(clientfd, buffer, received_bytes, 0) < 0) {
        perror("Failed to send response from remote host");
        break;
      }
    }
  }

  if (remote_socket_fd >= 0) {
    shutdown(remote_socket_fd, SHUT_RDWR);
    close(remote_socket_fd);
  }

  shutdown(clientfd, SHUT_RDWR);
  close(clientfd);
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int listen_port = atoi(argv[1]);
  if (listen_port <= 0) {
    fprintf(stderr, "Invalid port number: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("Failed to create server socket");
    return EXIT_FAILURE;
  }

  int enable = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
    perror("Failed to set socket option");
    return EXIT_FAILURE;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(struct sockaddr_in));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(listen_port);

  if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
    perror("Failed to bind server socket");
    return EXIT_FAILURE;
  }

  if (listen(server_fd, SOMAXCONN) < 0) {
    perror("Failed to listen on server socket");
    return EXIT_FAILURE;
  }

  printf("Proxy is listening on port %d\n", listen_port);

  while (1) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_socket_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_addr_len);
    if (client_socket_fd < 0) {
      perror("Failed to accept client socket");
      continue;
    }

    pid_t child_pid = fork();
    if (child_pid == 0) {
      connection_handler(client_socket_fd);
      return EXIT_SUCCESS;
    }

    close(client_socket_fd);
  }

  close(server_fd);
  return EXIT_SUCCESS;
}