//Code Llama-13B DATASET v1.0 Category: Website Uptime Monitor ; Style: unmistakable
// Website Uptime Monitor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024
#define URL_MAX_LEN 256
#define TIMEOUT 5

typedef struct {
    char url[URL_MAX_LEN];
    int status_code;
    time_t start_time;
    time_t end_time;
} Website;

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int get_website_status(Website *website) {
    struct addrinfo hints, *server_info;
    struct sockaddr_storage server_addr;
    int sock, status;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(website->url, NULL, &hints, &server_info) != 0) {
        error("getaddrinfo() failed");
    }

    sock = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sock == -1) {
        error("socket() failed");
    }

    if (connect(sock, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        error("connect() failed");
    }

    freeaddrinfo(server_info);

    struct timeval timeout = {
        .tv_sec = TIMEOUT,
        .tv_usec = 0
    };

    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        error("setsockopt() failed");
    }

    char buf[BUF_SIZE];
    ssize_t n = read(sock, buf, BUF_SIZE);
    if (n == -1) {
        error("read() failed");
    }

    close(sock);

    if (n == 0) {
        return -1;
    }

    if (strstr(buf, "200 OK") != NULL) {
        return 200;
    } else if (strstr(buf, "404 Not Found") != NULL) {
        return 404;
    } else {
        return -1;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    Website website = {
        .url = argv[1],
        .status_code = 0,
        .start_time = 0,
        .end_time = 0
    };

    website.start_time = time(NULL);
    website.status_code = get_website_status(&website);
    website.end_time = time(NULL);

    if (website.status_code == 200) {
        printf("Website %s is up and running!\n", website.url);
    } else {
        printf("Website %s is down!\n", website.url);
    }

    printf("Start time: %s\n", ctime(&website.start_time));
    printf("End time: %s\n", ctime(&website.end_time));

    return 0;
}