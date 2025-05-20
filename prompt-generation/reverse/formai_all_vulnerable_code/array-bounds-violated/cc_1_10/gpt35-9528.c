//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  // Create socket
  int sock;
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
      perror("socket creation failed");
      exit(EXIT_FAILURE);
  }

  // Set up server address
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr("192.168.1.1"); // Change to your router IP address
  server_addr.sin_port = htons(80); // Most router administration pages use port 80

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("connection to server failed");
      exit(EXIT_FAILURE);
  }

  // Send request for Wi-Fi signal strength
  char request[BUFFER_SIZE];
  sprintf(request, "GET /cgi-bin/luci/admin/status/wireless?get=1 HTTP/1.1\r\n");
  strcat(request, "Host: 192.168.1.1\r\n\r\n");

  if (send(sock, request, strlen(request), 0) < 0) {
      perror("request sending failed");
      exit(EXIT_FAILURE);
  }

  // Receive response from server
  char response[BUFFER_SIZE];
  int received_bytes = recv(sock, response, BUFFER_SIZE - 1, 0);
  response[received_bytes] = '\0';

  // Extract signal strength from response
  char *signal_string = strstr(response, "signal");
  if (signal_string == NULL) {
      printf("Unable to find signal strength in response\n");
      exit(EXIT_FAILURE);
  }

  int signal_strength = atoi(signal_string + 7); // Skip "signal:" and convert to integer

  printf("Wi-Fi signal strength is: %d dBm\n", signal_strength);

  close(sock);
  return EXIT_SUCCESS;
}