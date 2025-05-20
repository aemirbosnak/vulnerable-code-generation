//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *cmd;

    // check if the required arguments are provided
    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <port_number> <command>\n");
        return 0;
    }

    // convert the server IP and port number to integer format
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    // create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 0;
    }

    // connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 0;
    }

    // send the command to the server
    cmd = argv[3];
    send(sock, cmd, strlen(cmd), 0);

    // receive the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    while (recv(sock, buffer, BUFFER_SIZE, 0) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    // close the socket
    close(sock);

    return 0;
}