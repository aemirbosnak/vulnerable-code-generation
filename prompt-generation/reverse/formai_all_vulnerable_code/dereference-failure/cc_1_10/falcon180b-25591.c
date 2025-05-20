//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 100
#define PORT "3490"

typedef struct {
    char ssid[MAX];
    int signal;
} wifi_t;

void *run(void *param) {
    char buffer[1024];
    int length;
    wifi_t *data = (wifi_t *) param;

    while(1) {
        length = read(data->signal, buffer, sizeof(buffer));
        if(length <= 0) {
            break;
        }
        printf("Wi-Fi signal strength for %s is %d\n", data->ssid, length);
    }

    return NULL;
}

int main(int argc, char **argv) {
    int sock, newsock, portno;
    struct sockaddr_in serv_addr, cli_addr;
    wifi_t *data;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("socket failed");
        exit(errno);
    }

    portno = atoi(PORT);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(errno);
    }

    listen(sock, 5);

    while(1) {
        newsock = accept(sock, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
        if(newsock < 0) {
            perror("accept failed");
            exit(errno);
        }

        data = (wifi_t *) malloc(sizeof(wifi_t));
        strcpy(data->ssid, "");
        data->signal = newsock;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, run, (void *) data);
    }

    return 0;
}