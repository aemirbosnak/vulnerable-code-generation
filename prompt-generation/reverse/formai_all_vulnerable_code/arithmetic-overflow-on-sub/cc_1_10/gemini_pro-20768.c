//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
// Welcome to our intrusion detection system!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

// Our trusty alarm function
void alarm(char *message) {
    fprintf(stderr, "INTRUSION DETECTED: %s\n", message);
    exit(1);
}

// The main event
int main() {
    // Let's set up our socket
    int sockfd;
    struct sockaddr_in servaddr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Bind our socket to the network
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(80);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Time to listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Let's get ready to receive some data
    int connfd;
    struct sockaddr_in cliaddr;
    socklen_t len;
    char buffer[1024];
    time_t last_activity;

    // The main loop
    while (1) {
        // Accept an incoming connection
        len = sizeof(cliaddr);
        if ((connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len)) < 0) {
            perror("accept");
            exit(1);
        }

        // Set a timer for this connection
        last_activity = time(NULL);

        // Read data from the client
        while (1) {
            // Check if the client has been inactive for too long
            if (time(NULL) - last_activity > 300) {
                alarm("Client inactivity");
            }

            // Read data from the client
            int n = read(connfd, buffer, sizeof(buffer));

            // Handle any errors
            if (n < 0) {
                perror("read");
                exit(1);
            } else if (n == 0) {
                // Client closed the connection
                break;
            }

            // Update the timer
            last_activity = time(NULL);

            // Check for suspicious patterns
            if (strstr(buffer, "malicious_payload")) {
                alarm("Malicious payload detected");
            } else if (strstr(buffer, "unauthorized_access")) {
                alarm("Unauthorized access attempt");
            }

            // Write data back to the client
            if (write(connfd, buffer, n) < 0) {
                perror("write");
                exit(1);
            }
        }

        // Close the connection
        close(connfd);
    }

    // We'll never get here, but just in case...
    close(sockfd);
    return 0;
}