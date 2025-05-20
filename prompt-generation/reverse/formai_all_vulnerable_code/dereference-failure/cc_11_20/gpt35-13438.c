//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 143 //IMAP port number
#define BUF_SIZE 1024 //buffer size

int main() {
  char buffer[BUF_SIZE];
  int sockfd, bytes, sent, received, total;

  struct sockaddr_in server_addr;
  struct hostent *host;

  host = gethostbyname("imap.gmail.com"); //IMAP server address
  if (host == NULL) {
    perror("Error retrieving host address");
    exit(1);
  }

  //create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  //set server address
  bzero((char *)&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);

  //connect to server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  //receive server welcome message
  received = 0;
  total = 0;
  bzero(buffer, BUF_SIZE);
  do {
    bytes = recv(sockfd, buffer + total, BUF_SIZE - total, 0);
    if (bytes < 0) {
      perror("Error receiving server message");
      exit(1);
    }
    if (bytes == 0) {
      break;
    }
    total += bytes;
  } while (strstr(buffer, " OK ") == NULL);
  printf("%s", buffer);

  //send login command
  bzero(buffer, BUF_SIZE);
  sent = sprintf(buffer, "a LOGIN username password\r\n");
  if (send(sockfd, buffer, sent, 0) < 0) {
    perror("Error sending login command");
    exit(1);
  }

  //receive login response
  received = 0;
  total = 0;
  bzero(buffer, BUF_SIZE);
  do {
    bytes = recv(sockfd, buffer + total, BUF_SIZE - total, 0);
    if (bytes < 0) {
      perror("Error receiving login response");
      exit(1);
    }
    if (bytes == 0) {
      break;
    }
    total += bytes;
  } while (strstr(buffer, " OK ") == NULL);
  printf("%s", buffer);

  //send select command
  bzero(buffer, BUF_SIZE);
  sent = sprintf(buffer, "b SELECT Inbox\r\n");
  if (send(sockfd, buffer, sent, 0) < 0) {
    perror("Error sending select command");
    exit(1);
  }

  //receive select response
  received = 0;
  total = 0;
  bzero(buffer, BUF_SIZE);
  do {
    bytes = recv(sockfd, buffer + total, BUF_SIZE - total, 0);
    if (bytes < 0) {
      perror("Error receiving select response");
      exit(1);
    }
    if (bytes == 0) {
      break;
    }
    total += bytes;
  } while (strstr(buffer, " EXISTS ") == NULL);
  printf("%s", buffer);

  //send fetch command
  bzero(buffer, BUF_SIZE);
  sent = sprintf(buffer, "c FETCH 1 FULL\r\n");
  if (send(sockfd, buffer, sent, 0) < 0) {
    perror("Error sending fetch command");
    exit(1);
  }

  //receive fetch response
  received = 0;
  total = 0;
  bzero(buffer, BUF_SIZE);
  do {
    bytes = recv(sockfd, buffer + total, BUF_SIZE - total, 0);
    if (bytes < 0) {
      perror("Error receiving fetch response");
      exit(1);
    }
    if (bytes == 0) {
      break;
    }
    total += bytes;
  } while (strstr(buffer, " OK ") == NULL);
  printf("%s", buffer);

  close(sockfd); //close connection

  printf("IMAP client executed successfully!");

  return 0;
}