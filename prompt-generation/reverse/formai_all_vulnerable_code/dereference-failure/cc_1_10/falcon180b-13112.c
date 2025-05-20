//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    int connect_status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (connect_status == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    char send_buffer[BUFFER_SIZE];
    memset(send_buffer, 0, BUFFER_SIZE);
    sprintf(send_buffer, "PING\n");

    int send_status = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (send_status == -1) {
        printf("Error sending data\n");
        close(sockfd);
        return 1;
    }

    char receive_buffer[BUFFER_SIZE];
    memset(receive_buffer, 0, BUFFER_SIZE);
    int receive_status = recv(sockfd, receive_buffer, BUFFER_SIZE, 0);
    if (receive_status == -1) {
        printf("Error receiving data\n");
        close(sockfd);
        return 1;
    }

    printf("Received: %s\n", receive_buffer);

    close(sockfd);
    return 0;
}