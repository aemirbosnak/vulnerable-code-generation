//Code Llama-13B DATASET v1.0 Category: Drone Remote Control ; Style: Dennis Ritchie
/*
 * drone_remote.c
 *
 * A simple Drone Remote Control program written in C.
 *
 * Usage: ./drone_remote <drone_ip> <drone_port>
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <drone_ip> <drone_port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket()");
        return 1;
    }

    // Get the drone's IP and port
    char *ip = argv[1];
    int port = atoi(argv[2]);

    // Set up the server address and port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        perror("inet_pton()");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect()");
        return 1;
    }

    // Send the commands to the server
    char *cmds[] = {"forward", "left", "right", "backward"};
    for (int i = 0; i < 4; i++) {
        char *cmd = cmds[i];
        send(sock, cmd, strlen(cmd), 0);
        sleep(1);
    }

    // Close the socket
    close(sock);

    return 0;
}