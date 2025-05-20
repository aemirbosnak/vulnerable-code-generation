//Falcon-180B DATASET v1.0 Category: Networking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *ip_address = "127.0.0.1";
    int port = SERVER_PORT;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);

    snprintf(buffer, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: MyProgram\r\nTimestamp: %s\r\n\r\n", ip_address, timestamp);

    send(sockfd, buffer, strlen(buffer), 0);

    char response[BUFFER_SIZE];
    int bytes_received = 0;

    while ((bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }

    close(sockfd);

    return 0;
}