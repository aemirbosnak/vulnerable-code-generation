//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 256

void kingdom_boundaries() {
    printf("===================================\n");
    printf("  Welcome to the Knights' Duel!\n");
    printf("         The Royal Castle\n");
    printf("===================================\n");
}

void knight_challenge(char *knight_name) {
    printf("\n%s the Brave challenges thee to a duel!\n", knight_name);
    printf("Thou art summoned to duel in the honor of the Kingdom!\n");
}

void knight_victory(char *winner) {
    printf("\nHark! Victory belongs to %s!\n", winner);
    printf("The crowd roars in approval of thy prowess!\n");
}

void knight_defeat(char *loser) {
    printf("\nAlack! %s hath been vanquished!\n", loser);
    printf("Mayest thou train well for the next battle!\n");
}

int main() {
    kingdom_boundaries();

    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char knight_name[50];

    printf("Enter thy name, noble knight: ");
    scanf("%s", knight_name);
    
    // Setting up the castle for the duel
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Alas! The socket creation hath failed");
        exit(EXIT_FAILURE);
    }

    // Filling the address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Binding the socket to the castle
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Oh no! Binding hath failed!");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Prepare to listen for challengers
    listen(sockfd, 1);
    printf("The castle hath opened its gates for challengers...\n");

    int newsockfd;
    socklen_t addrlen = sizeof(serv_addr);

    // Await challengers
    newsockfd = accept(sockfd, (struct sockaddr *)&serv_addr, &addrlen);
    if (newsockfd < 0) {
        perror("The challenge hath encountered an error!");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Duel protocol begins
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        
        // Receive duel challenges
        int n = read(newsockfd, buffer, BUFFER_SIZE - 1);
        if (n <= 0) break;

        // Announce the challenge
        printf("\nKnight enters the battlefield! Message: %s\n", buffer);
        knight_challenge(knight_name);

        // Victory or defeat
        if (rand() % 2) {
            knight_victory(knight_name);
            send(newsockfd, "Victory!", strlen("Victory!") + 1, 0);
        } else {
            knight_defeat(knight_name);
            send(newsockfd, "Defeated!", strlen("Defeated!") + 1, 0);
        }
    }

    // Cleanup after duel
    close(newsockfd);
    close(sockfd);
    return 0;
}