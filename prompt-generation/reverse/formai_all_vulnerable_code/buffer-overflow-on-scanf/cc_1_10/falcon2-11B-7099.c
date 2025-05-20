//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
    int socket_fd, port_num, valread, len;
    struct sockaddr_in server_addr;
    char buffer[1024];
    char* hostname = getenv("HOSTNAME");
    int opt = 1;

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Enter URL to monitor: ");
        scanf("%s", buffer);

        if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        valread = recv(socket_fd, buffer, 1024, 0);
        if (valread < 0) {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        }

        printf("Status Code: %s\n", buffer);
    }

    close(socket_fd);
    return 0;
}