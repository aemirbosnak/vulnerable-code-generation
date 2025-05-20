//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/select.h>

#define MAX_FD 10

int main(int argc, char *argv[]) {

  if(argc != 3){
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    exit(0);
  }

  int sockfd, status;
  struct addrinfo hints, *res;
  fd_set fds;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((status = getaddrinfo(argv[1], argv[2], &hints, &res)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    exit(1);
  }

  if((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0){
    perror("socket");
    exit(1);
  }
  
  if(connect(sockfd, res->ai_addr, res->ai_addrlen) < 0){
    perror("connect");
    exit(1);
  }

  printf("Connected to %s on port %s\n", argv[1], argv[2]);

  while(1){

    FD_ZERO(&fds);
    FD_SET(sockfd, &fds);
    FD_SET(STDIN_FILENO, &fds);

    int ready = select(MAX_FD, &fds, NULL, NULL, NULL);

    if(ready < 0){
      perror("select");
      exit(1);
    }

    if(FD_ISSET(sockfd, &fds)){

      char buffer[1024];
      int bytes = recv(sockfd, buffer, sizeof(buffer)-1, 0);

      if(bytes < 0){
        perror("recv");
        exit(1);
      }

      if(bytes == 0){
        printf("Connection closed by server\n");
        break;
      }

      buffer[bytes] = '\0';
      printf("Server: %s\n", buffer);
    }

    if(FD_ISSET(STDIN_FILENO, &fds)){

      char buffer[1024];
      scanf("%s", buffer);
      send(sockfd, buffer, strlen(buffer), 0);
    }
  }

  close(sockfd);

  return 0;
}