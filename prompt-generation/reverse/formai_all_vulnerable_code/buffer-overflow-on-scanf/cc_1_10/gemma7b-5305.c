//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PORTS 65535

int main() {

  int sockfd, port, n, err, host_port;
  char hostname[256];
  struct sockaddr_in sock_addr;

  printf("Enter hostname: ");
  scanf("%s", hostname);

  printf("Enter host port: ");
  scanf("%d", &host_port);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(2));
  if (sockfd < 0) {
    perror("Socket creation error");
    return 1;
  }

  sock_addr.sin_family = AF_INET;
  sock_addr.sin_port = htons(host_port);
  inet_aton(hostname, &sock_addr.sin_addr);

  n = connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));
  if (n < 0) {
    perror("Connection error");
    return 1;
  }

  printf("Enter port number: ");
  scanf("%d", &port);

  err = send(sockfd, &port, sizeof(port), 0);
  if (err < 0) {
    perror("Send error");
    return 1;
  }

  n = recv(sockfd, &err, sizeof(err), 0);
  if (n < 0) {
    perror("Receive error");
    return 1;
  }

  printf("Port status: ");
  if (err == 1) {
    printf("Open\n");
  } else if (err == 0) {
    printf("Closed\n");
  } else {
    printf("Error\n");
  }

  close(sockfd);

  return 0;
}