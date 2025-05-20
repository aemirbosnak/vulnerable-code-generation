//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PINGS 10

int main() {
  int i, j, ping_count = 0, status, host_num;
  char host_name[255];

  printf("Enter the number of hosts to ping: ");
  scanf("%d", &host_num);

  for (i = 0; i < host_num; i++) {
    printf("Enter the host name: ");
    scanf("%s", host_name);

    for (j = 0; j < MAX_PINGS; j++) {
      status = ping(host_name);
      if (status == 0) {
        printf("Host %s is alive.\n", host_name);
        ping_count++;
      } else {
        printf("Host %s is not alive.\n", host_name);
      }
    }

    printf("Number of alive hosts: %d\n", ping_count);
  }

  return 0;
}

int ping(char *host_name) {
  int sockfd, status, ping_size, bytes_sent, bytes_received;
  struct sockaddr_in serv_addr;

  sockfd = socket(AF_INET, SOCK_DGRAM, htons(5));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8080);
  inet_pton(AF_INET, host_name, &serv_addr.sin_addr);

  ping_size = write(sockfd, "PING", 5);
  bytes_received = read(sockfd, "PONG", 5);

  status = bytes_received - ping_size;
  close(sockfd);

  return status;
}