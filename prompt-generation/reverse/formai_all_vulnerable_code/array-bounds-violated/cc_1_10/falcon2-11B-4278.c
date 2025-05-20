//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/time.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 5000

int main() {
    struct sockaddr_in server_address;
    int socket_fd, n;
    char buffer[1024];
    struct timeval tv;

    if ( ( socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
        perror("Error opening socket");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);

    if ( ( connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address))) < 0 ) {
        perror("Error connecting to server");
        return 1;
    }

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    while ( 1 ) {
        if ( ( n = recv(socket_fd, buffer, sizeof(buffer), 0)) < 0 ) {
            perror("Error receiving from server");
            return 1;
        }

        if ( n > 0 ) {
            buffer[n] = '\0';
            printf("Received message: %s\n", buffer);
        }

        tv.tv_sec = 5;
        tv.tv_usec = 0;
        select(0, NULL, NULL, NULL, &tv);
    }

    return 0;
}