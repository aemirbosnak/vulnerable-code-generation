//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
  int sockfd;
  char buffer[MAXLINE];
  char *hello = "Hello from server";
  struct sockaddr_in servaddr, cliaddr;

  // 1. Create a socket
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  // 2. Set server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET; // IPv4
  servaddr.sin_addr.s_addr = INADDR_ANY; // Bind to all interfaces
  servaddr.sin_port = htons(PORT); // htons converts host byte order to network byte order

  // 3. Bind the socket to the server address
  if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // 4. Receive a message from the client
  int len, n;

  len = sizeof(cliaddr);
  n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
  buffer[n] = '\0';
  printf("Client : %s\n", buffer);

  // 5. Send a message to the client
  sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
  printf("Server : %s\n", hello);

  // 6. Close the socket
  close(sockfd);

  return 0;
}