//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define POP3_PORT 110
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and IP address of the POP3 server
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    char *ip_address = inet_ntoa(*((struct in_addr *) host->h_addr_list[0]));

    // Create a socket and connect to the POP3 server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: Could not create socket");
        return EXIT_FAILURE;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error: Could not connect to server");
        return EXIT_FAILURE;
    }

    // Receive the welcome message from the POP3 server
    char line[MAX_LINE];
    if (recv(sockfd, line, MAX_LINE - 1, 0) == -1) {
        perror("Error: Could not receive welcome message");
        return EXIT_FAILURE;
    }
    printf("%s", line);

    // Send the USER command to the POP3 server
    char command[MAX_LINE];
    snprintf(command, MAX_LINE, "USER %s\r\n", argv[2]);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Error: Could not send USER command");
        return EXIT_FAILURE;
    }

    // Receive the response to the USER command
    if (recv(sockfd, line, MAX_LINE - 1, 0) == -1) {
        perror("Error: Could not receive response to USER command");
        return EXIT_FAILURE;
    }
    printf("%s", line);

    // Send the PASS command to the POP3 server
    snprintf(command, MAX_LINE, "PASS %s\r\n", argv[3]);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Error: Could not send PASS command");
        return EXIT_FAILURE;
    }

    // Receive the response to the PASS command
    if (recv(sockfd, line, MAX_LINE - 1, 0) == -1) {
        perror("Error: Could not receive response to PASS command");
        return EXIT_FAILURE;
    }
    printf("%s", line);

    // Send the LIST command to the POP3 server
    if (send(sockfd, "LIST\r\n", 6, 0) == -1) {
        perror("Error: Could not send LIST command");
        return EXIT_FAILURE;
    }

    // Receive the response to the LIST command
    while (1) {
        if (recv(sockfd, line, MAX_LINE - 1, 0) == -1) {
            perror("Error: Could not receive response to LIST command");
            return EXIT_FAILURE;
        }
        printf("%s", line);
        if (strstr(line, ".") != NULL) {
            break;
        }
    }

    // Send the QUIT command to the POP3 server
    if (send(sockfd, "QUIT\r\n", 6, 0) == -1) {
        perror("Error: Could not send QUIT command");
        return EXIT_FAILURE;
    }

    // Receive the response to the QUIT command
    if (recv(sockfd, line, MAX_LINE - 1, 0) == -1) {
        perror("Error: Could not receive response to QUIT command");
        return EXIT_FAILURE;
    }
    printf("%s", line);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}