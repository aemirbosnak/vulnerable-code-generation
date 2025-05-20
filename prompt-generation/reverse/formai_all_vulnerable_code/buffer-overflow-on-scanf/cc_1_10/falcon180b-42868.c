//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 100

struct player {
    char name[MAX_NAME_LENGTH];
    int score;
    int checksum;
};

int calculate_checksum(char* message) {
    int checksum = 0;
    int i = 0;
    while (message[i]!= '\0') {
        checksum += tolower(message[i]);
        i++;
    }
    return checksum;
}

int main() {
    struct player players[MAX_PLAYERS];
    int num_players = 0;
    char message[MAX_MESSAGE_LENGTH];
    char input[MAX_MESSAGE_LENGTH];
    int i, j, k;

    printf("Welcome to the multiplayer checksum calculator!\n");

    // Add players
    while (num_players < MAX_PLAYERS) {
        printf("Enter player name: ");
        scanf("%s", players[num_players].name);
        strcpy(players[num_players].name, tolower(players[num_players].name));
        num_players++;
    }

    // Main game loop
    while (1) {
        printf("\n");
        for (i = 0; i < num_players; i++) {
            printf("%s's score: %d\n", players[i].name, players[i].score);
        }
        printf("\nEnter message to calculate checksum: ");
        scanf("%s", message);

        // Calculate checksum for each player
        for (i = 0; i < num_players; i++) {
            players[i].checksum = calculate_checksum(message);
        }

        // Display results
        printf("\n");
        for (i = 0; i < num_players; i++) {
            printf("%s's checksum: %d\n", players[i].name, players[i].checksum);
        }

        // Ask if players want to continue
        printf("\nPlay again? (y/n): ");
        scanf(" %c", &input[0]);
        if (tolower(input[0])!= 'y') {
            break;
        }
    }

    return 0;
}