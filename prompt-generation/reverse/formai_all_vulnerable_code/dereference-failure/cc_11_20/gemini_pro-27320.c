//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_MSG_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(1);
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", argv[1]);
        exit(1);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Could not create socket");
        exit(1);
    }

    // Connect to the host
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr_list[0];

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Could not connect to host");
        close(sockfd);
        exit(1);
    }

    // Receive the welcome message
    char buf[MAX_MSG_SIZE];
    if (recv(sockfd, buf, MAX_MSG_SIZE, 0) < 0) {
        perror("Error: Could not receive welcome message");
        close(sockfd);
        exit(1);
    }

    // Send the USER command
    sprintf(buf, "USER %s\n", argv[2]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("Error: Could not send USER command");
        close(sockfd);
        exit(1);
    }

    // Receive the response to the USER command
    if (recv(sockfd, buf, MAX_MSG_SIZE, 0) < 0) {
        perror("Error: Could not receive response to USER command");
        close(sockfd);
        exit(1);
    }

    // Send the PASS command
    sprintf(buf, "PASS %s\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("Error: Could not send PASS command");
        close(sockfd);
        exit(1);
    }

    // Receive the response to the PASS command
    if (recv(sockfd, buf, MAX_MSG_SIZE, 0) < 0) {
        perror("Error: Could not receive response to PASS command");
        close(sockfd);
        exit(1);
    }

    // Send the LIST command
    if (send(sockfd, "LIST\n", strlen("LIST\n"), 0) < 0) {
        perror("Error: Could not send LIST command");
        close(sockfd);
        exit(1);
    }

    // Receive the response to the LIST command
    while (1) {
        if (recv(sockfd, buf, MAX_MSG_SIZE, 0) < 0) {
            perror("Error: Could not receive response to LIST command");
            close(sockfd);
            exit(1);
        }

        if (strstr(buf, "\n.\n") != NULL) {
            break;
        }

        printf("%s", buf);
    }

    // Send the QUIT command
    if (send(sockfd, "QUIT\n", strlen("QUIT\n"), 0) < 0) {
        perror("Error: Could not send QUIT command");
        close(sockfd);
        exit(1);
    }

    // Receive the response to the QUIT command
    if (recv(sockfd, buf, MAX_MSG_SIZE, 0) < 0) {
        perror("Error: Could not receive response to QUIT command");
        close(sockfd);
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}