//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_STRING_LENGTH 100

typedef struct {
    char name[MAX_STRING_LENGTH];
    int score;
} Player;

int main() {
    int numPlayers;
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    Player players[numPlayers];

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
    }

    int currentPlayer = 0;
    char input[MAX_STRING_LENGTH];
    while (1) {
        printf("Player %s's turn.\n", players[currentPlayer].name);
        printf("Enter your move: ");
        fgets(input, MAX_STRING_LENGTH, stdin);

        char *token = strtok(input, " ");
        if (strcmp(token, "quit") == 0) {
            printf("Player %s has quit the game.\n", players[currentPlayer].name);
            return 0;
        }
        else if (strcmp(token, "score") == 0) {
            printf("Player %s's score: %d\n", players[currentPlayer].name, players[currentPlayer].score);
        }
        else {
            int validInput = 1;
            for (int i = 0; i < strlen(token); i++) {
                if (!isalpha(token[i])) {
                    validInput = 0;
                    break;
                }
            }

            if (validInput) {
                int wordLength = strlen(token);
                players[currentPlayer].score += wordLength;
                printf("Player %s's score has increased by %d.\n", players[currentPlayer].name, wordLength);
            }
            else {
                printf("Invalid input. Try again.\n");
            }
        }

        currentPlayer = (currentPlayer + 1) % numPlayers;
    }

    return 0;
}