//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

/* A surrealistic IMAP Client program */

int main(int argc, char *argv[]) {

  int sockfd, numbytes;
  char buf[1024];
  char username[50];
  char password[50];

  struct addrinfo hints, *servinfo, *p;

  printf("Hey there! Welcome to the surreal World of IMAP Client\n");
  printf("Please enter your username: ");
  scanf("%s", username);

  printf("Please enter your password: ");
  scanf("%s", password);

  printf("Connecting to the surreal IMAP server...\n");

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  /* Get the server details */
  if ((getaddrinfo("imap.surrealworld.com", "143", &hints, &servinfo)) != 0) {
      fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
      return 1;
  }

  /* Connect to the server */
  for(p = servinfo; p != NULL; p = p->ai_next) {
      if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
          fprintf(stderr, "socket: %s\n", strerror(errno));
          continue;
      }

      if (connect(sockfd, p->ai_addr, p->ai_addrlen) < 0) {
          close(sockfd);
          fprintf(stderr, "connect: %s\n", strerror(errno));
          continue;
      }

      break;
  }

  if (p == NULL) {
      fprintf(stderr, "Failed to connect\n");
      return 2;
  }

  freeaddrinfo(servinfo);

  /* Send the Login Command */
  printf("Connected to the surreal IMAP server!\n");
  printf("Sending Login Command...\n");
  sprintf(buf, "LOGIN \"%s\" \"%s\"\r\n", username, password);

  if ((send(sockfd, buf, strlen(buf), 0)) < 0) {
      fprintf(stderr, "send: %s\n", strerror(errno));
      return 3;    
  }

  /* Receive the response from the server */
  if ((numbytes = recv(sockfd, buf, sizeof buf, 0)) < 0) {
      fprintf(stderr, "recv: %s\n", strerror(errno));
      return 4;  
  }

  buf[numbytes] = '\0';

  printf("Server Response: %s", buf);

  /* Send the Select Command */
  printf("Sending Select Command...\n");

  if ((send(sockfd, "SELECT INBOX\r\n", strlen("SELECT INBOX\r\n"), 0)) < 0) {
      fprintf(stderr, "send: %s\n", strerror(errno));
      return 5;
  }

  /* Receive the response from the server */
  if ((numbytes = recv(sockfd, buf, sizeof buf, 0)) < 0) {
      fprintf(stderr, "recv: %s\n", strerror(errno));
      return 6;  
  }

  buf[numbytes] = '\0';

  printf("Server Response: %s", buf);

  /* Send the List Command */
  printf("Sending List Command...\n");

  if ((send(sockfd, "LIST \"\" *\r\n", strlen("LIST \"\" *\r\n"), 0)) < 0) {
      fprintf(stderr, "send: %s\n", strerror(errno));
      return 7;
  }

  /* Receive the response from the server */
  if ((numbytes = recv(sockfd, buf, sizeof buf, 0)) < 0) {
      fprintf(stderr, "recv: %s\n", strerror(errno));
      return 8;  
  }

  buf[numbytes] = '\0';

  printf("Server Response: %s", buf);

  /* Send the Logout Command */
  printf("Logging out of the surreal IMAP server...\n");

  if ((send(sockfd, "LOGOUT\r\n", strlen("LOGOUT\r\n"), 0)) < 0) {
      fprintf(stderr, "send: %s\n", strerror(errno));
      return 9;
  }

  close(sockfd);

  printf("Disconnected from the surreal IMAP server.\n");

  return 0;
}