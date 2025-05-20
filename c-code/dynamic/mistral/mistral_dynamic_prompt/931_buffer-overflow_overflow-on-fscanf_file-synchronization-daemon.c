#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd, new_sockfd, numbytes;
    struct sockaddr_in server, client;
    char buffer[BUFFER_SIZE];
    ssize_t read;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Binding error");
        exit(1);
    }

    listen(sockfd, 5);
    printf("Listening on port %d\n", PORT);

    while (1) {
        new_sockfd = accept(sockfd, (struct sockaddr *)&client, (socklen_t *)NULL);
        read = recv(new_sockfd, buffer, BUFFER_SIZE, 0);
        if (read > 0) {
            sscanf(buffer, "%s%s%n", &buffer, &buffer + sizeof(buffer) - 4, &numbytes);
            memcpy(buffer + numbytes, "This is our secret!", strlen("This is our secret!"));
            write(new_sockfd, buffer, sizeof(buffer));
        }
    }

    return 0;
}
