//MISTRAL-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <signal.h>

#define MAX_TRY 5
#define TIMEOUT 3
#define BUFFER_SIZE 1024

typedef struct {
    char host[256];
    int port;
    int status;
    struct timeval last_checked;
} Monitor;

Monitor monitors[10];
int monitor_count = 0;

void sig_alarm(int signo) {
    for (int i = 0; i < monitor_count; ++i) {
        struct timeval now;
        gettimeofday(&now, NULL);
        long long diff = (now.tv_sec - monitors[i].last_checked.tv_sec) * 1000LL + (now.tv_usec - monitors[i].last_checked.tv_usec) / 1000;
        if (diff > TIMEOUT * 1000) {
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);
            struct sockaddr_in server_addr;
            memset(&server_addr, 0, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(monitors[i].port);
            inet_pton(AF_INET, monitors[i].host, &server_addr.sin_addr);

            if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
                perror("Error connecting to the website");
                monitors[i].status = -1;
            } else {
                close(sockfd);
                monitors[i].status = 1;
                printf("[!] Website %s:%d is UP!\n", monitors[i].host, monitors[i].port);
            }

            monitors[i].last_checked = now;
        }
    }
    alarm(TIMEOUT);
}

void add_monitor(const char* host, int port) {
    if (monitor_count >= sizeof(monitors) / sizeof(Monitor)) {
        fprintf(stderr, "Maximum number of monitors reached\n");
        return;
    }

    strcpy(monitors[monitor_count].host, host);
    monitors[monitor_count].port = port;
    monitors[monitor_count].status = -1;
    gettimeofday(&monitors[monitor_count].last_checked, NULL);
    monitor_count++;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    add_monitor(argv[1], atoi(argv[2]));

    printf("[!!] Monitor started for website %s:%s\n", argv[1], argv[2]);
    alarm(TIMEOUT);

    while (1) {
        sig_alarm(SIGALRM);
        usleep(100000);
    }

    return 0;
}