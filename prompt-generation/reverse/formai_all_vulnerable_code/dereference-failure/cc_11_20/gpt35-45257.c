//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <sys/time.h>

#define PORT 8080 // Port to listen on
#define MAX_CLIENTS 100 // Maximum number of clients
#define TIMEOUT_SEC 5 // Number of seconds for timeout
#define BUFFER_SIZE 1024 // Size of buffer for sending/receiving messages

int main(int argc, char *argv[]) {
  // Parse command line arguments for IP address and port number
  if (argc != 3) {
    printf("Usage: %s <ip-address> <port>\n", argv[0]);
    return 1;
  }
  char *ip_address = argv[1];
  int port_number = atoi(argv[2]);

  // Create socket
  int server_fd;
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    return 1;
  }

  // Set socket options for reusability
  int opt = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt failed");
    return 1;
  }

  // Bind socket to IP address and port number
  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr(ip_address);
  address.sin_port = htons(port_number);
  if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
    perror("bind failed");
    return 1;
  }

  // Listen for incoming connections
  if (listen(server_fd, MAX_CLIENTS) < 0) {
    perror("listen failed");
    return 1;
  }

  // Accept incoming connections
  int client_fd;
  struct sockaddr_in client_address;
  socklen_t client_address_length = sizeof(client_address);
  fd_set master_set, read_set;
  FD_ZERO(&master_set);
  FD_SET(server_fd, &master_set);
  int max_fd = server_fd;
  struct timeval timeout;
  timeout.tv_sec = TIMEOUT_SEC;
  timeout.tv_usec = 0;
  char buffer[BUFFER_SIZE];
  while (1) {
    read_set = master_set;
    if (select(max_fd + 1, &read_set, NULL, NULL, &timeout) < 0) {
      perror("select failed");
      return 1;
    }
    for (int fd = 0; fd <= max_fd; fd++) {
      if (FD_ISSET(fd, &read_set)) {
        if (fd == server_fd) {
          client_fd = accept(server_fd, (struct sockaddr *) &client_address, &client_address_length);
          if (client_fd < 0) {
            perror("accept failed");
            return 1;
          }
          printf("New client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
          FD_SET(client_fd, &master_set);
          if (client_fd > max_fd) {
            max_fd = client_fd;
          }
        } else {
          int num_bytes = recv(fd, buffer, sizeof(buffer), 0);
          if (num_bytes <= 0) {
            if (num_bytes == 0) {
              printf("Client %d disconnected\n", fd);
            } else {
              printf("recv failed on client %d\n", fd);
            }
            close(fd);
            FD_CLR(fd, &master_set);
          } else {
            buffer[num_bytes] = '\0';
            printf("Received message from client %d: %s", fd, buffer);
            // TODO: Perform QoS checks and monitor network quality
          }
        }
      }
    }
  }
  return 0;
}