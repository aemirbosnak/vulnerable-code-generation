//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define PORT 25

int check_smtp(char* hostname) {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    return -1;
  }

  server = gethostbyname(hostname);
  if (server == NULL) {
    perror("ERROR, no such host");
    return -1;
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  bcopy((char *)server->h_addr, 
        (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    return -1;
  }

  char buffer[MAX_LINE];
  n = read(sockfd, buffer, MAX_LINE-1);
  if (n < 0) {
    perror("ERROR reading from socket");
    return -1;
  }
  
  if (strncmp(buffer, "220", 3) != 0) {
    perror("ERROR: server is not an SMTP server");
    return -1;
  }

  close(sockfd);
  return 0;
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    printf("Usage: %s <smtp_server> <recipient_email>\n", argv[0]);
    return 1;
  }

  if (check_smtp(argv[1]) < 0) {
    return 1;
  }

  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    return 1;
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    perror("ERROR, no such host");
    return 1;
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  bcopy((char *)server->h_addr, 
        (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    return 1;
  }

  char buffer[MAX_LINE];
  n = read(sockfd, buffer, MAX_LINE-1);
  if (n < 0) {
    perror("ERROR reading from socket");
    return 1;
  }

  printf("%s", buffer);

  bzero(buffer, MAX_LINE);
  sprintf(buffer, "HELO %s\r\n", argv[1]);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    return 1;
  }

  n = read(sockfd, buffer, MAX_LINE-1);
  if (n < 0) {
    perror("ERROR reading from socket");
    return 1;
  }

  printf("%s", buffer);

  bzero(buffer, MAX_LINE);
  sprintf(buffer, "MAIL FROM: <%s>\r\n", argv[0]);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    return 1;
  }

  n = read(sockfd, buffer, MAX_LINE-1);
  if (n < 0) {
    perror("ERROR reading from socket");
    return 1;
  }

  printf("%s", buffer);

  bzero(buffer, MAX_LINE);
  sprintf(buffer, "RCPT TO: <%s>\r\n", argv[2]);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    return 1;
  }

  n = read(sockfd, buffer, MAX_LINE-1);
  if (n < 0) {
    perror("ERROR reading from socket");
    return 1;
  }

  printf("%s", buffer);

  bzero(buffer, MAX_LINE);
  strcpy(buffer, "DATA\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    return 1;
  }

  n = read(sockfd, buffer, MAX_LINE-1);
  if (n < 0) {
    perror("ERROR reading from socket");
    return 1;
  }

  printf("%s", buffer);

  bzero(buffer, MAX_LINE);
  strcpy(buffer, "This is a test email.\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    return 1;
  }

  bzero(buffer, MAX_LINE);
  strcpy(buffer, ".\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    return 1;
  }

  n = read(sockfd, buffer, MAX_LINE-1);
  if (n < 0) {
    perror("ERROR reading from socket");
    return 1;
  }

  printf("%s", buffer);

  bzero(buffer, MAX_LINE);
  strcpy(buffer, "QUIT\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    return 1;
  }

  n = read(sockfd, buffer, MAX_LINE-1);
  if (n < 0) {
    perror("ERROR reading from socket");
    return 1;
  }

  printf("%s", buffer);

  close(sockfd);
  return 0;
}