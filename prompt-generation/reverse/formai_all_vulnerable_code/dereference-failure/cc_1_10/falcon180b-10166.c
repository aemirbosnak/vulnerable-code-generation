//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TRUE   1
#define FALSE  0
#define DEBUG  TRUE

#define LIGHT_ON "ON"
#define LIGHT_OFF "OFF"

int main(int argc, char *argv[]) {

    int sock;
    struct sockaddr_in server;
    char send_data[1024], recv_data[1024];
    int bytes_sent, bytes_recv;
    int port, opt = TRUE;
    char* ip;

    // Check command line arguments
    if (argc!= 6) {
        printf("Usage:./smart_home_light_control <IP> <PORT> <LIGHT_STATUS> <USERNAME> <PASSWORD>\n");
        exit(1);
    }

    // Assign command line arguments to variables
    ip = argv[1];
    port = atoi(argv[2]);
    strcpy(send_data, argv[3]);
    strcpy(send_data + strlen(send_data), " ");
    strcpy(send_data + strlen(send_data), argv[4]);
    strcpy(send_data + strlen(send_data), " ");
    strcpy(send_data + strlen(send_data), argv[5]);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set socket options
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    // Connect to server
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send data to server
    bytes_sent = send(sock, send_data, strlen(send_data), 0);
    if (bytes_sent < 0) {
        printf("Error sending data\n");
        exit(1);
    }

    // Receive data from server
    bytes_recv = recv(sock, recv_data, sizeof(recv_data), 0);
    if (bytes_recv < 0) {
        printf("Error receiving data\n");
        exit(1);
    }

    // Print received data
    printf("Received data: %s\n", recv_data);

    // Close socket
    close(sock);

    return 0;
}