//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define FTP_PORT 21

int main() {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];

  printf("Enter the IP address of the FTP server: ");
  scanf("%s", buffer);
  server = gethostbyname(buffer);
  if (server == NULL) {
    fprintf(stderr, "Error: could not get host by name\n");
    exit(1);
  }

  portno = FTP_PORT;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error: could not open socket\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: could not connect to server\n");
    exit(1);
  }

  printf("Connected to FTP server.\n");

  while (1) {
    printf("Enter a command (USER, PASS, QUIT, or LS): ");
    scanf("%s", buffer);

    if (strcmp(buffer, "QUIT") == 0) {
      break;
    } else if (strcmp(buffer, "USER") == 0) {
      printf("Enter username: ");
      scanf("%s", buffer);
      sprintf(buffer, "USER %s\r\n", buffer);
      n = write(sockfd, buffer, strlen(buffer));
      if (n < 0) {
        fprintf(stderr, "Error: could not send username\n");
        exit(1);
      }
    } else if (strcmp(buffer, "PASS") == 0) {
      printf("Enter password: ");
      scanf("%s", buffer);
      sprintf(buffer, "PASS %s\r\n", buffer);
      n = write(sockfd, buffer, strlen(buffer));
      if (n < 0) {
        fprintf(stderr, "Error: could not send password\n");
        exit(1);
      }
    } else if (strcmp(buffer, "LS") == 0) {
      sprintf(buffer, "LS\r\n");
      n = write(sockfd, buffer, strlen(buffer));
      if (n < 0) {
        fprintf(stderr, "Error: could not send LS command\n");
        exit(1);
      }
      while (1) {
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
          fprintf(stderr, "Error: could not read response from server\n");
          exit(1);
        } else if (n == 0) {
          break;
        } else {
          printf("%s", buffer);
        }
      }
    } else {
      printf("Invalid command.\n");
    }
  }

  close(sockfd);

  return 0;
}