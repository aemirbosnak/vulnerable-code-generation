//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int bytes_sent, bytes_recv;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    printf("Enter server IP address: ");
    scanf("%s", inet_ntoa(serv_addr.sin_addr));
    printf("Enter server port: ");
    scanf("%d", &serv_addr.sin_port);

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    while (1) {
        printf("Enter message to send: ");
        fgets(send_buffer, BUFFER_SIZE, stdin);
        bytes_sent = send(sock, send_buffer, strlen(send_buffer), 0);
        if (bytes_sent == -1) {
            printf("Error sending message.\n");
            exit(1);
        }

        bytes_recv = recv(sock, recv_buffer, BUFFER_SIZE, 0);
        if (bytes_recv == -1) {
            printf("Error receiving message.\n");
            exit(1);
        }

        printf("Received message: %s\n", recv_buffer);
    }

    close(sock);
    return 0;
}