//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <user>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    struct hostent *host_info;

    // Get the hostname from the command line.
    host_info = gethostbyname(argv[1]);
    if (host_info == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", argv[1]);
        return 1;
    }

    // Set up the socket address structure.
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    // Create the socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: could not create socket");
        return 1;
    }

    // Connect to the POP3 server.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: could not connect to POP3 server");
        return 1;
    }

    // Get the welcome message from the server.
    char buf[1024];
    int bytes_read = recv(sockfd, buf, sizeof(buf), 0);
    if (bytes_read < 0) {
        perror("Error: could not receive welcome message from server");
        return 1;
    }

    printf("Welcome message: %s\n", buf);

    // Send the USER command.
    sprintf(buf, "USER %s\r\n", argv[2]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("Error: could not send USER command");
        return 1;
    }

    // Get the response to the USER command.
    bytes_read = recv(sockfd, buf, sizeof(buf), 0);
    if (bytes_read < 0) {
        perror("Error: could not receive response to USER command");
        return 1;
    }

    printf("Response to USER command: %s\n", buf);

    // Send the PASS command.
    sprintf(buf, "PASS %s\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("Error: could not send PASS command");
        return 1;
    }

    // Get the response to the PASS command.
    bytes_read = recv(sockfd, buf, sizeof(buf), 0);
    if (bytes_read < 0) {
        perror("Error: could not receive response to PASS command");
        return 1;
    }

    printf("Response to PASS command: %s\n", buf);

    // Send the STAT command.
    if (send(sockfd, "STAT\r\n", 6, 0) < 0) {
        perror("Error: could not send STAT command");
        return 1;
    }

    // Get the response to the STAT command.
    bytes_read = recv(sockfd, buf, sizeof(buf), 0);
    if (bytes_read < 0) {
        perror("Error: could not receive response to STAT command");
        return 1;
    }

    printf("Response to STAT command: %s\n", buf);

    // Send the LIST command.
    if (send(sockfd, "LIST\r\n", 6, 0) < 0) {
        perror("Error: could not send LIST command");
        return 1;
    }

    // Get the response to the LIST command.
    bytes_read = recv(sockfd, buf, sizeof(buf), 0);
    if (bytes_read < 0) {
        perror("Error: could not receive response to LIST command");
        return 1;
    }

    printf("Response to LIST command: %s\n", buf);

    // Send the QUIT command.
    if (send(sockfd, "QUIT\r\n", 6, 0) < 0) {
        perror("Error: could not send QUIT command");
        return 1;
    }

    // Close the socket.
    close(sockfd);

    return 0;
}