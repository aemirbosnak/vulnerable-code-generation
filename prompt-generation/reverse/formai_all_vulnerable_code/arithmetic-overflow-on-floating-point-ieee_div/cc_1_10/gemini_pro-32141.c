//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <time.h>

#define SERVER_IP "8.8.8.8"
#define SERVER_PORT 53

int main() {
  int sock;
  struct sockaddr_in server_addr;
  char data[1024];
  int data_len = sizeof(data);
  int bytes_received;
  int bytes_sent;
  clock_t start, end;
  double elapsed_time;
  double speed;

  if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket");
    return -1;
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

  start = clock();

  for (int i = 0; i < 10; i++) {
    bytes_sent = sendto(sock, data, data_len, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bytes_sent < 0) {
      perror("sendto");
      return -1;
    }

    bytes_received = recvfrom(sock, data, data_len, 0, NULL, NULL);
    if (bytes_received < 0) {
      perror("recvfrom");
      return -1;
    }
  }

  end = clock();

  elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
  speed = (double)bytes_received * 8 / elapsed_time;

  printf("Speed: %.2f Mbps\n", speed);

  close(sock);
  return 0;
}