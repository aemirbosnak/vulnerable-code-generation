//Falcon-180B DATASET v1.0 Category: System event logger ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/timerfd.h>
#include <time.h>

#define MAX_EVENTS 10
#define TIMER_INTERVAL 1 // in seconds

int epoll_fd;
int timer_fd;

struct epoll_event events[MAX_EVENTS];

void timer_callback(int fd, uint32_t events, void *data) {
    printf("Timer expired!\n");
    close(timer_fd);
    exit(0);
}

void event_callback(int fd, uint32_t events, void *data) {
    printf("Event occurred on file descriptor %d\n", fd);
}

int main() {
    int i;
    epoll_fd = epoll_create(MAX_EVENTS);
    if (epoll_fd == -1) {
        printf("Error creating epoll instance\n");
        exit(1);
    }

    timer_fd = timerfd_create(CLOCK_MONOTONIC, 0);
    if (timer_fd == -1) {
        printf("Error creating timerfd instance\n");
        exit(1);
    }

    struct itimerspec timer_spec = {
       .it_interval = {.tv_sec = TIMER_INTERVAL },
       .it_value = {.tv_sec = TIMER_INTERVAL }
    };

    if (timerfd_settime(timer_fd, 0, &timer_spec, NULL) == -1) {
        printf("Error setting timerfd interval\n");
        exit(1);
    }

    for (i = 0; i < MAX_EVENTS; i++) {
        events[i].data.fd = i;
        events[i].events = EPOLLIN;
    }

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, STDIN_FILENO, &events[0]) == -1) {
        printf("Error adding stdin to epoll\n");
        exit(1);
    }

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, timer_fd, &events[1]) == -1) {
        printf("Error adding timerfd to epoll\n");
        exit(1);
    }

    printf("Press any key to exit...\n");

    char c;
    scanf("%c", &c);

    close(epoll_fd);
    close(timer_fd);

    return 0;
}