//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error resolving hostname: %s\n", hostname);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        return EXIT_FAILURE;
    }

    // Receive the welcome message
    char buf[1024];
    int nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (nbytes == -1) {
        perror("Error receiving welcome message");
        return EXIT_FAILURE;
    }

    printf("%s", buf);

    // Send the USER command
    char username[100];
    printf("Enter your username: ");
    gets(username);

    sprintf(buf, "USER %s\r\n", username);
    nbytes = send(sockfd, buf, strlen(buf), 0);
    if (nbytes == -1) {
        perror("Error sending USER command");
        return EXIT_FAILURE;
    }

    // Receive the response to the USER command
    nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (nbytes == -1) {
        perror("Error receiving response to USER command");
        return EXIT_FAILURE;
    }

    printf("%s", buf);

    // Send the PASS command
    char password[100];
    printf("Enter your password: ");
    gets(password);

    sprintf(buf, "PASS %s\r\n", password);
    nbytes = send(sockfd, buf, strlen(buf), 0);
    if (nbytes == -1) {
        perror("Error sending PASS command");
        return EXIT_FAILURE;
    }

    // Receive the response to the PASS command
    nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (nbytes == -1) {
        perror("Error receiving response to PASS command");
        return EXIT_FAILURE;
    }

    printf("%s", buf);

    // Send the STAT command
    sprintf(buf, "STAT\r\n");
    nbytes = send(sockfd, buf, strlen(buf), 0);
    if (nbytes == -1) {
        perror("Error sending STAT command");
        return EXIT_FAILURE;
    }

    // Receive the response to the STAT command
    nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (nbytes == -1) {
        perror("Error receiving response to STAT command");
        return EXIT_FAILURE;
    }

    printf("%s", buf);

    // Send the LIST command
    sprintf(buf, "LIST\r\n");
    nbytes = send(sockfd, buf, strlen(buf), 0);
    if (nbytes == -1) {
        perror("Error sending LIST command");
        return EXIT_FAILURE;
    }

    // Receive the response to the LIST command
    nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (nbytes == -1) {
        perror("Error receiving response to LIST command");
        return EXIT_FAILURE;
    }

    printf("%s", buf);

    // Send the QUIT command
    sprintf(buf, "QUIT\r\n");
    nbytes = send(sockfd, buf, strlen(buf), 0);
    if (nbytes == -1) {
        perror("Error sending QUIT command");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}