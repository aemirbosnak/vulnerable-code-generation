//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Resolve the server address
    struct sockaddr_in server_addr;
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error resolving server address\n");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Create the socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        close(sock);
        return EXIT_FAILURE;
    }

    // Send the USER command
    char user_cmd[128];
    sprintf(user_cmd, "USER %s\r\n", "username");
    if (send(sock, user_cmd, strlen(user_cmd), 0) == -1) {
        perror("Error sending USER command");
        close(sock);
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    char user_resp[128];
    if (recv(sock, user_resp, sizeof(user_resp), 0) == -1) {
        perror("Error receiving response from server");
        close(sock);
        return EXIT_FAILURE;
    }

    if (strncmp(user_resp, "+OK", 3) != 0) {
        fprintf(stderr, "Error authenticating user: %s\n", user_resp);
        close(sock);
        return EXIT_FAILURE;
    }

    // Send the PASS command
    char pass_cmd[128];
    sprintf(pass_cmd, "PASS %s\r\n", "password");
    if (send(sock, pass_cmd, strlen(pass_cmd), 0) == -1) {
        perror("Error sending PASS command");
        close(sock);
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    char pass_resp[128];
    if (recv(sock, pass_resp, sizeof(pass_resp), 0) == -1) {
        perror("Error receiving response from server");
        close(sock);
        return EXIT_FAILURE;
    }

    if (strncmp(pass_resp, "+OK", 3) != 0) {
        fprintf(stderr, "Error authenticating password: %s\n", pass_resp);
        close(sock);
        return EXIT_FAILURE;
    }

    // Send the STAT command
    char stat_cmd[128];
    sprintf(stat_cmd, "STAT\r\n");
    if (send(sock, stat_cmd, strlen(stat_cmd), 0) == -1) {
        perror("Error sending STAT command");
        close(sock);
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    char stat_resp[128];
    if (recv(sock, stat_resp, sizeof(stat_resp), 0) == -1) {
        perror("Error receiving response from server");
        close(sock);
        return EXIT_FAILURE;
    }

    if (strncmp(stat_resp, "+OK", 3) != 0) {
        fprintf(stderr, "Error getting mailbox statistics: %s\n", stat_resp);
        close(sock);
        return EXIT_FAILURE;
    }

    // Parse the mailbox statistics
    char *num_messages = strtok(stat_resp, " ");
    char *total_size = strtok(NULL, " ");

    // Print the mailbox statistics
    printf("Number of messages: %s\n", num_messages);
    printf("Total size: %s\n", total_size);

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}