//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 80
#define TIMEOUT 10
#define MAX_RESPONSE_LENGTH 4096

int main(int argc, char *argv[]) {
  if(argc < 2) {
    printf("Usage: %s <URL>\n", argv[0]);
    return 1;
  }

  char *url = argv[1];
  char *hostname = url;

  // Parse hostname from URL
  if (strstr(url, "http://") != NULL) {
    hostname = url + 7;
  }
  else if (strstr(url, "https://") != NULL) {
    hostname = url + 8;
  }
  
  // Remove any path from hostname
  char *path = strchr(hostname, '/');
  if(path != NULL) {
    *path = '\0';
  }

  // Get IP address of hostname
  struct hostent *he = gethostbyname(hostname);
  if(he == NULL) {
    printf("Error: Cannot resolve hostname %s\n", hostname);
    return 1;
  }

  struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;

  // Create socket
  int sockfd;
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("Error: Cannot create socket\n");
    return 1;
  }

  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  serv_addr.sin_addr = *addr_list[0];

  // Connect to server
  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error: Cannot connect to server %s\n", hostname);
    return 1;
  }

  // Send HTTP request
  char request[256];
  snprintf(request, 256, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path != NULL ? path + 1 : "", hostname);

  if(send(sockfd, request, strlen(request), 0) < 0) {
    printf("Error: Cannot send HTTP request\n");
    return 1;
  }

  // Receive HTTP response
  char response[MAX_RESPONSE_LENGTH];
  int n = 0;
  int total_bytes_received = 0;

  while(total_bytes_received < MAX_RESPONSE_LENGTH && n != -1) {
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(sockfd, &fds);

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    int ready_fds = select(sockfd + 1, &fds, NULL, NULL, &timeout);

    if(ready_fds == -1) {
      printf("Error: Cannot receive HTTP response\n");
      return 1;
    }
    else if(ready_fds == 0) {
      printf("Error: Timeout while receiving HTTP response\n");
      return 1;
    }

    n = recv(sockfd, response + total_bytes_received, MAX_RESPONSE_LENGTH - total_bytes_received, 0);
    total_bytes_received += n;
  }

  // Close socket
  close(sockfd);

  // Check HTTP response
  if(total_bytes_received == 0) {
    printf("Error: Empty HTTP response\n");
    return 1;
  }
  else if(strncmp(response, "HTTP/1.", 7) != 0) {
    printf("Error: Invalid HTTP response\n");
    return 1;
  }
  else if(response[9] != '2') {
    printf("Error: HTTP error %s\n", response + 9);
    return 1;
  }

  printf("Website is up!\n");

  return 0;
}