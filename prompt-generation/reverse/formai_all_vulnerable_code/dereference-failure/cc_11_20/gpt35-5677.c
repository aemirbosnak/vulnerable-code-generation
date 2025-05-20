//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
    exit(1);
  }

  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[BUFFER_SIZE];
  char *username = "<your-username>";
  char *password = "<your-password>";
  char *email_folder = "INBOX";
  char *email_status = "UNSEEN"; 

  portno = atoi(argv[2]);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd,(const struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  n = read(sockfd, buffer, BUFFER_SIZE - 1);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("%s\n", buffer);

  // log in to the email server
  sprintf(buffer, "1 LOGIN %s %s\r\n", username, password);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }
  n = read(sockfd, buffer, BUFFER_SIZE - 1);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("%s\n", buffer);

  // select the email folder
  sprintf(buffer, "2 SELECT %s\r\n", email_folder);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }
  n = read(sockfd, buffer, BUFFER_SIZE - 1);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("%s\n", buffer);

  // get all unseen messages
  sprintf(buffer, "3 SEARCH %s\r\n", email_status);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }
  n = read(sockfd, buffer, BUFFER_SIZE - 1);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("%s\n", buffer);

  // log out from the email server
  sprintf(buffer, "4 LOGOUT\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }
  close(sockfd);
  return 0;
}