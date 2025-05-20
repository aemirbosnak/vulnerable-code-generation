//MISTRAL-7B DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PORT 8080
#define MAXLINE 1024

int main(int argc, char const *argv[]) {
  int sockfd;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  server = gethostbyname("email-server.post-apocalypse.net");
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
       (char *)&serv_addr.sin_addr.s_addr,
       server->h_length);
  serv_addr.sin_port = htons(PORT);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  char buffer[MAXLINE];
  int n;
  char to[MAXLINE], subject[MAXLINE], message[MAXLINE];

  printf("Enter recipient email address: ");
  bzero(to, MAXLINE);
  fgets(to, MAXLINE, stdin);
  to[strlen(to) - 1] = '\0';

  printf("Enter email subject: ");
  bzero(subject, MAXLINE);
  fgets(subject, MAXLINE, stdin);
  subject[strlen(subject) - 1] = '\0';

  printf("Enter email message: ");
  bzero(message, MAXLINE);
  fgets(message, MAXLINE, stdin);
  message[strlen(message) - 1] = '\0';

  sprintf(buffer, "TO: %s\r\n", to);
  write(sockfd, buffer, strlen(buffer));

  sprintf(buffer, "SUBJECT: %s\r\n", subject);
  write(sockfd, buffer, strlen(buffer));

  sprintf(buffer, "MESSAGE:\r\n%s\r\n.", message);
  write(sockfd, buffer, strlen(buffer));

  n = read(sockfd, buffer, MAXLINE);
  printf("Server response: %s\n", buffer);

  close(sockfd);
  return 0;
}