//Code Llama-13B DATASET v1.0 Category: Website Uptime Monitor ; Style: shocked
// Website Uptime Monitor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <netdb.h>
#include <time.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <website> <interval>\n", argv[0]);
    return 1;
  }

  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char *website = argv[1];
  int interval = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error opening socket: %s\n", strerror(errno));
    return 1;
  }

  server = gethostbyname(website);
  if (server == NULL) {
    printf("Error resolving hostname: %s\n", strerror(errno));
    return 1;
  }

  portno = 80;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error connecting to server: %s\n", strerror(errno));
    return 1;
  }

  char *msg = "GET / HTTP/1.0\r\nHost: %s\r\n\r\n";
  char *buf = (char *)malloc(1024);
  int n = sprintf(buf, msg, website);

  if (write(sockfd, buf, n) < 0) {
    printf("Error sending request: %s\n", strerror(errno));
    return 1;
  }

  time_t start_time = time(NULL);
  while (1) {
    if (read(sockfd, buf, 1024) < 0) {
      printf("Error reading response: %s\n", strerror(errno));
      return 1;
    }
    if (strstr(buf, "200 OK")) {
      printf("Website is up and running\n");
      break;
    }
    sleep(interval);
    if (time(NULL) - start_time > 300) {
      printf("Website is down\n");
      break;
    }
  }

  close(sockfd);
  free(buf);
  return 0;
}