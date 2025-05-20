#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <netdb.h>

#define MAX_HOSTS 1000
#define MAX_THREADS 50

void *scan_host(void *arg) {
  int host_num = (int)arg;
  FILE *fp = fopen("hosts.txt", "r");
  char hostname[256];
  int port;
  fscanf(fp, "%s %d", hostname, &port);
  fclose(fp);

  int sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr.s_addr = inet_addr(hostname);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
    printf("Host %s is up.\n", hostname);
  } else {
    printf("Host %s is down.\n", hostname);
  }

  close(sockfd);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[MAX_THREADS];
  int i;

  FILE *fp = fopen("hosts.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  char hostname[256];
  int port;
  fscanf(fp, "%s %d", hostname, &port);

  fclose(fp);

  for (i = 0; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, scan_host, (void *)i);
  }

  for (i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
