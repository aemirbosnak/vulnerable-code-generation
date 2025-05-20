//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    char hostname[100];
    int port = 0;
    int sockfd = 0;
    struct sockaddr_in server_addr;
    int addrlen = sizeof(server_addr);
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    int signal_strength = 0;

    printf("Enter Wi-Fi network name: ");
    scanf("%s", hostname);

    if ((port = getaddrinfo(hostname, NULL, NULL, &server_addr))!= 0) {
        printf("Error: cannot connect to Wi-Fi network.\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: cannot create socket.\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: cannot connect to Wi-Fi network.\n");
        exit(1);
    }

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        if (strstr(buffer, "Signal Strength:")!= NULL) {
            signal_strength = atoi(strtok(buffer, " "));
            break;
        }
    }

    close(sockfd);

    printf("Wi-Fi signal strength: %d\n", signal_strength);

    return 0;
}