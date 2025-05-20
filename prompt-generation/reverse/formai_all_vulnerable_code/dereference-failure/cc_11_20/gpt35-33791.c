//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_LINE 1024 // Maximum size of a single line

int main(int argc, char *argv[]) {
    char *host = "example.com"; // Server name
    char *user = "username"; // Username
    char *pass = "password"; // Password
    
    // Open a socket for the server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Could not create socket\n");
        return 1;
    }

    // Resolve the server IP address
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        printf("Could not resolve hostname\n");
        return 1;
    }

    // Set up the server address structure
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    memcpy(&serveraddr.sin_addr.s_addr, server->h_addr, server->h_length);
    serveraddr.sin_port = htons(110);

    // Attempt to connect to the server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Could not connect to server\n");
        return 1;
    }

    // Receive the welcome message from the server
    char response[MAX_LINE];
    if (recv(sockfd, response, MAX_LINE, 0) == -1) {
        printf("Could not receive message from server\n");
        return 1;
    }
    printf("%s", response);

    // Send the login credentials to the server
    char message[MAX_LINE];
    sprintf(message, "USER %s\r\n", user);
    send(sockfd, message, strlen(message), 0);
    if (recv(sockfd, response, MAX_LINE, 0) == -1) {
        printf("Could not receive message from server\n");
        return 1;
    }
    printf("%s", response);

    sprintf(message, "PASS %s\r\n", pass);
    send(sockfd, message, strlen(message), 0);
    if (recv(sockfd, response, MAX_LINE, 0) == -1) {
        printf("Could not receive message from server\n");
        return 1;
    }
    printf("%s", response);

    // Request a list of messages from the server
    sprintf(message, "LIST\r\n");
    send(sockfd, message, strlen(message), 0);
    if (recv(sockfd, response, MAX_LINE, 0) == -1) {
        printf("Could not receive message from server\n");
        return 1;
    }
    printf("%s", response);

    // Read through each message
    int num_messages;
    scanf(response, "+OK %d", &num_messages);
    for (int i = 1; i <= num_messages; i++) {
        sprintf(message, "RETR %d\r\n", i);
        send(sockfd, message, strlen(message), 0);
        if (recv(sockfd, response, MAX_LINE, 0) == -1) {
            printf("Could not receive message from server\n");
            return 1;
        }
        printf("%s", response);

        // Parse the message for useful information
        char *token = strtok(response, "\n");
        while (token != NULL) {
            if (strncmp(token, "From:", 5) == 0 || strncmp(token, "Subject:", 8) == 0) {
                printf("%s\n", token);
            }
            token = strtok(NULL, "\n");
        }
    }

    // Logout of the server
    sprintf(message, "QUIT\r\n");
    send(sockfd, message, strlen(message), 0);
    if (recv(sockfd, response, MAX_LINE, 0) == -1) {
        printf("Could not receive message from server\n");
        return 1;
    }
    printf("%s", response);

    close(sockfd); // Close the socket and exit
    return 0;
}