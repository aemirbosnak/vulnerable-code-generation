//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Romeo and Juliet
/* BuildHTTPClient.c - A program to build an HTTP Client using Romeo and Juliet phrases */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char* argv[]) {
    int s;
    char request[MAX_SIZE], response[MAX_SIZE];
    struct sockaddr_in server;

    // Romeo: Oh, speak again, bright angel!
    printf("Enter server address: ");
    scanf("%s", request);

    // Juliet: What's in a name? That which we call a rose, by any other name would smell as sweet.
    printf("Enter server port: ");
    scanf("%hu", &server.sin_port);

    // Romeo: But, soft! what light through yonder window breaks?
    server.sin_family = AF_INET;

    // Juliet: O Romeo, Romeo! wherefore art thou Romeo?
    inet_pton(AF_INET, request, &server.sin_addr);

    // Romeo: My bounty is as boundless as the sea, my love as deep;
    // The more I give to thee, the more I have, for both are infinite.
    s = socket(AF_INET, SOCK_STREAM, 0);

    // Juliet: Good night, good night! Parting is such sweet sorrow, that I shall say good night till it be morrow.
    if (connect(s, (struct sockaddr*) &server, sizeof(server)) < 0) {
        perror("Unable to connect to server");
        // Romeo: Alas, that love, whose view is muffled still, Should, without eyes, see pathways to his will!
        return 0;
    }

    // Juliet: My only love sprung from my only hate! Too early seen unknown, and known too late!
    strcpy(request, "GET / HTTP/1.1\r\nHost: ");
    strcat(request, inet_ntoa(server.sin_addr));
    strcat(request, "\r\n\r\n");

    // Romeo: Love goes toward love, as schoolboys from their books, But love from love, toward school with heavy looks.
    send(s, request, strlen(request), 0);

    // Juliet: A plague o' both your houses!
    int bytesReceived = 0;
    while ((bytesReceived = recv(s, response, MAX_SIZE, 0)) > 0) {
        response[bytesReceived] = '\0';
        printf("%s", response);
    }

    // Romeo: Thus with a kiss I die.
    close(s);
    return 0;
}