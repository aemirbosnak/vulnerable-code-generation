//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

int main(int argc, char *argv[]) {
  int sock;
  struct sockaddr_in server_addr;
  char buffer[BUFFER_SIZE];

  if (argc!= 2) {
    printf("Usage: %s <server_ip>\n", argv[0]);
    return 1;
  }

  strcpy(SERVER_IP, argv[1]);

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Error creating socket\n");
    return 1;
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    printf("Error connecting to server\n");
    close(sock);
    return 1;
  }

  send(sock, "GET / HTTP/1.1\r\nHost: speedtest.net\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: speedtest.net\r\n\r\n"), 0);

  while (1) {
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

    if (bytes_received <= 0) {
      break;
    }

    printf("%s", buffer);
  }

  close(sock);
  return 0;
}