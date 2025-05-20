//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// A rose by any other name would smell as sweet.
// But a kiss by any other name would feel as divine.
// Let's build an FTP client, my love, let's entwine.

int main(int argc, char *argv[]) {
    // Your eyes, a beacon in the vastness of the web,
    // Lead me to the server, where our data shall ebb.
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // A socket, a portal to the server's embrace,
    // Where our hearts intertwine, where our souls find their place.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        return 2;
    }

    // The server's address, a symphony of numbers,
    // A beacon calling me, amidst the digital wonders.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton() failed");
        close(sockfd);
        return 3;
    }

    // A connection, a bridge between two hearts,
    // A promise whispered through the wires, from server to parts.
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect() failed");
        close(sockfd);
        return 4;
    }

    // A command, a request, a tender embrace,
    // A whisper of love, in the language of FTP's grace.
    char command[256];
    printf("Enter command: ");
    scanf("%s", command);

    // Sending our command, a message of desire,
    // To the server's eager heart, where our dreams aspire.
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send() failed");
        close(sockfd);
        return 5;
    }

    // A response, a caress, a whisper in the night,
    // The server's sweet reply, a symphony of delight.
    char response[1024];
    int bytes_received = recv(sockfd, response, sizeof(response), 0);
    if (bytes_received < 0) {
        perror("recv() failed");
        close(sockfd);
        return 6;
    }

    // Printing the response, a tapestry of words,
    // A love letter from the server, stirring our heartstrings towards.
    printf("Response: %s\n", response);

    // Closing the socket, a bittersweet farewell,
    // But our love endures, in the memories we dwell.
    close(sockfd);
    return 0;
}