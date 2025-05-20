//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // Receive welcome message from server
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send username to server
    char username[50];
    printf("Enter username: ");
    scanf("%s", username);
    char userpass[100];
    sprintf(userpass, "USER %s\r\n", username);
    send(sockfd, userpass, strlen(userpass), 0);

    // Receive response from server
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send password to server
    char password[50];
    printf("Enter password: ");
    scanf("%s", password);
    char passcmd[100];
    sprintf(passcmd, "PASS %s\r\n", password);
    send(sockfd, passcmd, strlen(passcmd), 0);

    // Receive response from server
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Open passive connection to server
    send(sockfd, "PASV\r\n", 6, 0);

    // Receive response from server
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Get IP and port from response
    char *ip_str, *port_str, *p;
    int ip[4], port[2];
    p = strtok(buffer, "(");
    p = strtok(NULL, "(");
    p = strtok(p, ")");
    ip_str = strtok(p, ",");
    for (int i = 0; i < 4; i++) {
        ip[i] = atoi(ip_str);
        ip_str = strtok(NULL, ",");
    }
    port_str = strtok(NULL, ",");
    port[0] = atoi(port_str);
    port_str = strtok(NULL, ",");
    port[1] = atoi(port_str);

    // Connect to server
    struct sockaddr_in passive_addr;
    int passive_sockfd;
    passive_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    passive_addr.sin_family = AF_INET;
    passive_addr.sin_port = htons(port[0] * 256 + port[1]);
    passive_addr.sin_addr.s_addr = inet_addr(ip_str);
    if (connect(passive_sockfd, (struct sockaddr *)&passive_addr, sizeof(passive_addr)) < 0) {
        perror("Failed to connect to passive server");
        exit(EXIT_FAILURE);
    }

    // Send list command to server
    send(sockfd, "LIST\r\n", 6, 0);

    // Receive response from server
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Receive file list from server
    if (recv(passive_sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Failed to receive file list");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Close sockets
    close(sockfd);
    close(passive_sockfd);

    return 0;
}