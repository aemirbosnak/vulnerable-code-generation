//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

void error_handling(char *message) {
  perror(message);
  exit(1);
}

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno, clilen, recv_len;
  char buffer[BUF_SIZE];
  struct sockaddr_in serv_addr, cli_addr;
  char *host_name;
  int host_len;
  int i;

  if (argc < 3) {
    printf("Usage:./client <host_name> <port_number>\n");
    exit(0);
  }

  host_name = argv[1];
  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    error_handling("socket failed");
  }

  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  host_len = strlen(host_name);
  if (host_len > 16) {
    printf("Error: hostname too long.\n");
    exit(0);
  }
  strncpy(serv_addr.sin_zero, "\0", sizeof(serv_addr.sin_zero) - host_len);
  strncat(serv_addr.sin_zero, host_name, host_len);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    error_handling("connect failed");
  }

  printf("Connected to %s:%d\n", host_name, portno);

  while (1) {
    bzero(buffer, BUF_SIZE);
    clilen = sizeof(cli_addr);
    recv_len = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&cli_addr, &clilen);
    if (recv_len > 0) {
      printf("Received %d bytes from %s:%d\n", recv_len, inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
      printf("Message: %s\n", buffer);
    } else {
      break;
    }
  }

  close(sockfd);
  return 0;
}