//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *server = argv[1];
    char *username = argv[2];

    // Get the IP address of the POP3 server
    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "Error resolving hostname %s\n", server);
        return EXIT_FAILURE;
    }

    // Create a socket to connect to the POP3 server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Connect to the POP3 server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(POP3_PORT);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error connecting to server");
        return EXIT_FAILURE;
    }

    // Send the USER command to the POP3 server
    char buf[1024];
    sprintf(buf, "USER %s\r\n", username);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error sending USER command");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        perror("Error receiving response from server");
        return EXIT_FAILURE;
    }

    // Check the response from the POP3 server
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the PASS command to the POP3 server
    sprintf(buf, "PASS ******\r\n");
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error sending PASS command");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        perror("Error receiving response from server");
        return EXIT_FAILURE;
    }

    // Check the response from the POP3 server
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the LIST command to the POP3 server
    sprintf(buf, "LIST\r\n");
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error sending LIST command");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server
    int num_messages = 0;
    while (recv(sock, buf, sizeof(buf), 0) > 0) {
        if (strncmp(buf, "+OK", 3) == 0) {
            break;
        }

        if (strncmp(buf, ".", 1) == 0) {
            num_messages++;
        }
    }

    // Print the number of messages
    printf("Number of messages: %d\n", num_messages);

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}