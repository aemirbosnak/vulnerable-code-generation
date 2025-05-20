//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sock, port, opt = TRUE;
    struct sockaddr_in server;
    char buffer[BUFSIZE];

    if(argc!= 4) {
        printf("Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        exit(0);
    }

    strcpy(server.sin_zero, "");
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1) {
        printf("Error creating socket\n");
        exit(0);
    }

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(0);
    }

    for(port = atoi(argv[2]); port <= atoi(argv[3]); port++) {
        if(opt) {
            if(send(sock, "GET / HTTP/1.1\r\nHost: 10.0.0.1\r\n\r\n", 64, 0) == -1) {
                printf("Port %d is closed\n", port);
            } else {
                if(recv(sock, buffer, BUFSIZE, 0) == -1) {
                    printf("Error receiving data\n");
                    exit(0);
                }

                if(strstr(buffer, "200 OK")!= NULL) {
                    printf("Port %d is open\n", port);
                } else {
                    printf("Port %d is closed\n", port);
                }
            }
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sock);

    return 0;
}