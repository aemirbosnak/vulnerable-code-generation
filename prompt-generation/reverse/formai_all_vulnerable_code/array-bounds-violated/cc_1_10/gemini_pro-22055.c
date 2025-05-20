//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *host = argv[1];
  int port = atoi(argv[2]);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) {
    perror("inet_pton");
    close(sockfd);
    return EXIT_FAILURE;
  }

  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    close(sockfd);
    return EXIT_FAILURE;
  }

  char *request = "GET / HTTP/1.1\r\nHost: "
                 "%s\r\n\r\n";

  char buf[4096];
  snprintf(buf, sizeof(buf), request, host);

  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  int recv_size = recv(sockfd, buf, sizeof(buf) -
                                           1, 0);

  if (recv_size < 0) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }

  buf[recv_size] = '\0';

  printf("%s", buf);

  close(sockfd);

  return EXIT_SUCCESS;
}