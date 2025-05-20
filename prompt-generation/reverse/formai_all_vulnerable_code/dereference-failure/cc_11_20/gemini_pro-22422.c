//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];
  
  if (argc < 3) {
    printf("HTTP Client - Usage: %s hostname port\n", argv[0]);
    return 1;
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    printf("HTTP Client - Error: no such host\n");
    return 2;
  }

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("HTTP Client - Error: cannot create socket\n");
    return 3;
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
    printf("HTTP Client - Error: cannot connect to host\n");
    return 4;
  }

  printf("HTTP Client - Connected to %s on port %d\n", argv[1], portno);
  
  while (1) {
    printf("HTTP Client - Enter command (GET, POST, QUIT): ");
    scanf("%s", buffer);
    if (strcmp(buffer, "GET") == 0) {
      printf("HTTP Client - Enter URL: ");
      scanf("%s", buffer);
      snprintf(buffer, sizeof(buffer), "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", buffer, argv[1]);
      n = write(sockfd, buffer, strlen(buffer));
      if (n < 0) {
        printf("HTTP Client - Error: cannot write to socket\n");
      }
      bzero(buffer, sizeof(buffer));
      while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        printf("%s", buffer);
      }
      printf("\n");
    } else if (strcmp(buffer, "POST") == 0) {
      printf("HTTP Client - Enter URL: ");
      scanf("%s", buffer);
      printf("HTTP Client - Enter data: ");
      scanf("%s", buffer);
      snprintf(buffer, sizeof(buffer), "POST %s HTTP/1.1\r\nHost: %s\r\nContent-Length: %d\r\n\r\n%s", buffer, argv[1], strlen(buffer), buffer);
      n = write(sockfd, buffer, strlen(buffer));
      if (n < 0) {
        printf("HTTP Client - Error: cannot write to socket\n");
      }
      bzero(buffer, sizeof(buffer));
      while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        printf("%s", buffer);
      }
      printf("\n");
    } else if (strcmp(buffer, "QUIT") == 0) {
      printf("HTTP Client - Exiting\n");
      break;
    } else {
      printf("HTTP Client - Invalid command\n");
    }
  }
  
  close(sockfd);
  return 0;
}