//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>

// Santa's post office for all the letters :)
#define POP3_PORT "110"

int main(int argc, char *argv[]) {
    // Check if we have the right number of arguments
    if (argc != 3) {
        printf("You're not playing by the rules. Usage: %s <server> <username>\n", argv[0]);
        return 1;
    }

    // Let's get the server information
    struct addrinfo hints, *server_info;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(argv[1], POP3_PORT, &hints, &server_info) != 0) {
        printf("Couldn't find the server. Looks like the elves are on strike again.\n");
        return 2;
    }

    // Now let's make a connection
    int sockfd;
    if ((sockfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol)) == -1) {
        printf("Couldn't create a socket. Maybe the reindeer are tired from all the flying.\n");
        return 3;
    }

    if (connect(sockfd, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        printf("Couldn't connect to the server. Looks like the North Pole is experiencing a blizzard.\n");
        return 4;
    }

    freeaddrinfo(server_info);

    // Let's introduce ourselves to the server
    char username[50];
    snprintf(username, sizeof(username), "USER %s\r\n", argv[2]);
    if (send(sockfd, username, strlen(username), 0) == -1) {
        printf("Couldn't send our username. Maybe the elves are too busy with toy production.\n");
        return 5;
    }

    char server_response[512];
    if (recv(sockfd, server_response, sizeof(server_response), 0) == -1) {
        printf("Couldn't receive the server's response. Looks like the mailboxes are overflowing.\n");
        return 6;
    }

    printf("Server says: %s", server_response);

    // Now let's ask for our letters
    char message[512];
    snprintf(message, sizeof(message), "RETR 1\r\n");
    if (send(sockfd, message, strlen(message), 0) == -1) {
        printf("Couldn't ask for our letters. Maybe the reindeer are delivering the wrong presents.\n");
        return 7;
    }

    if (recv(sockfd, server_response, sizeof(server_response), 0) == -1) {
        printf("Couldn't receive our letters. Looks like the mailman is on vacation.\n");
        return 8;
    }

    printf("Our letter says: %s", server_response);

    // Let's say goodbye to the server
    char quit[50];
    snprintf(quit, sizeof(quit), "QUIT\r\n");
    if (send(sockfd, quit, strlen(quit), 0) == -1) {
        printf("Couldn't say goodbye. Maybe the server is out of cookies.\n");
        return 9;
    }

    if (recv(sockfd, server_response, sizeof(server_response), 0) == -1) {
        printf("Couldn't receive the server's response. Looks like the elves are taking a nap.\n");
        return 10;
    }

    printf("Server says goodbye: %s", server_response);

    // Let's clean up after ourselves
    close(sockfd);

    printf("Merry Christmas!\n");
    return 0;
}