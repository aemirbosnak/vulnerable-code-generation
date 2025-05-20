//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // check if enough arguments are given
    if (argc < 3) {
        printf("Usage: %s <server> <username>\n", argv[0]);
        return 1;
    }

    // set up socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // set up server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(110); // POP3 default port
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) != 1) {
        printf("Invalid server address\n");
        return 1;
    }

    // connect to server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    // receive greeting message from server
    char buffer[BUFFER_SIZE];
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Error receiving message from server\n");
        return 1;
    }
    printf("%s", buffer);

    // send username to server
    char username[BUFFER_SIZE];
    printf("Enter password for %s: ", argv[2]);
    fgets(username, BUFFER_SIZE, stdin);
    snprintf(buffer, BUFFER_SIZE, "USER %s\n", username);
    if (send(sock, buffer, strlen(buffer), 0) == -1) {
        printf("Error sending message to server\n");
        return 1;
    }

    // receive response from server
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Error receiving message from server\n");
        return 1;
    }
    printf("%s", buffer);

    // send password to server
    char password[BUFFER_SIZE];
    printf("Enter password: ");
    fgets(password, BUFFER_SIZE, stdin);
    snprintf(buffer, BUFFER_SIZE, "PASS %s\n", password);
    if (send(sock, buffer, strlen(buffer), 0) == -1) {
        printf("Error sending message to server\n");
        return 1;
    }

    // receive response from server
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Error receiving message from server\n");
        return 1;
    }
    printf("%s", buffer);

    // send command to list all emails
    snprintf(buffer, BUFFER_SIZE, "LIST\n");
    if (send(sock, buffer, strlen(buffer), 0) == -1) {
        printf("Error sending message to server\n");
        return 1;
    }

    // receive response from server
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Error receiving message from server\n");
        return 1;
    }
    printf("%s", buffer);

    // retrieve each email
    int email_number;
    do {
        printf("Enter email number to retrieve (-1 to exit): ");
        scanf("%d", &email_number);

        // send command to retrieve email
        if (email_number != -1) {
            snprintf(buffer, BUFFER_SIZE, "RETR %d\n", email_number);
            if (send(sock, buffer, strlen(buffer), 0) == -1) {
                printf("Error sending message to server\n");
                return 1;
            }

            // receive response from server
            if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
                printf("Error receiving message from server\n");
                return 1;
            }
            printf("%s", buffer);

            // receive email content from server
            while ((strcmp(buffer, ".\r\n") != 0) && (strcmp(buffer, ".\n") != 0)) {
                if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
                    printf("Error receiving message from server\n");
                    return 1;
                }
                printf("%s", buffer);
            }
        }
    } while (email_number != -1);

    // send command to quit session
    snprintf(buffer, BUFFER_SIZE, "QUIT\n");
    if (send(sock, buffer, strlen(buffer), 0) == -1) {
        printf("Error sending message to server\n");
        return 1;
    }

    // receive response from server
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Error receiving message from server\n");
        return 1;
    }
    printf("%s", buffer);

    // close socket
    close(sock);

    return 0;
}