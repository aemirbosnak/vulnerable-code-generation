//Falcon-180B DATASET v1.0 Category: Networking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    int n;
    int total_bytes_received = 0;
    int max_bytes_to_receive = 100000; // 100 KB

    if (argc!= 3) {
        printf("Usage:./client <server_ip> <port>\n");
        return 1;
    }

    port = atoi(argv[2]);
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("No such host\n");
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    while (total_bytes_received < max_bytes_to_receive) {
        n = recv(sock, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving data\n");
            return 1;
        }
        total_bytes_received += n;
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}