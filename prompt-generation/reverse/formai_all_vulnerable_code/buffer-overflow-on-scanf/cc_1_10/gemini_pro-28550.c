//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in servaddr;

  if (argc != 3) {
    printf("Usage: %s <server IP address> <server port>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(1);
  }

  char buf[MAX_LINE];
  while (1) {
    memset(buf, 0, MAX_LINE);
    printf("Enter a message to send to the server: ");
    scanf("%s", buf);

    if (strcmp(buf, "exit") == 0) {
      break;
    }

    if (write(sockfd, buf, strlen(buf)) < 0) {
      perror("write");
      exit(1);
    }

    memset(buf, 0, MAX_LINE);
    if (read(sockfd, buf, MAX_LINE) < 0) {
      perror("read");
      exit(1);
    }

    printf("Message received from the server: %s\n", buf);
  }

  close(sockfd);
  return 0;
}