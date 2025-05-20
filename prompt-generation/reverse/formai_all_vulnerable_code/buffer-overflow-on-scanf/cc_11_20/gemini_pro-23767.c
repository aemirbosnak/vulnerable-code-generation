//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main() {
  // Welcome the user to the POP3 client!
  printf("OMG! Welcome to the POP3 Client! Are you ready to be blown away?!\n");

  // Get the server hostname and port number from the user.
  char hostname[100];
  int port;
  printf("What's the hostname of the POP3 server, dude? ");
  scanf("%s", hostname);
  printf("And what port is it listening on? ");
  scanf("%d", &port);

  // Create a socket and connect to the POP3 server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("OMG! I can't create a socket!");
    return -1;
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(hostname);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("OMG! I can't connect to the server!");
    close(sockfd);
    return -1;
  }

  // Receive the welcome message from the server.
  char buf[MAX_BUF_SIZE];
  int n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (n == -1) {
    perror("OMG! I can't receive the welcome message!");
    close(sockfd);
    return -1;
  }

  printf("%s", buf);

  // Send the USER command to the server.
  char username[100];
  printf("What's your username, dude? ");
  scanf("%s", username);
  sprintf(buf, "USER %s\r\n", username);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("OMG! I can't send the USER command!");
    close(sockfd);
    return -1;
  }

  // Receive the response from the server.
  n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (n == -1) {
    perror("OMG! I can't receive the response to the USER command!");
    close(sockfd);
    return -1;
  }

  printf("%s", buf);

  // Send the PASS command to the server.
  char password[100];
  printf("What's your password, dude? ");
  scanf("%s", password);
  sprintf(buf, "PASS %s\r\n", password);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("OMG! I can't send the PASS command!");
    close(sockfd);
    return -1;
  }

  // Receive the response from the server.
  n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (n == -1) {
    perror("OMG! I can't receive the response to the PASS command!");
    close(sockfd);
    return -1;
  }

  printf("%s", buf);

  // Send the LIST command to the server.
  sprintf(buf, "LIST\r\n");
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("OMG! I can't send the LIST command!");
    close(sockfd);
    return -1;
  }

  // Receive the response from the server.
  n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (n == -1) {
    perror("OMG! I can't receive the response to the LIST command!");
    close(sockfd);
    return -1;
  }

  printf("%s", buf);

  // Send the RETR command to the server.
  int msg_num;
  printf("Which message do you want to retrieve, dude? ");
  scanf("%d", &msg_num);
  sprintf(buf, "RETR %d\r\n", msg_num);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("OMG! I can't send the RETR command!");
    close(sockfd);
    return -1;
  }

  // Receive the response from the server.
  n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (n == -1) {
    perror("OMG! I can't receive the response to the RETR command!");
    close(sockfd);
    return -1;
  }

  printf("%s", buf);

  // Send the QUIT command to the server.
  sprintf(buf, "QUIT\r\n");
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("OMG! I can't send the QUIT command!");
    close(sockfd);
    return -1;
  }

  // Receive the response from the server.
  n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (n == -1) {
    perror("OMG! I can't receive the response to the QUIT command!");
    close(sockfd);
    return -1;
  }

  printf("%s", buf);

  // Close the socket.
  close(sockfd);

  // Say goodbye to the user.
  printf("OMG! That's all, folks! Thanks for using the POP3 Client!");

  return 0;
}