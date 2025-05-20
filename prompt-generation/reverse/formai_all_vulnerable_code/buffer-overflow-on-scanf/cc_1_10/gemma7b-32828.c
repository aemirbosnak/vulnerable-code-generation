//Gemma-7B DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define POP3_PORT 110

int main() {
  int sockfd, n, len, flag = 0;
  char buf[1024], username[256], password[256], message[1024];
  struct sockaddr_in srv_addr;

  // Socket setup
  sockfd = socket(AF_INET, SOCK_STREAM, htons(POP3_PORT));
  if (sockfd == -1) {
    perror("Socket error");
    return 1;
  }

  // Server address
  srv_addr.sin_family = AF_INET;
  srv_addr.sin_port = htons(POP3_PORT);
  srv_addr.sin_addr.s_addr = inet_addr("localhost");

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) == -1) {
    perror("Connect error");
    return 1;
  }

  // Login
  printf("Enter username: ");
  scanf("%s", username);

  printf("Enter password: ");
  scanf("%s", password);

  len = strlen(username) + strlen(password) + 1;
  strcpy(buf, "USER ");
  strcat(buf, username);
  strcat(buf, "\r\n");
  strcat(buf, "PASS ");
  strcat(buf, password);
  strcat(buf, "\r\n");

  write(sockfd, buf, len);

  // Check for login success
  read(sockfd, buf, 1024);
  if (strstr(buf, "OK") == NULL) {
    perror("Login failed");
    return 1;
  }

  // Get message
  printf("Enter message: ");
  scanf("%s", message);

  len = strlen(message) + 1;
  strcpy(buf, "MSG ");
  strcat(buf, message);
  strcat(buf, "\r\n");

  write(sockfd, buf, len);

  // Read server response
  read(sockfd, buf, 1024);

  // Print message
  printf("Server response: \n");
  printf("%s", buf);

  // Logout
  flag = 1;
  len = strlen("LOGOUT\r\n") + 1;
  strcpy(buf, "LOGOUT\r\n");

  write(sockfd, buf, len);

  // Close socket
  close(sockfd);

  if (flag) {
    printf("Goodbye!\n");
  }

  return 0;
}