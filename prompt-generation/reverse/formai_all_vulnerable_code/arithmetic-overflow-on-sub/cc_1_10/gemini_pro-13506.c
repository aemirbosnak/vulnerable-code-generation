//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s <server_ip>\n", argv[0]);
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
    printf("Error: Invalid IP address\n");
    return 1;
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    printf("Error: Failed to create socket\n");
    return 1;
  }

  if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    printf("Error: Failed to connect to server\n");
    return 1;
  }

  char request[] = "GET / HTTP/1.1\r\nHost: "
                  "" /* Server IP here */
                  "\r\nConnection: close\r\n\r\n";
  if (send(sock, request, strlen(request), 0) < 0) {
    printf("Error: Failed to send request\n");
    return 1;
  }

  clock_t start = clock();
  char buf[BUFF_SIZE];
  int bytes_received = 0;
  while ((bytes_received = recv(sock, buf, BUFF_SIZE, 0)) > 0) {
  }

  clock_t end = clock();

  if (bytes_received < 0) {
    printf("Error: Failed to receive response\n");
    return 1;
  }

  double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
  double speed = (double)bytes_received / time_elapsed / 1024 / 1024;
  printf("Speed: %.2f Mbps\n", speed);

  close(sock);
  return 0;
}