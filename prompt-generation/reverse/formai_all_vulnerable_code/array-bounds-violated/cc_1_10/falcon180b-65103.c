//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDR "127.0.0.1"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAX_PACKET_SIZE];
    int bytes_received;

    // create socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDR, &server_addr.sin_addr);

    // send packet to server
    int packet_size = strlen("hello");
    strcpy(buffer, "hello");
    sendto(sock, buffer, packet_size, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // receive response from server
    bytes_received = recvfrom(sock, buffer, MAX_PACKET_SIZE, 0, NULL, NULL);
    if (bytes_received == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    // print response
    buffer[bytes_received] = '\0';
    printf("Response: %s\n", buffer);

    // close socket
    close(sock);

    return 0;
}