//Code Llama-13B DATASET v1.0 Category: Website Uptime Monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_URL_LEN 1024
#define MAX_LINE_LEN 1024

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <URL>\n", argv[0]);
    return 1;
  }

  char *url = argv[1];
  int sock;
  char recv_buf[MAX_LINE_LEN];
  struct sockaddr_in server_addr;

  // Create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    return 1;
  }

  // Setup server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  if (inet_pton(AF_INET, url, &server_addr.sin_addr) <= 0) {
    perror("inet_pton() failed");
    return 1;
  }

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect() failed");
    return 1;
  }

  // Send request to server
  char request[MAX_LINE_LEN] = "GET / HTTP/1.1\r\nHost: ";
  strcat(request, url);
  strcat(request, "\r\n\r\n");
  if (write(sock, request, strlen(request)) < 0) {
    perror("write() failed");
    return 1;
  }

  // Receive response from server
  int bytes_recv = read(sock, recv_buf, MAX_LINE_LEN);
  if (bytes_recv < 0) {
    perror("read() failed");
    return 1;
  }
  recv_buf[bytes_recv] = '\0';

  // Check for HTTP response code
  char *ptr = strstr(recv_buf, "HTTP/1.1");
  if (ptr == NULL) {
    printf("Invalid response from server\n");
    return 1;
  }
  ptr += 9; // Skip "HTTP/1.1 "
  int code = atoi(ptr);
  if (code < 200 || code > 299) {
    printf("Website is down (HTTP response code %d)\n", code);
    return 1;
  }

  printf("Website is up (HTTP response code %d)\n", code);
  return 0;
}