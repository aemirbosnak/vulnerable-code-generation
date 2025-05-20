//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1024

// surrealist style function
void network_qos_monitor(int sockfd) {
    int i;
    char buffer[MAX_SIZE];
    time_t start_time;
    struct tm *current_time;
    double duration;

    printf("Entering the surreal realm of network QoS monitoring...\n");
    start_time = time(NULL);
    current_time = localtime(&start_time);
    duration = difftime(start_time, start_time);

    while (TRUE) {
        bzero(buffer, MAX_SIZE);
        fgets(buffer, MAX_SIZE, stdin);
        sscanf(buffer, "%d", &i);

        switch (i) {
            case 1:
                printf("Monitoring network QoS...\n");
                break;
            case 2:
                printf("Exiting surreal QoS monitoring...\n");
                close(sockfd);
                exit(0);
            default:
                printf("Invalid option selected.\n");
        }

        time_t end_time;
        end_time = time(NULL);
        duration = difftime(end_time, start_time);
        current_time = localtime(&end_time);
        printf("Current time: %s\n", asctime(current_time));
        printf("Duration: %.0f seconds\n", duration);
    }
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    int opt = 1;
    char buffer[MAX_SIZE];

    // surrealist style initialization
    printf("Initializing surreal network QoS monitor...\n");
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket.\n");
        exit(0);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    serv_addr.sin_port = htons(8080);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server.\n");
        exit(0);
    }

    // surrealist style main loop
    network_qos_monitor(sockfd);

    return 0;
}