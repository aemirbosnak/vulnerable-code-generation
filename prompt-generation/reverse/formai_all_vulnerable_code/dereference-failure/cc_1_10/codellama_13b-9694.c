//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: dynamic
// ping_test.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PING_HOST "www.example.com"
#define PING_TIMEOUT 5

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in servaddr;
  struct hostent *host;
  char *hostname = argv[1];
  char send_buf[1024];
  char recv_buf[1024];
  int n;
  int i;

  if ((host = gethostbyname(hostname)) == NULL) {
    fprintf(stderr, "ERROR: Could not resolve hostname %s\n", hostname);
    return 1;
  }

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    fprintf(stderr, "ERROR: Could not create socket\n");
    return 1;
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(80);
  memcpy(&servaddr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    fprintf(stderr, "ERROR: Could not connect to %s\n", hostname);
    return 1;
  }

  // Send a request to the server
  sprintf(send_buf, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);
  if (send(sockfd, send_buf, strlen(send_buf), 0) < 0) {
    fprintf(stderr, "ERROR: Could not send request to server\n");
    return 1;
  }

  // Receive the response from the server
  n = recv(sockfd, recv_buf, sizeof(recv_buf), 0);
  if (n < 0) {
    fprintf(stderr, "ERROR: Could not receive response from server\n");
    return 1;
  }

  // Print the response from the server
  printf("Response from server:\n%s\n", recv_buf);

  return 0;
}