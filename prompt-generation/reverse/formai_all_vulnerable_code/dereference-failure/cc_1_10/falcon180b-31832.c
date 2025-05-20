//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int bytes_sent, bytes_recv;
    struct timeval timeout;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(send_buffer, 0, BUFFER_SIZE);
        memset(recv_buffer, 0, BUFFER_SIZE);

        printf("Enter a message to send: ");
        fgets(send_buffer, BUFFER_SIZE, stdin);

        bytes_sent = send(sockfd, send_buffer, strlen(send_buffer), 0);
        if (bytes_sent == -1) {
            printf("Error sending message\n");
            exit(1);
        }

        printf("Message sent successfully\n");

        memset(recv_buffer, 0, BUFFER_SIZE);
        bytes_recv = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
        if (bytes_recv == -1) {
            printf("Error receiving message\n");
            exit(1);
        }

        printf("Message received: %s\n", recv_buffer);

        if (strcmp(recv_buffer, "bye") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}