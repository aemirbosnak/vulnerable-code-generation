//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_SIZE 1024

int main() {
    char recipient[100] = "recipient@example.com";
    char message[MAX_MESSAGE_SIZE] = "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: A Romantic Message\r\n\r\nHello, my love. I just wanted to tell you how much I care about you. You bring joy to my life and make me feel complete. I love you more than words can express. \r\n\r\nWith all my love,\r\nSender\r\n";

    char command[100] = "HELO example.com";
    char response[100];
    int response_len;

    // Send HELO command
    printf("Sending HELO command...\r\n");
    printf("HELO %s\r\n", command);
    fflush(stdout);
    response_len = recv(0, response, 100, 0);
    response[response_len] = '\0';

    // Check if server responds with OK
    if (strcmp(response, "250 OK") == 0) {
        printf("Server response: %s\r\n", response);
    } else {
        printf("Error: Server did not respond with OK\r\n");
        return 1;
    }

    // Send MAIL FROM command
    printf("Sending MAIL FROM command...\r\n");
    printf("MAIL FROM: %s\r\n", command);
    fflush(stdout);
    response_len = recv(0, response, 100, 0);
    response[response_len] = '\0';

    // Check if server responds with OK
    if (strcmp(response, "250 OK") == 0) {
        printf("Server response: %s\r\n", response);
    } else {
        printf("Error: Server did not respond with OK\r\n");
        return 1;
    }

    // Send RCPT TO command
    printf("Sending RCPT TO command...\r\n");
    printf("RCPT TO: %s\r\n", command);
    fflush(stdout);
    response_len = recv(0, response, 100, 0);
    response[response_len] = '\0';

    // Check if server responds with OK
    if (strcmp(response, "250 OK") == 0) {
        printf("Server response: %s\r\n", response);
    } else {
        printf("Error: Server did not respond with OK\r\n");
        return 1;
    }

    // Send DATA command
    printf("Sending DATA command...\r\n");
    printf("DATA\r\n");
    fflush(stdout);
    response_len = recv(0, response, 100, 0);
    response[response_len] = '\0';

    // Check if server responds with OK
    if (strcmp(response, "354 OK") == 0) {
        printf("Server response: %s\r\n", response);
    } else {
        printf("Error: Server did not respond with OK\r\n");
        return 1;
    }

    // Send message
    printf("Sending message...\r\n");
    printf("%s\r\n", message);
    fflush(stdout);
    response_len = recv(0, response, 100, 0);
    response[response_len] = '\0';

    // Check if server responds with OK
    if (strcmp(response, "250 OK") == 0) {
        printf("Server response: %s\r\n", response);
    } else {
        printf("Error: Server did not respond with OK\r\n");
        return 1;
    }

    // Send QUIT command
    printf("Sending QUIT command...\r\n");
    printf("QUIT\r\n");
    fflush(stdout);
    response_len = recv(0, response, 100, 0);
    response[response_len] = '\0';

    // Check if server responds with OK
    if (strcmp(response, "221 OK") == 0) {
        printf("Server response: %s\r\n", response);
    } else {
        printf("Error: Server did not respond with OK\r\n");
        return 1;
    }

    return 0;
}