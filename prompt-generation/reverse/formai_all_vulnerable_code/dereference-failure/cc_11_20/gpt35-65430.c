//FormAI DATASET v1.0 Category: Networking ; Style: intelligent
// A networking program to retrieve the current weather using OpenWeatherMap API

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096
#define WEATHER_API_KEY "YOUR_OPENWEATHERMAP_API_KEY_HERE"
#define WEATHER_API_URL "http://api.openweathermap.org/data/2.5/weather?q=%s&appid=%s"

int main(int argc, char* argv[]) {
  if(argc != 2) {
    printf("Usage: %s CITY_NAME\n", argv[0]);
    return 0;
  }

  char* city_name = argv[1];
  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int sfd, s, flags;
  ssize_t nread;
  size_t total_bytes = 0;
  char buffer[MAX_BUFFER_SIZE];
  char query_string[MAX_BUFFER_SIZE];
  char* body_start;
  char* response_status;
  char* response_status_start = buffer;
  char* content_length_start;
  char* content_length_end;
  char* content_start;
  char* content_end;
  int content_length;

  snprintf(query_string, MAX_BUFFER_SIZE, WEATHER_API_URL, city_name, WEATHER_API_KEY);

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;

  s = getaddrinfo("api.openweathermap.org", "http", &hints, &result);
  if (s != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
    exit(EXIT_FAILURE);
  }

  for (rp = result; rp != NULL; rp = rp->ai_next) {
    sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sfd == -1) continue;

    if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1) break; /* Success */

    close(sfd);
  }

  if (rp == NULL) {
    fprintf(stderr, "Could not connect\n");
    exit(EXIT_FAILURE);
  }

  freeaddrinfo(result);

  // Non-blocking I/O
  flags = fcntl(sfd, F_GETFL, 0);
  fcntl(sfd, F_SETFL, flags | O_NONBLOCK);

  memset(buffer, 0, MAX_BUFFER_SIZE);
  snprintf(buffer, MAX_BUFFER_SIZE, "GET %s HTTP/1.1\r\n", query_string);
  snprintf(buffer + strlen(buffer), MAX_BUFFER_SIZE - strlen(buffer), "Host: api.openweathermap.org\r\n");
  snprintf(buffer + strlen(buffer), MAX_BUFFER_SIZE - strlen(buffer), "Connection: close\r\n");
  snprintf(buffer + strlen(buffer), MAX_BUFFER_SIZE - strlen(buffer), "\r\n");

  send(sfd, buffer, strlen(buffer), 0);

  // Wait for the server's response
  while((nread = recv(sfd, buffer + total_bytes, MAX_BUFFER_SIZE - total_bytes, 0)) > 0) {
    total_bytes += nread;
    if(total_bytes >= MAX_BUFFER_SIZE) break;
  }

  // Check if there's any response
  if(total_bytes <= 0) return -1;

  response_status = strstr(response_status_start, "HTTP/1.1 ");
  if(!response_status) return -1;

  // Get the HTTP response status code
  response_status += strlen("HTTP/1.1 ");
  if(!isdigit(*response_status)) return -1;

  int response_code = strtol(response_status, &response_status, 10);
  if(response_code != 200) return -1;

  content_length_start = strstr(buffer, "Content-Length: ");
  if(!content_length_start) return -1;

  content_length_start += strlen("Content-Length: ");
  content_length_end = strchr(content_length_start, '\r');
  if(!content_length_end) return -1;

  content_length = strtol(content_length_start, &content_length_end, 10);
  if(content_length <= 0 || content_length > MAX_BUFFER_SIZE) return -1;

  // Get the start and end of the response content
  body_start = strstr(buffer, "\r\n\r\n");
  if(!body_start) return -1;

  body_start += 4;

  content_start = body_start;
  content_end = content_start + content_length;

  printf("%.*s\n", (int)(content_end - content_start), content_start);

  close(sfd);

  return 0;
}