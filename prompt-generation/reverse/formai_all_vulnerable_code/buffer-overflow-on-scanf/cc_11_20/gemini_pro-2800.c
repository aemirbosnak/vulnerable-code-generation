//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 110

int main() {
  int sockfd, i, len;
  char buffer[1024], username[100], password[100], command[100];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Connection failed");
    exit(EXIT_FAILURE);
  }

  // Receive the welcome message
  len = recv(sockfd, buffer, sizeof(buffer), 0);
  if (len < 0) {
    perror("Receive failed");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", buffer);

  // Send the username
  printf("Enter your username: ");
  scanf("%s", username);
  len = strlen(username);
  buffer[0] = 'U';
  buffer[1] = 'S';
  buffer[2] = 'E';
  buffer[3] = 'R';
  buffer[4] = ' ';
  for (i = 5; i < len + 5; i++) {
    buffer[i] = username[i - 5];
  }
  buffer[len + 5] = '\r';
  buffer[len + 6] = '\n';
  len += 7;

  if (send(sockfd, buffer, len, 0) < 0) {
    perror("Send failed");
    exit(EXIT_FAILURE);
  }

  // Receive the server response
  len = recv(sockfd, buffer, sizeof(buffer), 0);
  if (len < 0) {
    perror("Receive failed");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", buffer);

  // Send the password
  printf("Enter your password: ");
  scanf("%s", password);
  len = strlen(password);
  buffer[0] = 'P';
  buffer[1] = 'A';
  buffer[2] = 'S';
  buffer[3] = 'S';
  buffer[4] = ' ';
  for (i = 5; i < len + 5; i++) {
    buffer[i] = password[i - 5];
  }
  buffer[len + 5] = '\r';
  buffer[len + 6] = '\n';
  len += 7;

  if (send(sockfd, buffer, len, 0) < 0) {
    perror("Send failed");
    exit(EXIT_FAILURE);
  }

  // Receive the server response
  len = recv(sockfd, buffer, sizeof(buffer), 0);
  if (len < 0) {
    perror("Receive failed");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", buffer);

  // Send the LIST command
  strcpy(command, "LIST\r\n");
  len = strlen(command);

  if (send(sockfd, command, len, 0) < 0) {
    perror("Send failed");
    exit(EXIT_FAILURE);
  }

  // Receive the server response
  len = recv(sockfd, buffer, sizeof(buffer), 0);
  if (len < 0) {
    perror("Receive failed");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}