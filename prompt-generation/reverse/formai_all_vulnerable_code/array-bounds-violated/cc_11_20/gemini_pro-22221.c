//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LENGTH 256
#define MAX_RESPONSE_LENGTH 1024

typedef struct {
    char *url;
    int port;
    int interval;
    int timeout;
    int status;
    time_t last_checked;
} website;

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <url> <port> <interval> <timeout>\n", argv[0]);
        return EXIT_FAILURE;
    }

    website w;
    w.url = argv[1];
    w.port = atoi(argv[2]);
    w.interval = atoi(argv[3]);
    w.timeout = atoi(argv[4]);
    w.status = 0;
    w.last_checked = time(NULL);

    while (1) {
        time_t now = time(NULL);

        if (now - w.last_checked >= w.interval) {
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd == -1) {
                perror("socket");
                return EXIT_FAILURE;
            }

            struct hostent *host = gethostbyname(w.url);
            if (host == NULL) {
                perror("gethostbyname");
                return EXIT_FAILURE;
            }

            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(w.port);
            addr.sin_addr = *(struct in_addr *)host->h_addr;

            if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
                perror("connect");
                w.status = 0;
            } else {
                char request[MAX_URL_LENGTH + 8];
                snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", w.url);

                if (send(sockfd, request, strlen(request), 0) == -1) {
                    perror("send");
                    w.status = 0;
                } else {
                    char response[MAX_RESPONSE_LENGTH];
                    int n = recv(sockfd, response, sizeof(response), 0);
                    if (n == -1) {
                        perror("recv");
                        w.status = 0;
                    } else {
                        response[n] = '\0';
                        if (strstr(response, "200 OK") != NULL) {
                            w.status = 1;
                        } else {
                            w.status = 0;
                        }
                    }
                }
            }

            close(sockfd);

            w.last_checked = now;
        }

        printf("%s: %s\n", w.url, w.status ? "up" : "down");

        sleep(1);
    }

    return EXIT_SUCCESS;
}