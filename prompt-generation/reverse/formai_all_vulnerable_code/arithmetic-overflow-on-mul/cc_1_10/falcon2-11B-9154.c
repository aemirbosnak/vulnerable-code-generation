//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: beginner-friendly
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <netdb.h>

int main() {
  struct sockaddr_in server_addr;
  struct hostent *server;
  int sockfd, bytes_sent, bytes_recv, n;
  char buffer[1024];
  struct timeval start, end;
  double ttl, dl, ul;

  // Initialize socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }

  // Connect to server
  server = gethostbyname("www.google.com");
  if (server == NULL) {
    perror("gethostbyname");
    exit(1);
  }
  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
  server_addr.sin_port = htons(80);
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Measure download and upload speeds
  gettimeofday(&start, NULL);
  bytes_sent = send(sockfd, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n", 57, 0);
  if (bytes_sent < 0) {
    perror("send");
    exit(1);
  }
  gettimeofday(&end, NULL);
  ttl = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
  dl = bytes_sent * 8 / ttl;
  gettimeofday(&start, NULL);
  bytes_sent = send(sockfd, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n", 57, 0);
  if (bytes_sent < 0) {
    perror("send");
    exit(1);
  }
  gettimeofday(&end, NULL);
  ttl = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
  ul = bytes_sent * 8 / ttl;

  // Print results
  printf("Download Speed: %.2f Mbps\n", dl / 1000000);
  printf("Upload Speed: %.2f Mbps\n", ul / 1000000);

  close(sockfd);
  return 0;
}