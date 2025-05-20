//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: irregular
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <netdb.h>

/* Keep track of the uptime of a website */
struct website {
    char *url;
    int sockfd;
    time_t last_check;
    time_t last_up;
};

/* Create a new website uptime monitor */
struct website *website_new(const char *url) {
    struct website *w = malloc(sizeof(struct website));
    w->url = strdup(url);
    w->sockfd = -1;
    w->last_check = 0;
    w->last_up = 0;
    return w;
}

/* Free a website uptime monitor */
void website_free(struct website *w) {
    free(w->url);
    close(w->sockfd);
    free(w);
}

/* Check the uptime of a website */
int website_check(struct website *w) {
    int ret;
    struct timespec ts;
    struct addrinfo hints, *res, *res0;
    char *host, *port;

    /* Parse the URL */
    ret = sscanf(w->url, "http://%[^:]:%s", &host, &port);
    if (ret != 2) {
        errno = EINVAL;
        return -1;
    }

    /* Resolve the hostname */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    ret = getaddrinfo(host, port, &hints, &res0);
    if (ret != 0) {
        errno = EHOSTUNREACH;
        return -1;
    }

    /* Create a socket */
    w->sockfd = socket(res0->ai_family, res0->ai_socktype, res0->ai_protocol);
    if (w->sockfd == -1) {
        return -1;
    }

    /* Connect to the website */
    ret = connect(w->sockfd, res0->ai_addr, res0->ai_addrlen);
    if (ret != 0) {
        close(w->sockfd);
        w->sockfd = -1;
        errno = ECONNREFUSED;
        return -1;
    }

    /* Get the current time */
    clock_gettime(CLOCK_MONOTONIC, &ts);

    /* Update the website's last check and last up times */
    w->last_check = ts.tv_sec;
    w->last_up = ts.tv_sec;

    /* Free the address info */
    freeaddrinfo(res0);

    return 0;
}

/* Monitor the uptime of a website */
void website_monitor(struct website *w) {
    int ret;
    struct epoll_event ev;

    /* Create an epoll instance */
    int epollfd = epoll_create1(0);
    if (epollfd == -1) {
        return;
    }

    /* Add the website's socket to the epoll instance */
    ev.events = EPOLLIN | EPOLLPRI;
    ev.data.fd = w->sockfd;
    ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, w->sockfd, &ev);
    if (ret != 0) {
        close(epollfd);
        return;
    }

    /* Monitor the website's uptime */
    while (1) {
        /* Wait for an event */
        struct epoll_event events[1];
        ret = epoll_wait(epollfd, events, 1, -1);
        if (ret == -1) {
            if (errno == EINTR) {
                continue;
            }
            break;
        }

        /* Check if the website is up */
        ret = website_check(w);
        if (ret != 0) {
            printf("Website %s is down\n", w->url);
        } else {
            printf("Website %s is up\n", w->url);
        }
    }

    /* Close the epoll instance */
    close(epollfd);
}

/* Main function */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    /* Create a new website uptime monitor */
    struct website *w = website_new(argv[1]);

    /* Monitor the website's uptime */
    website_monitor(w);

    /* Free the website uptime monitor */
    website_free(w);

    return 0;
}