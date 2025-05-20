//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 4096
#define DEFAULT_PORT 80

struct url_parts {
  char *path;
  char *hostname;
};


/*
 * This function takes an URL string as input and separates the path and hostname.
 * It also returns a struct containing the two parts.
 */
struct url_parts parse_url(char *url)
{
  struct url_parts parts;
  char *ptr = strstr(url, "//");
  if (ptr != NULL) {
    ptr += 2;
    parts.hostname = ptr;
    char *path_ptr = strstr(ptr, "/");
    if (path_ptr != NULL) {
      *path_ptr = '\0';
      path_ptr++;
      parts.path = path_ptr;
    } else {
      parts.path = "";
    }
  } else {
    parts.hostname = url;
    parts.path = "";
  }
  return parts;
}


/*
 * This function sends an HTTP request and returns the response in a buffer.
 */
char *send_request(char *hostname, char *path)
{
  struct sockaddr_in server_addr;
  int sockfd;
  char request[MAX_REQUEST_SIZE], buffer[MAX_RESPONSE_SIZE];

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Get server IP
  struct hostent *server = gethostbyname(hostname);
  if (server == NULL) {
    perror("Error getting server IP");
    exit(1);
  }

  // Prepare server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(DEFAULT_PORT);
  memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Prepare request
  sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

  // Send request
  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("Error sending request");
    exit(1);
  }

  // Receive response
  int bytes_received = recv(sockfd, buffer, MAX_RESPONSE_SIZE - 1, 0);
  if (bytes_received < 0) {
    perror("Error receiving response");
    exit(1);
  }
  buffer[bytes_received] = '\0';

  // Clean up
  close(sockfd);

  return strdup(buffer);
}


int main(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(stderr, "Usage: %s URL\n", argv[0]);
    exit(1);
  }

  char *url = argv[1];
  struct url_parts parts = parse_url(url);

  printf("Host: %s\n", parts.hostname);
  printf("Path: %s\n", parts.path);

  char *response = send_request(parts.hostname, parts.path);
  printf("\n%s\n", response);

  return 0;
}