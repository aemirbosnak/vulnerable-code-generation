//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_URL_LENGTH 256

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <url> <interval>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *url = argv[1];
  int interval = atoi(argv[2]);

  if (interval < 1) {
    fprintf(stderr, "Error: interval must be greater than 0\n");
    return EXIT_FAILURE;
  }

  while (1) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    time_t now = ts.tv_sec;

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *result;
    int status = getaddrinfo(url, "http", &hints, &result);
    if (status != 0) {
      fprintf(stderr, "Error: getaddrinfo() failed: %s\n", gai_strerror(status));
      return EXIT_FAILURE;
    }

    struct addrinfo *rp;
    for (rp = result; rp != NULL; rp = rp->ai_next) {
      int sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
      if (sockfd == -1) {
        fprintf(stderr, "Error: socket() failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
      }

      status = connect(sockfd, rp->ai_addr, rp->ai_addrlen);
      if (status == -1) {
        fprintf(stderr, "Error: connect() failed: %s\n", strerror(errno));
        close(sockfd);
        continue;
      }

      char request[] = "HEAD / HTTP/1.1\r\nHost: ";
      strncat(request, url, sizeof(request) - strlen(request) - 1);
      strncat(request, "\r\n\r\n", sizeof(request) - strlen(request) - 1);

      status = send(sockfd, request, strlen(request), 0);
      if (status == -1) {
        fprintf(stderr, "Error: send() failed: %s\n", strerror(errno));
        close(sockfd);
        continue;
      }

      char response[MAX_URL_LENGTH];
      status = recv(sockfd, response, sizeof(response) - 1, 0);
      if (status == -1) {
        fprintf(stderr, "Error: recv() failed: %s\n", strerror(errno));
        close(sockfd);
        continue;
      }

      close(sockfd);

      if (strstr(response, "200 OK") != NULL) {
        printf("Up: %s\n", url);
      } else {
        printf("Down: %s\n", url);
      }
    }

    freeaddrinfo(result);

    sleep(interval);
  }

  return EXIT_SUCCESS;
}