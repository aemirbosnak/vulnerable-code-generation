//Falcon-180B DATASET v1.0 Category: Networking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[BUFFER_SIZE];
  int len;
  struct hostent *server;

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Socket failed");
    exit(EXIT_FAILURE);
  }

  printf("Enter the server IP address: ");
  scanf("%s", buffer);

  server = gethostbyname(buffer);
  if (server == NULL) {
    printf("Host not found\n");
    exit(EXIT_FAILURE);
  }

  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(80);

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Connection failed");
    exit(EXIT_FAILURE);
  }

  printf("Connected to server\n");

  // Receive data from server
  len = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (len < 0) {
    perror("Receive failed");
    exit(EXIT_FAILURE);
  } else {
    buffer[len] = '\0';
    printf("Received data from server: %s\n", buffer);
  }

  // Send data to server
  send(sockfd, "Hello, server!", strlen("Hello, server!"), 0);

  // Close socket
  close(sockfd);

  return 0;
}