#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <netdb.h>

#define MAX_THREADS 10

void *scan_port(int port) {
  int sockfd, err;
  struct sockaddr_in sock_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd < 0) {
    perror("Error opening socket");
    return NULL;
  }

  sock_addr.sin_family = AF_INET;
  sock_addr.sin_port = htons(port);
  err = connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));
  if (err < 0) {
    perror("Error connecting to port");
    close(sockfd);
    return NULL;
  }

  close(sockfd);
  return NULL;
}

int main(int argc, char *argv[]) {
  int host_port, start_port, end_port;
  char host_ip[256];
  pthread_t threads[MAX_THREADS];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host_ip> <start_port> <end_port>\n", argv[0]);
    return 1;
  }

  strcpy(host_ip, argv[1]);
  start_port = atoi(argv[2]);
  end_port = atoi(argv[3]);

  if (start_port > end_port) {
    fprintf(stderr, "Error: start port must be less than or equal to end port.\n");
    return 1;
  }

  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, scan_port, (void *) (start_port + i));
  }

  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
