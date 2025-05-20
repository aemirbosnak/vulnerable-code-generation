#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PORTS 1000

pthread_t threads[MAX_PORTS];

void *scan_port(int port) {
  int sockfd, connfd, err;
  char buf[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd < 0) {
    perror("Error creating socket");
    return NULL;
  }

  connfd = connect(sockfd, NULL, 0);
  if (connfd < 0) {
    perror("Error connecting to port");
    close(sockfd);
    return NULL;
  }

  err = read(connfd, buf, 1024);
  if (err < 0) {
    perror("Error reading from port");
    close(sockfd);
    close(connfd);
    return NULL;
  }

  printf("Port %d: Server response: %s\n", port, buf);

  close(sockfd);
  close(connfd);

  return NULL;
}

int main() {
  int i, port_start, port_end;

  printf("Enter port start: ");
  scanf("%d", &port_start);

  printf("Enter port end: ");
  scanf("%d", &port_end);

  for (i = port_start; i <= port_end; i++) {
    pthread_create(&threads[i], NULL, scan_port, (void *)i);
  }

  for (i = port_start; i <= port_end; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
