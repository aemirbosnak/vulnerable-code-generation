//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {

    // Check if user provided correct number of arguments
    if (argc < 4) {
        printf("Usage: %s [smtp-server] [from-address] [to-address]\n", argv[0]);
        return 1;
    }

    char smtp_server[256], from_address[256], to_address[256];
    strcpy(smtp_server, argv[1]);
    strcpy(from_address, argv[2]);
    strcpy(to_address, argv[3]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Get server information
    struct hostent *server = gethostbyname(smtp_server);
    if (server == NULL) {
        perror("Error getting server information");
        return 1;
    }

    // Setup server address
    struct sockaddr_in server_addr;
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&server_addr.sin_addr.s_addr,
          server->h_length);
    server_addr.sin_port = htons(25);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    char buffer[BUFSIZE];
    int n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        return 1;
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send HELO command
    char helo_command[256];
    sprintf(helo_command, "HELO %s\r\n", smtp_server);
    n = write(sockfd, helo_command, strlen(helo_command));
    if (n < 0) {
        perror("Error writing to socket");
        return 1;
    }

    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        return 1;
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send MAIL FROM command
    char from_command[256];
    sprintf(from_command, "MAIL FROM: <%s>\r\n", from_address);
    n = write(sockfd, from_command, strlen(from_command));
    if (n < 0) {
        perror("Error writing to socket");
        return 1;
    }

    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        return 1;
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send RCPT TO command
    char rcpt_command[256];
    sprintf(rcpt_command, "RCPT TO: <%s>\r\n", to_address);
    n = write(sockfd, rcpt_command, strlen(rcpt_command));
    if (n < 0) {
        perror("Error writing to socket");
        return 1;
    }

    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        return 1;
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send DATA command
    char data_command[256];
    sprintf(data_command, "DATA\r\n");
    n = write(sockfd, data_command, strlen(data_command));
    if (n < 0) {
        perror("Error writing to socket");
        return 1;
    }

    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        return 1;
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send message body
    char message[BUFSIZE];
    printf("Enter message:\n");
    fgets(message, BUFSIZE - 1, stdin);

    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        perror("Error writing to socket");
        return 1;
    }

    // Send end-of-message command
    char end_command[256];
    sprintf(end_command, "\r\n.\r\n");
    n = write(sockfd, end_command, strlen(end_command));
    if (n < 0) {
        perror("Error writing to socket");
        return 1;
    }

    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        return 1;
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send QUIT command
    char quit_command[256];
    sprintf(quit_command, "QUIT\r\n");
    n = write(sockfd, quit_command, strlen(quit_command));
    if (n < 0) {
        perror("Error writing to socket");
        return 1;
    }

    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        return 1;
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}