//FormAI DATASET v1.0 Category: Chat server ; Style: decentralized
#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8000
#define MAX_CONNECTIONS 5
#define MAX_DATA_SIZE 1024
#define MAX_CLIENTS 256

/* Declaration of functions */
void *connection_handler(void *socket_fd_ptr);
void broadcast_message(int sender_fd, char *message, int message_size);

/* Declaration of global variables */
int client_fds[MAX_CLIENTS]; // array of clients' file descriptors
int num_clients = 0;         // counter for connected clients
int server_fd;               // file descriptor for server's socket

int main(int argc, char *argv[]) {
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len = sizeof(client_addr);
  int socket_fd;

  // Create socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set socket options to allow reuse of port
  int yes = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) ==
      -1) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Set up server's socket address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  memset(&(server_addr.sin_zero), '\0', 8);

  // Bind socket to server address
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) ==
      -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Start listening for incoming connections
  if (listen(server_fd, MAX_CONNECTIONS) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d...\n", PORT);

  // Set up signal handling to gracefully shut down server
  signal(SIGINT, SIG_IGN);
  signal(SIGTERM, SIG_IGN);
  struct sigaction sig_act;
  sig_act.sa_handler = &exit;
  sigaction(SIGINT, &sig_act, NULL);
  sigaction(SIGTERM, &sig_act, NULL);

  // Main loop for accepting client connections
  while (1) {
    // Wait for and accept incoming client connections
    if ((socket_fd = accept(server_fd, (struct sockaddr *)&client_addr,
                            &client_len)) == -1) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    // Add client file descriptor to list of client fds
    client_fds[num_clients++] = socket_fd;

    // Create new thread to handle connection
    pthread_t thread;
    if (pthread_create(&thread, NULL, connection_handler,
                       (void *)&socket_fd) != 0) {
      perror("pthread_create");
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}

/* Handle incoming client connection */
void *connection_handler(void *socket_fd_ptr) {
  int socket_fd = *(int *)socket_fd_ptr;
  char client_msg[MAX_DATA_SIZE];
  int num_bytes;

  // Get client address
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  if (getpeername(socket_fd, (struct sockaddr *)&client_addr,
                  &client_len) == -1) {
    perror("getpeername");
    exit(EXIT_FAILURE);
  }

  // Print welcome message to client
  printf("New client connected from %s:%d\n",
         inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

  // Main loop for handling client messages
  while ((num_bytes = recv(socket_fd, client_msg, MAX_DATA_SIZE, 0)) > 0) {
    client_msg[num_bytes] = '\0';

    // Check if client wants to disconnect
    if (strcmp(client_msg, "quit\n") == 0 ||
        strcmp(client_msg, "exit\n") == 0) {
      printf("Client from %s:%d disconnected\n", inet_ntoa(client_addr.sin_addr),
             ntohs(client_addr.sin_port));
      close(socket_fd);
      break;
    }

    // Broadcast message to all other clients
    broadcast_message(socket_fd, client_msg, num_bytes);
  }

  // Remove client file descriptor from list of client fds
  int i;
  for (i = 0; i < num_clients; i++) {
    if (client_fds[i] == socket_fd) {
      while (i < num_clients - 1) {
        client_fds[i] = client_fds[i + 1];
        i++;
      }
      num_clients--;
      break;
    }
  }

  pthread_exit(0);
}

/* Broadcast message to all other clients */
void broadcast_message(int sender_fd, char *message, int message_size) {
  int i;
  for (i = 0; i < num_clients; i++) {
    if (client_fds[i] != sender_fd) {
      if (send(client_fds[i], message, message_size, 0) == -1) {
        perror("send");
      }
    }
  }
}