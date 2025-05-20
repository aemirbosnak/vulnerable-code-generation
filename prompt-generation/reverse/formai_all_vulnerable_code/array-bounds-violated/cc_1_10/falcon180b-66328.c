//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock = 0;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *username = "anonymous";
    char *password = "anonymous@example.com";
    int port = 21;

    // Connect to the FTP server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket.\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to the FTP server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server.\n");
        close(sock);
        return 1;
    }

    // Send username and password
    send(sock, username, strlen(username), 0);
    send(sock, password, strlen(password), 0);

    while (1) {
        // Receive data from the server
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error: Could not receive data from server.\n");
            close(sock);
            return 1;
        }

        // Print data to console
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}