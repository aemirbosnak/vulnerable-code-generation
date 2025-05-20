//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playerCoords[2] = {3, 3}; // starting coordinates of player
int alienCoords[2] = {0, 0}; // coordinates of alien spaceship
int numAliens = 5; // number of aliens in the game
int turns = 10; // number of turns the player has to defeat the aliens
int playerHealth = 100; // player's starting health

void generateAlienPosition() {
   // Generate random coordinates for the alien spaceship within the game boundaries
    srand(time(NULL));
    alienCoords[0] = rand() % 6;
    alienCoords[1] = rand() % 6;
}

void attackAlien() {
    // If the player and alien are in the same coordinate, reduce number of aliens remaining
    if (playerCoords[0] == alienCoords[0] && playerCoords[1] == alienCoords[1]) {
        numAliens--;
        printf("You have defeated an alien spaceship!\n");
    } else {
        printf("There are no aliens in this coordinate.\n");
    }
}

void printBoard() {
    // Print the game board with player, alien and remaining aliens
    printf("Player Health: %d\n", playerHealth);
    printf("Remaining Aliens: %d\n", numAliens);
    printf("+---+---+---+---+---+---+\n");
    for (int i = 0; i < 6; i++) {
        printf("|");
        for (int j = 0; j < 6; j++) {
            if (i == playerCoords[0] && j == playerCoords[1]) {
                printf(" P |");
            }
            else if (i == alienCoords[0] && j == alienCoords[1]) {
                printf(" A |");
            } else {
                printf("   |");
            }
        }
        printf("\n+---+---+---+---+---+---+\n");
    }
}

int main() {
    printf("Welcome to the Space Adventure Game!\n");
    generateAlienPosition();
    printBoard();
    while (numAliens > 0 && turns > 0 && playerHealth > 0) {
        printf("Please enter your move (W, A, S, D): ");
        char move;
        scanf(" %c", &move);
        switch(move) {
            case 'W':
                if (playerCoords[0] > 0) {
                    playerCoords[0]--;
                }
                break;
            case 'A':
                if (playerCoords[1] > 0) {
                    playerCoords[1]--;
                }
                break;
            case 'S':
                if (playerCoords[0] < 5) {
                    playerCoords[0]++;
                }
                break;
            case 'D':
                if (playerCoords[1] < 5) {
                    playerCoords[1]++;
                }
                break;
            default:
                printf("Invalid move, please try again.\n");
                continue;   
        }
        turns--;
        attackAlien();
        if (numAliens > 0) {
            // Generate new position for alien each turn
            generateAlienPosition();
            printBoard();
        } else {
            printf("Congratulations! You have defeated all aliens and saved the galaxy!\n");
        }
    }
    if (turns <= 0) {
        printf("You have run out of turns. Game over.\n");
    } 
    if (playerHealth <= 0) {
        printf("You have lost all your health. Game over.\n");
    }
    return 0;
}