//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define POP3_PORT 110

struct POP3_response {
  char status;
  char message[256];
};

int main() {
  struct addrinfo hints, *server_info;
  int sockfd, n;
  struct sockaddr_in server_addr;
  char buffer[256];
  char username[256], password[256];

  // Get server address and port
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  if (getaddrinfo("pop.example.com", "110", &hints, &server_info) != 0) {
    perror("getaddrinfo");
    exit(EXIT_FAILURE);
  }

  // Create socket
  sockfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to server
  if (connect(sockfd, server_info->ai_addr, server_info->ai_addrlen) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Get username and password
  printf("Enter your POP3 username: ");
  fgets(username, sizeof(username), stdin);
  printf("Enter your POP3 password: ");
  fgets(password, sizeof(password), stdin);

  // Send username and password
  send(sockfd, username, strlen(username), 0);
  send(sockfd, password, strlen(password), 0);

  // Receive response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Print response
  printf("%s\n", buffer);

  // Close socket
  close(sockfd);

  return 0;
}