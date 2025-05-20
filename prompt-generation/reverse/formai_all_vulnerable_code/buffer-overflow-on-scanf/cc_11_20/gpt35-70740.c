//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  // Require hostname and port arguments
  if (argc < 3) {
    fprintf(stderr, "USAGE: %s <hostname> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *hostname = argv[1], *port = argv[2];
  // Retrieve IP address
  struct hostent *he;
  if ((he = gethostbyname(hostname)) == NULL) {
    fprintf(stderr, "Could not resolve hostname '%s'\n", hostname);
    exit(EXIT_FAILURE);
  }
  struct in_addr **addr_list = (struct in_addr **)he->h_addr_list;
  char ip_address[INET_ADDRSTRLEN];
  inet_ntop(he->h_addrtype, *addr_list, ip_address, INET_ADDRSTRLEN);

  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Initialize sockaddr_in structure
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(atoi(port));
  server_address.sin_addr = *((struct in_addr *)he->h_addr);
  memset(&(server_address.sin_zero), '\0', 8);

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(struct sockaddr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Receive server greeting
  char buffer[BUFFER_SIZE];
  memset(buffer, 0, BUFFER_SIZE);
  if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  printf("%s", buffer);

  // Send user credentials
  char username[BUFFER_SIZE], password[BUFFER_SIZE];
  printf("Username: ");
  scanf("%s", username);
  printf("Password: ");
  scanf("%s", password);
  char user_message[BUFFER_SIZE], pass_message[BUFFER_SIZE];
  sprintf(user_message, "USER %s\r\n", username);
  sprintf(pass_message, "PASS %s\r\n", password);
  if (send(sockfd, user_message, strlen(user_message), 0) < 0 ||
      recv(sockfd, buffer, BUFFER_SIZE, 0) < 0 ||
      send(sockfd, pass_message, strlen(pass_message), 0) < 0 ||
      recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
    perror("send/recv");
    exit(EXIT_FAILURE);
  }
  printf("%s", buffer);

  // Send command to list emails
  char list_message[] = "LIST\r\n";
  if (send(sockfd, list_message, strlen(list_message), 0) < 0 ||
      recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
    perror("send/recv");
    exit(EXIT_FAILURE);
  }
  printf("%s", buffer);

  // Send command to quit
  char quit_message[] = "QUIT\r\n";
  if (send(sockfd, quit_message, strlen(quit_message), 0) < 0 ||
      recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
    perror("send/recv");
    exit(EXIT_FAILURE);
  }
  printf("%s", buffer);

  // Close socket
  close(sockfd);

  return 0;
}