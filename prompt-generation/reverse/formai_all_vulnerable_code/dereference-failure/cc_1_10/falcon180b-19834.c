//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PORT 65535

void scan_ports(int sock, struct sockaddr_in *server, int start_port, int end_port);

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *hostname;
    int port;
    int start_port = 1;
    int end_port = MAX_PORT;

    if(argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if(inet_pton(AF_INET, hostname, &server.sin_addr) <= 0) {
        printf("Invalid hostname\n");
        close(sock);
        return 1;
    }

    if(connect(sock, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1) {
        printf("Connection failed\n");
        close(sock);
        return 1;
    }

    scan_ports(sock, &server, start_port, end_port);

    close(sock);
    return 0;
}

void scan_ports(int sock, struct sockaddr_in *server, int start_port, int end_port) {
    int port;
    char buffer[1024];

    for(port = start_port; port <= end_port; port++) {
        if(port == 25) { // skip SMTP port
            continue;
        }

        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", inet_ntoa(server->sin_addr));

        if(send(sock, buffer, strlen(buffer), 0)!= strlen(buffer)) {
            printf("Error sending request\n");
            close(sock);
            return;
        }

        int bytes_received = 0;
        while(bytes_received < 1024) {
            int result = recv(sock, &buffer[bytes_received], 1024 - bytes_received, 0);
            if(result == -1 || result == 0) {
                printf("Error receiving response\n");
                close(sock);
                return;
            }
            bytes_received += result;
        }

        if(strstr(buffer, "200 OK")!= NULL) {
            printf("Port %d is open\n", port);
        }
    }
}