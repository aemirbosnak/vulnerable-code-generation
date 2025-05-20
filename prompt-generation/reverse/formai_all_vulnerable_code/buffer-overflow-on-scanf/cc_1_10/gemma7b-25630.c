//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    int sockfd, port, n, err, timeout = 5;
    char hostname[256], buffer[1024], message[1024], ping_reply[1024];
    struct sockaddr_in serv_addr;

    printf("Please enter the hostname or IP address of the target computer: ");
    scanf("%s", hostname);

    printf("Enter the port number you want to ping (default is 53): ");
    scanf("%d", &port);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, htons(port))) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    sprintf(message, "Ping! From: %s", hostname);
    n = sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    if (n < 0) {
        perror("Error sending message");
        exit(1);
    }

    printf("Sending ping...\n");

    memset(ping_reply, 0, 1024);
    n = recvfrom(sockfd, ping_reply, 1024, 0, (struct sockaddr *)&serv_addr, NULL);

    if (n < 0) {
        perror("Error receiving reply");
        exit(1);
    }

    printf("Received ping reply: %s\n", ping_reply);

    close(sockfd);

    return 0;
}