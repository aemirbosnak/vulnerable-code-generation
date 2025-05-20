//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: accurate
// Building a FTP Client example program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in server_addr;
  char buffer[MAX_BUFFER_SIZE];
  char *server_ip = "127.0.0.1";
  int server_port = 21;

  if (argc != 3) {
    printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
    return 1;
  }

  server_ip = argv[1];
  server_port = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    return 1;
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(server_port);
  inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting");
    return 1;
  }

  while (fgets(buffer, MAX_BUFFER_SIZE, stdin) != NULL) {
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
      perror("Error sending data");
      return 1;
    }
  }

  close(sockfd);

  return 0;
}