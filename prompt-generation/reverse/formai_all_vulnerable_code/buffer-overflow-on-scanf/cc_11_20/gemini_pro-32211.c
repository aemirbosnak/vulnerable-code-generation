//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
  // Declare the variables we'll need
  char username[100];
  char password[100];
  char server[100];
  char port[100];
  int sockfd;
  struct sockaddr_in servaddr;

  // Get the user's input
  printf("Email server: ");
  scanf("%s", server);
  printf("Port: ");
  scanf("%s", port);
  printf("Username: ");
  scanf("%s", username);
  printf("Password: ");
  scanf("%s", password);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Could not create socket");
    exit(1);
  }

  // Set up the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(port));
  servaddr.sin_addr.s_addr = inet_addr(server);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Could not connect to server");
    exit(1);
  }

  // Send the USER command
  char user_cmd[strlen(username) + 10];
  sprintf(user_cmd, "USER %s\r\n", username);
  if (send(sockfd, user_cmd, strlen(user_cmd), 0) < 0) {
    perror("Could not send USER command");
    exit(1);
  }

  // Receive the server's response
  char recv_buf[1024];
  if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) < 0) {
    perror("Could not receive server's response");
    exit(1);
  }

  // Check if the server's response is positive
  if (strstr(recv_buf, "+OK") == NULL) {
    printf("Server did not accept USER command\n");
    exit(1);
  }

  // Send the PASS command
  char pass_cmd[strlen(password) + 10];
  sprintf(pass_cmd, "PASS %s\r\n", password);
  if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) < 0) {
    perror("Could not send PASS command");
    exit(1);
  }

  // Receive the server's response
  if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) < 0) {
    perror("Could not receive server's response");
    exit(1);
  }

  // Check if the server's response is positive
  if (strstr(recv_buf, "+OK") == NULL) {
    printf("Server did not accept PASS command\n");
    exit(1);
  }

  // Send the STAT command
  if (send(sockfd, "STAT\r\n", 6, 0) < 0) {
    perror("Could not send STAT command");
    exit(1);
  }

  // Receive the server's response
  if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) < 0) {
    perror("Could not receive server's response");
    exit(1);
  }

  // Print the server's response
  printf("Number of messages: %s\n", recv_buf);

  // Send the LIST command
  if (send(sockfd, "LIST\r\n", 6, 0) < 0) {
    perror("Could not send LIST command");
    exit(1);
  }

  // Receive the server's response
  if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) < 0) {
    perror("Could not receive server's response");
    exit(1);
  }

  // Print the server's response
  printf("List of messages:\n%s\n", recv_buf);

  // Send the RETR command
  if (send(sockfd, "RETR 1\r\n", 8, 0) < 0) {
    perror("Could not send RETR command");
    exit(1);
  }

  // Receive the server's response
  if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) < 0) {
    perror("Could not receive server's response");
    exit(1);
  }

  // Print the server's response
  printf("Message:\n%s\n", recv_buf);

  // Send the QUIT command
  if (send(sockfd, "QUIT\r\n", 6, 0) < 0) {
    perror("Could not send QUIT command");
    exit(1);
  }

  // Close the socket
  close(sockfd);

  return 0;
}