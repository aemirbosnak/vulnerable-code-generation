//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char target_ip[100];
    int target_port;
    char response[BUFFER_SIZE];
    int sock;
    struct hostent *host;
    struct sockaddr_in server_addr;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    strcpy(target_ip, argv[1]);
    target_port = atoi(argv[2]);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Socket creation failed\n");
        return 1;
    }

    host = gethostbyname(target_ip);
    if (host == NULL) {
        printf("Error: Host not found\n");
        close(sock);
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(target_port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Connection failed\n");
        close(sock);
        return 1;
    }

    printf("Connected to %s:%d\n", target_ip, target_port);

    // Send data
    if (send(sock, "GET / HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: Close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: Close\r\n\r\n"), 0) == -1) {
        printf("Error: Data send failed\n");
        close(sock);
        return 1;
    }

    // Receive response
    if (recv(sock, response, BUFFER_SIZE, 0) == -1) {
        printf("Error: Data receive failed\n");
        close(sock);
        return 1;
    }

    printf("Response: %s\n", response);

    close(sock);
    return 0;
}