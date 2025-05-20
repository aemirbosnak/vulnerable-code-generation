//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    return 1;
  }

  // Resolve the hostname
  struct hostent *hostent = gethostbyname(argv[1]);
  if (hostent == NULL) {
    printf("Error: Could not resolve hostname %s\n", argv[1]);
    return 1;
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Error: Could not create socket\n");
    return 1;
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  server_addr.sin_addr = *(struct in_addr *)hostent->h_addr;
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    printf("Error: Could not connect to server\n");
    return 1;
  }

  // Send a request to the server
  char request[BUFF_SIZE];
  sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
  if (send(sockfd, request, strlen(request), 0) == -1) {
    printf("Error: Could not send request to server\n");
    return 1;
  }

  // Receive the response from the server
  char response[BUFF_SIZE];
  int bytes_received = 0;
  struct timeval start_time, end_time;
  gettimeofday(&start_time, NULL);
  while ((bytes_received = recv(sockfd, response, BUFF_SIZE, 0)) > 0) {
    gettimeofday(&end_time, NULL);
  }
  if (bytes_received == -1) {
    printf("Error: Could not receive response from server\n");
    return 1;
  }

  // Calculate the download speed
  double download_speed = (double)(bytes_received) / ((double)(end_time.tv_sec - start_time.tv_sec) + (double)(end_time.tv_usec - start_time.tv_usec) / 1000000);
  printf("Download speed: %.2f KB/s\n", download_speed);

  // Close the socket
  close(sockfd);

  return 0;
}