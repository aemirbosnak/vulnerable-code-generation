#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>
#include <netdb.h>
#include <unistd.h>

void *scan_host(void *arg) {
  char *hostname = (char *)arg;
  int port = 80;
  struct hostent *host = gethostbyname(hostname);
  if (host) {
    for (; port <= 1024; port++) {
      int sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
      if (sockfd) {
        char buf[1024];
        send(sockfd, "GET /", 6, 0);
        recv(sockfd, buf, 1024, 0);
        close(sockfd);
      }
    }
  }
  return NULL;
}

int main() {
  pthread_t threads[100];
  FILE *fp = fopen("hosts.txt", "r");
  char line[1024];
  while (fgets(line, 1024, fp) != NULL) {
    char *hostname = strtok(line, ":");
    pthread_create(&threads[0], NULL, scan_host, hostname);
  }
  for (int i = 0; i < 100; i++) {
    pthread_join(threads[i], NULL);
  }
  fclose(fp);
  return 0;
}
