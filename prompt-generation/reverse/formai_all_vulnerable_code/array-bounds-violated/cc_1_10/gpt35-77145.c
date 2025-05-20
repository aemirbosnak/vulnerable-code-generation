//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <signal.h>

#define MAXLINE 1000
#define PORT 5000

volatile sig_atomic_t done = 0;

void signal_handler(int sig) {
    done = 1;
}

int main() {
    signal(SIGINT, signal_handler);

    int sockfd;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    char buffer[MAXLINE];
    char recv_message[MAXLINE*10];
    long total_bytes = 0;

    while (!done) {
        memset(buffer, 0, sizeof(buffer));
        snprintf(buffer, MAXLINE, "Client message at %ld", time(NULL));

        if (send(sockfd, buffer, strlen(buffer), 0) < 0)
        {
            perror("Send failed");
        }
        else
        {
            total_bytes += strlen(buffer);
            printf("Sent: %s\n", buffer);
        }

        memset(recv_message, 0, sizeof(recv_message));
        ssize_t bytes_received = recv(sockfd, recv_message, sizeof(recv_message), 0);

        if (bytes_received < 0)
        {
            perror("Receive failed");
        }
        else if (bytes_received == 0)
        {
            printf("Server disconnected\n");
            done = 1;
        }
        else
        {
            total_bytes += bytes_received;
            recv_message[bytes_received] = 0;
            printf("Received: %s\n", recv_message);
        }

        usleep(50000);
    }

    close(sockfd);
    printf("Total bytes transferred: %ld\n", total_bytes);

    return 0;
}