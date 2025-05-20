//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAXLEN 4096

// Function to send a command and read the response from the server
int send_command(int sock, char *command, char *response_buffer) {
    int count;

    // Send the command to the server
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Failed to send command to server");
        return -1;
    }

    // Read the response from the server
    memset(response_buffer, 0, MAXLEN);
    count = recv(sock, response_buffer, MAXLEN - 1, 0);
    if (count < 0) {
        perror("Failed to receive response from server");
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    struct hostent *host_info;
    char user[MAXLEN], pass[MAXLEN], from[MAXLEN], to[MAXLEN];
    char subject[MAXLEN], message[MAXLEN], response[MAXLEN];

    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <server name> <port number>\n", argv[0]);
        return 0;
    }

    // Create the socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        return -1;
    }

    // Get the host information
    host_info = gethostbyname(argv[1]);
    if (host_info == NULL) {
        perror("Failed to get host information");
        return -1;
    }

    // Set up the server address structure
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr = *((struct in_addr *) host_info->h_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to connect to server");
        return -1;
    }

    // Get user credentials
    printf("Enter username: ");
    if (fgets(user, MAXLEN, stdin) == NULL) {
        perror("Failed to get username");
        return -1;
    }
    user[strcspn(user, "\n")] = '\0';

    printf("Enter password: ");
    if (fgets(pass, MAXLEN, stdin) == NULL) {
        perror("Failed to get password");
        return -1;
    }
    pass[strcspn(pass, "\n")] = '\0';

    // Send login command and authenticate the user
    if (send_command(sock, "AUTH LOGIN\n", response) == -1) {
        return -1;
    }
    printf("%s", response);

    // Send username and password to server
    memset(response, 0, MAXLEN);
    if (send_command(sock, user, response) == -1) {
        return -1;
    }
    printf("%s", response);

    memset(response, 0, MAXLEN);
    if (send_command(sock, pass, response) == -1) {
        return -1;
    }
    printf("%s", response);

    // Get message details
    printf("From: ");
    if (fgets(from, MAXLEN, stdin) == NULL) {
        perror("Failed to get 'From' address");
        return -1;
    }
    from[strcspn(from, "\n")] = '\0';

    printf("To: ");
    if (fgets(to, MAXLEN, stdin) == NULL) {
        perror("Failed to get 'To' address");
        return -1;
    }
    to[strcspn(to, "\n")] = '\0';

    printf("Subject: ");
    if (fgets(subject, MAXLEN, stdin) == NULL) {
        perror("Failed to get message subject");
        return -1;
    }
    subject[strcspn(subject, "\n")] = '\0';

    printf("Message: ");
    if (fgets(message, MAXLEN, stdin) == NULL) {
        perror("Failed to get message body");
        return -1;
    }
    message[strcspn(message, "\n")] = '\0';

    // Send message details to server
    if (send_command(sock, "MAIL FROM: <", response) == -1) {
        return -1;
    }
    if (send_command(sock, from, response) == -1) {
        return -1;
    }
    if (send_command(sock, ">\n", response) == -1) {
        return -1;
    }

    if (send_command(sock, "RCPT TO: <", response) == -1) {
        return -1;
    }
    if (send_command(sock, to, response) == -1) {
        return -1;
    }
    if (send_command(sock, ">\n", response) == -1) {
        return -1;
    }

    if (send_command(sock, "DATA\n", response) == -1) {
        return -1;
    }
    printf("%s", response);

    if (send_command(sock, "Subject: ", response) == -1) {
        return -1;
    }
    if (send_command(sock, subject, response) == -1) {
        return -1;
    }
    if (send_command(sock, "\n", response) == -1) {
        return -1;
    }

    if (send_command(sock, message, response) == -1) {
        return -1;
    }
    if (send_command(sock, ".\n", response) == -1) {
        return -1;
    }

    if (send_command(sock, "QUIT\n", response) == -1) {
        return -1;
    }
    printf("%s", response);

    // Close the socket
    close(sock);

    return 0;
}