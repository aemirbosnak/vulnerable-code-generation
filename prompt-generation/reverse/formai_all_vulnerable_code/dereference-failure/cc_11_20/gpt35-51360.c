//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main() {
    int socket_fd, email_count;
    struct hostent *host;
    struct sockaddr_in server_address;
    char *username = "your_username";
    char *password = "your_password";
    char buffer[BUFFER_SIZE];
    ssize_t response_length;

    // Connect to the mail server
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error opening socket");
        exit(1);
    }

    host = gethostbyname("imap.gmail.com");
    if (host == NULL) {
        perror("Error finding host");
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(993);
    memcpy(&server_address.sin_addr, host->h_addr, host->h_length);

    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    // Authenticate with IMAP server
    response_length = read(socket_fd, buffer, BUFFER_SIZE); // Wait for server greeting message
    if (response_length == -1) {
        perror("Error receiving response from server");
        close(socket_fd);
        exit(1);
    }

    buffer[response_length] = '\0';
    printf("%s", buffer); // Print server greeting message

    char login_message[BUFFER_SIZE];
    sprintf(login_message, "a1 LOGIN %s %s\n", username, password);
    write(socket_fd, login_message, strlen(login_message));

    response_length = read(socket_fd, buffer, BUFFER_SIZE);
    if (response_length == -1) {
        perror("Error receiving response from server");
        close(socket_fd);
        exit(1);
    }

    buffer[response_length] = '\0';

    if (strstr(buffer, "OK") == NULL) { // Check if login was successful
        printf("Authentication failed.\n");
        close(socket_fd);
        exit(1);
    } else {
        printf("Login successful.\n");
    }

    // Retrieve list of email messages
    write(socket_fd, "a2 SELECT INBOX\n", strlen("a2 SELECT INBOX\n"));

    response_length = read(socket_fd, buffer, BUFFER_SIZE);
    if (response_length == -1) {
        perror("Error receiving response from server");
        close(socket_fd);
        exit(1);
    }

    buffer[response_length] = '\0';
    printf("%s", buffer); // Print SELECT response

    write(socket_fd, "a3 FETCH 1:* ALL\n", strlen("a3 FETCH 1:* ALL\n"));

    response_length = read(socket_fd, buffer, BUFFER_SIZE);
    if (response_length == -1) {
        perror("Error receiving response from server");
        close(socket_fd);
        exit(1);
    }

    buffer[response_length] = '\0';

    char *start_position = buffer;
    while ((start_position = strstr(start_position, " FLAGS ("))) {
        printf("%s\n", start_position + strlen(" FLAGS ("));
        start_position += strlen(" FLAGS (");
        email_count++;
    }

    printf("Total number of emails: %d\n", email_count);

    // Disconnect from server
    write(socket_fd, "a4 LOGOUT\n", strlen("a4 LOGOUT\n"));

    response_length = read(socket_fd, buffer, BUFFER_SIZE);
    if (response_length == -1) {
        perror("Error receiving response from server");
        close(socket_fd);
        exit(1);
    }

    buffer[response_length] = '\0';
    printf("%s", buffer); // Print server goodbye message

    close(socket_fd);

    return 0;
}