//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// A whimsical tale of a Chat Server

// A realm of connected souls, where thoughts traverse the digital ether
int main() {

    // Behold, the guardians of communication
    int sfd, cfd, port, opt;
    struct sockaddr_in server, client;

    // A quest for a mystical port
    printf("Hark! What port shall we open? ");
    scanf("%d", &port);

    // Weave the server's ethereal abode
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0) {
        perror("Alack, the server's abode could not be conjured");
        return 1;
    }

    // Set socket options to prevent "Address already in use" errors
    opt = 1;
    if (setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("Alas, options could not be set");
        return 1;
    }

    // Bind the server's abode to the chosen port
    memset(&server, '\0', sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(port);
    if (bind(sfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Woe! The server's abode could not be bound");
        return 1;
    }

    // Prepare the server to receive visitors
    if (listen(sfd, 5) < 0) {
        perror("Alas, the server could not prepare to receive visitors");
        return 1;
    }

    printf("Huzzah! The server awaits its guests at port %d.\n", port);

    // A never-ending loop, a realm of eternal communication
    while (true) {
        // A new visitor approaches, and we eagerly accept their presence
        socklen_t clilen = sizeof(client);
        cfd = accept(sfd, (struct sockaddr*)&client, &clilen);
        if (cfd < 0) {
            perror("Alas, we could not receive the visitor");
            continue;
        }

        // Exchange pleasantries, for language connects souls
        char welcome[] = "Welcome, weary traveler! What words do you bring?";
        write(cfd, welcome, strlen(welcome));

        // Prepare parchment and quill to receive the visitor's tale
        char buffer[1024] = {0};

        // Listen intently as the visitor shares their story
        ssize_t nbytes;
        while ((nbytes = read(cfd, buffer, sizeof(buffer))) > 0) {
            buffer[nbytes] = '\0';

            // Respond to the visitor's tale with understanding and wisdom
            char response[1024];
            sprintf(response, "I hear your tale, wise traveler. Your words have touched my ethereal realm.");
            write(cfd, response, strlen(response));
        }

        // The visitor's tale has ended, and we bid them farewell
        close(cfd);
    }

    // The server's journey has ended, may it rest in digital tranquility
    close(sfd);
    return 0;
}