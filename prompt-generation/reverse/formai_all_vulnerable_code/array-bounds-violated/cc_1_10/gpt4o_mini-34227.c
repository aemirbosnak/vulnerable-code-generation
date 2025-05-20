//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 4096

// The wasteland was unforgiving, yet echoes of a more connected world survive.
void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0); // POP3 requires a carriage return and new line
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // The server responds, just like the whispers of hope in the desolation.
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        printf("%s", buffer);
        // Glimpses of the past linger in the messages received; perhaps they still matter.
        if (strstr(buffer, "+OK") != NULL) {
            break; // Break if we receive a positive acknowledgment
        }
    }
}

int main() {
    struct sockaddr_in server_addr;
    int sockfd;
    char *server = "YOUR_SERVER"; // The distant, forgotten server
    char *username = "YOUR_USERNAME"; // The username of a survivor
    char *password = "YOUR_PASSWORD"; // Vital secrets to unlock the past

    // In a world where every connection matters, initiate sockets and connect.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket, the connection to the world is lost.");
        return EXIT_FAILURE;
    }

    // Define the server address structure; this is one of the last known beacons.
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    // Convert IPv4 addresses from text to binary form.
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        perror("Invalid address, the coordinates are forever lost.");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Connect to the server, a twitching hope among the ruins.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed, it feels like the end of the line.");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Now the exchange begins, as the remnants of emails still haunt the wires.
    read_response(sockfd); // Read server's greeting

    // Authenticate; the keys to the past must be used wisely.
    char auth_cmd[BUFFER_SIZE];
    snprintf(auth_cmd, sizeof(auth_cmd), "USER %s", username);
    send_command(sockfd, auth_cmd);
    read_response(sockfd);

    snprintf(auth_cmd, sizeof(auth_cmd), "PASS %s", password);
    send_command(sockfd, auth_cmd);
    read_response(sockfd);

    // Ask for the list of messages; this could uncover crucial intelligence.
    send_command(sockfd, "LIST");
    read_response(sockfd);

    // It's time to fetch through the ashes of forgotten letters.
    send_command(sockfd, "RETR 1"); // Fetching the first email; a glimpse into history.
    read_response(sockfd);

    // Cleanup and close the connection, as all good things must.
    send_command(sockfd, "QUIT");
    read_response(sockfd);
    close(sockfd);

    // The echoes of communication fade as the world returns to silence.
    return EXIT_SUCCESS;
}