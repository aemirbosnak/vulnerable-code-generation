//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024
#define IMAP_PORT 143

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[MAX_LENGTH];
    int status;

    // Create socket and connect to IMAP server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(IMAP_PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        perror("inet_pton failed");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    // Send IMAP command to retrieve email
    printf("Enter IMAP command: ");
    scanf("%s", buffer);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Send failed");
        exit(1);
    }

    // Receive response from IMAP server
    n = recv(sockfd, buffer, MAX_LENGTH, 0);
    if (n < 0) {
        perror("Recv failed");
        exit(1);
    }
    printf("IMAP server response: %s\n", buffer);

    // Close socket and exit
    close(sockfd);
    exit(0);
}