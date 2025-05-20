//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define MAX_USERNAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 100
#define MAX_QUERY_LENGTH 1000

int main(int argc, char* argv[]) {

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char query[MAX_QUERY_LENGTH];
    char buffer[BUF_SIZE];
    char *imap_server;
    char *imap_username;
    char *imap_password;

    // Get the server address and port number from command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s server_address port_number\n", argv[0]);
        exit(1);
    }

    imap_server = argv[1];
    portno = atoi(argv[2]);

    // Create a socket for the IMAP client
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Get the server hostname and IP address
    server = gethostbyname(imap_server);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host '%s'\n", imap_server);
        exit(1);
    }

    // Setup the server address for communication
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to IMAP server");
        exit(1);
    }

    // Authenticate the IMAP client using the provided username and password
    printf("Enter your IMAP username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    printf("Enter your IMAP password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    imap_username = strtok(username, "\n");
    imap_password = strtok(password, "\n");

    sprintf(query, "LOGIN %s %s\r\n", imap_username, imap_password);

    n = write(sockfd, query, strlen(query));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    // Get the list of available mailboxes for the authenticated IMAP account
    n = write(sockfd, "LIST \"\" *\r\n", strlen("LIST \"\" *\r\n"));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    // Select a mailbox to work with
    printf("Enter the name of the mailbox you want to work with: ");
    bzero(query, MAX_QUERY_LENGTH);
    fgets(query, MAX_QUERY_LENGTH, stdin);

    sprintf(buffer, "SELECT \"%s\"\r\n", query);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    // Get the number of messages in the selected mailbox
    n = write(sockfd, "STATUS \"\" (MESSAGES)\r\n", strlen("STATUS \"\" (MESSAGES)\r\n"));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    // Get the list of available flags for messages in the selected mailbox
    n = write(sockfd, "LIST \"\" *\r\n", strlen("LIST \"\" *\r\n"));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    // Logout from the IMAP account and close the socket
    n = write(sockfd, "LOGOUT\r\n", strlen("LOGOUT\r\n"));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    close(sockfd);

    return 0;
}