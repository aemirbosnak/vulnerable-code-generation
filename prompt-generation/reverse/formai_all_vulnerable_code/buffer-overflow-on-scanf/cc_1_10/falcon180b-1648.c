//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_GAME_TIME 60

typedef struct {
    char name[20];
    int score;
} Player;

Player players[MAX_PLAYERS];
int numPlayers;

void initializeGame() {
    printf("Welcome to the Space Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", &players[0].name);
    numPlayers = 1;
    srand(time(NULL));
    int i;
    for (i = 1; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Falcon");
        players[i].score = 0;
    }
}

void playGame() {
    int i, j;
    char choice;
    int gameTime = MAX_GAME_TIME;

    while (gameTime > 0 && numPlayers > 0) {
        printf("\n%s, it's your turn.\n", players[0].name);
        printf("What would you like to do?\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Shoot\n");
        printf("5. Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (players[0].score < 100) {
                    printf("You moved forward and gained 10 points!\n");
                    players[0].score += 10;
                } else {
                    printf("You moved forward.\n");
                }
                break;
            case '2':
                printf("You turned left.\n");
                break;
            case '3':
                printf("You turned right.\n");
                break;
            case '4':
                printf("You shot and destroyed an enemy ship!\n");
                if (players[0].score < 100) {
                    players[0].score += 20;
                }
                break;
            case '5':
                printf("You quit the game.\n");
                numPlayers--;
                break;
            default:
                printf("Invalid choice.\n");
        }

        if (gameTime == 0) {
            printf("\nGame over! You scored %d points.\n", players[0].score);
            break;
        }

        gameTime--;
    }

    printf("\nThanks for playing!\n");
}

int main() {
    initializeGame();
    playGame();
    return 0;
}