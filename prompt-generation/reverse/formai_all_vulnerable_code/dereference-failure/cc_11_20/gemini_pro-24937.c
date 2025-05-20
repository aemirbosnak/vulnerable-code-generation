//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

int main(int argc, char **argv) {

  if(argc < 4) {
    printf("Usage: %s hostname port username password\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Look up the hostname
  struct hostent *host = gethostbyname(argv[1]);
  if(host == NULL) {
    fprintf(stderr, "Error: Could not resolve hostname: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // Create the socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    fprintf(stderr, "Error: Could not create socket: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[2]));
  memcpy(&serv_addr.sin_addr, host->h_addr_list[0], host->h_length);
  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: Could not connect to server: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Send the USER command
  char buf[BUFSIZ];
  snprintf(buf, sizeof(buf), "USER %s\r\n", argv[3]);
  if(send(sockfd, buf, strlen(buf), 0) < 0) {
    fprintf(stderr, "Error: Could not send USER command: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Receive the USER response
  if(recv(sockfd, buf, sizeof(buf), 0) < 0) {
    fprintf(stderr, "Error: Could not receive USER response: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Send the PASS command
  snprintf(buf, sizeof(buf), "PASS %s\r\n", argv[4]);
  if(send(sockfd, buf, strlen(buf), 0) < 0) {
    fprintf(stderr, "Error: Could not send PASS command: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Receive the PASS response
  if(recv(sockfd, buf, sizeof(buf), 0) < 0) {
    fprintf(stderr, "Error: Could not receive PASS response: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Send the LIST command
  if(send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0) < 0) {
    fprintf(stderr, "Error: Could not send LIST command: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Receive the LIST response
  while(1) {
    if(recv(sockfd, buf, sizeof(buf), 0) < 0) {
      fprintf(stderr, "Error: Could not receive LIST response: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }

    if(strcmp(buf, ".\r\n") == 0) {
      break;
    }

    printf("%s", buf);
  }

  // Send the QUIT command
  if(send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
    fprintf(stderr, "Error: Could not send QUIT command: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Close the socket
  close(sockfd);

  exit(EXIT_SUCCESS);
}