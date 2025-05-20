//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define FTP_PORT 21
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[MAX_LINE_LENGTH];
    char command[MAX_LINE_LENGTH];
    char hostname[MAX_LINE_LENGTH];
    char username[MAX_LINE_LENGTH];
    char password[MAX_LINE_LENGTH];

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password> <command>\n", argv[0]);
        exit(1);
    }

    // Get the hostname, username, password, and command from the command line arguments.
    strcpy(hostname, argv[1]);
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);
    strcpy(command, argv[4]);

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Get the IP address of the FTP server.
    struct hostent *hp = gethostbyname(hostname);
    if (hp == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hostname);
        exit(1);
    }

    // Fill in the sockaddr_in structure.
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(FTP_PORT);
    servaddr.sin_addr = *((struct in_addr *)hp->h_addr);

    // Connect to the FTP server.
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Read the welcome message from the FTP server.
    n = read(sockfd, buf, MAX_LINE_LENGTH);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("%s", buf);

    // Send the USER command to the FTP server.
    sprintf(buf, "USER %s\r\n", username);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the response from the FTP server.
    n = read(sockfd, buf, MAX_LINE_LENGTH);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("%s", buf);

    // Send the PASS command to the FTP server.
    sprintf(buf, "PASS %s\r\n", password);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the response from the FTP server.
    n = read(sockfd, buf, MAX_LINE_LENGTH);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("%s", buf);

    // Send the command to the FTP server.
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the response from the FTP server.
    while ((n = read(sockfd, buf, MAX_LINE_LENGTH)) > 0) {
        printf("%s", buf);
    }
    if (n < 0) {
        perror("read");
        exit(1);
    }

    // Close the socket.
    close(sockfd);

    return 0;
}