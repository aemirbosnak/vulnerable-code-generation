//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

// Our trusty intrusion detection system
int main() {
    // Let's set up our listening post
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    // What port shall we listen on?
    printf("Enter port number: ");
    scanf("%d", &portno);

    // Create a socket, if we can
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Oops, couldn't create socket!\n");
        return 1;
    }

    // Set up our server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind our socket to the address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Oops, couldn't bind socket!\n");
        return 1;
    }

    // Ready to listen for connections
    listen(sockfd, 5);

    // Loop forever, waiting for connections
    while (1) {
        clilen = sizeof(cli_addr);

        // Accept a connection
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            printf("Oops, couldn't accept connection!\n");
            continue;
        }

        // Get the time of day
        time_t now = time(NULL);
        struct tm *tm = localtime(&now);

        // Log the connection
        printf("%s - Connection from %s on port %d\n", asctime(tm), inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // Read the data from the client
        memset(buffer, 0, sizeof(buffer));
        int n = read(newsockfd, buffer, sizeof(buffer));
        if (n < 0) {
            printf("Oops, couldn't read from socket!\n");
            continue;
        }

        // Check for suspicious activity
        if (strstr(buffer, "DROP TABLE") != NULL) {
            printf("Alert! Suspicious activity detected: %s\n", buffer);
        } else if (strstr(buffer, "DELETE FROM") != NULL) {
            printf("Alert! Suspicious activity detected: %s\n", buffer);
        } else if (strstr(buffer, "UPDATE") != NULL) {
            printf("Alert! Suspicious activity detected: %s\n", buffer);
        } else if (strstr(buffer, "INSERT INTO") != NULL) {
            printf("Alert! Suspicious activity detected: %s\n", buffer);
        } else {
            printf("All clear!\n");
        }

        // Close the connection
        close(newsockfd);
    }

    // Close the listening socket
    close(sockfd);

    return 0;
}