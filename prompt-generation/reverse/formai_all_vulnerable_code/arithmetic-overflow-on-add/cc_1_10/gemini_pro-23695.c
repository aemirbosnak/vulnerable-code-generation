//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/select.h>
#include <sys/time.h>
#include <pthread.h>

#define PORT_RANGE 65535
#define TIMEOUT 10

int sockfd;
struct sockaddr_in server_addr;

void* scan_thread(void* arg) {
  int start_port = *(int*)arg;
  int end_port = start_port + PORT_RANGE / 2;

  for (int port = start_port; port <= end_port; port++) {
    int n = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (n == 0) {
      printf("Port %d is open\n", port);
    } else {
      printf("Port %d is closed\n", port);
    }
  }

  return NULL;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <IP address>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT_RANGE);
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);

  pthread_t thread1, thread2;
  pthread_create(&thread1, NULL, scan_thread, (void*)0);
  pthread_create(&thread2, NULL, scan_thread, (void*)(PORT_RANGE / 2 + 1));

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  close(sockfd);

  return 0;
}