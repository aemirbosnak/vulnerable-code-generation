//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 4096

int main(int argc, char **argv) {
    int sockfd, n, port, messageCount = 1;
    char recvline[MAXLINE + 1], buffer[MAXLINE + 1];
    struct sockaddr_in servaddr;
    struct hostent *server;

    // Check command line arguments
    if (argc != 3) {
        printf("usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get port number
    port = atoi(argv[2]);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Couldn't create socket");
        exit(EXIT_FAILURE);
    }

    // Get server IP address
    if ((server = gethostbyname(argv[1])) == NULL) {
        perror("Couldn't get server IP address");
        exit(EXIT_FAILURE);
    }

    // Set up address structure
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Couldn't connect to server");
        exit(EXIT_FAILURE);
    }

    // Read greeting message from server
    n = read(sockfd, recvline, MAXLINE);
    if (n <= 0) {
        perror("Couldn't read from socket");
        exit(EXIT_FAILURE);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // Send USER command to server
    printf("Please enter your username: ");
    fgets(buffer, MAXLINE, stdin);
    sprintf(buffer, "USER %s", strchr(buffer,'\n'));
    write(sockfd, buffer, strlen(buffer));

    // Read response from server
    n = read(sockfd, recvline, MAXLINE);
    if (n <= 0) {
        perror("Couldn't read from socket");
        exit(EXIT_FAILURE);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // Send PASS command to server
    printf("Please enter your password: ");
    fgets(buffer, MAXLINE, stdin);
    sprintf(buffer, "PASS %s", strchr(buffer,'\n'));
    write(sockfd, buffer, strlen(buffer));

    // Read response from server
    n = read(sockfd, recvline, MAXLINE);
    if (n <= 0) {
        perror("Couldn't read from socket");
        exit(EXIT_FAILURE);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // Send STAT command to server
    write(sockfd, "STAT", strlen("STAT"));

    // Read response from server
    n = read(sockfd, recvline, MAXLINE);
    if (n <= 0) {
        perror("Couldn't read from socket");
        exit(EXIT_FAILURE);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // Get number of messages and total size from response
    int numMessages, totalSize;
    sscanf(recvline,"+OK %d %d",&numMessages,&totalSize);

    // Print summary
    printf("You have %d messages totaling %d bytes\n", numMessages, totalSize);

    // Loop through each message and print its details
    while (messageCount <= numMessages) {
        sprintf(buffer, "TOP %d 0", messageCount);
        write(sockfd, buffer, strlen(buffer));

        // Read response from server
        n = read(sockfd, recvline, MAXLINE);
        if (n <= 0) {
            perror("Couldn't read from socket");
            exit(EXIT_FAILURE);
        }
        recvline[n] = 0;
        printf("Message %d:\n%s", messageCount, recvline);

        // Increment message count
        messageCount++;
    }

    // Close socket
    close(sockfd);
    return 0;
}