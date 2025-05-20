//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed random number generator
    int playerX = rand() % 10; // Randomly place player on X-axis
    int playerY = rand() % 10; // Randomly place player on Y-axis
    int treasureX = rand() % 10; // Randomly place treasure on X-axis
    int treasureY = rand() % 10; // Randomly place treasure on Y-axis

    printf("Welcome to the treasure hunt!\n\n");
    printf("You are at location (%d, %d)\n", playerX, playerY);
    printf("The treasure is hidden at location (%d, %d)\n", treasureX, treasureY);
    printf("Use the arrow keys to move around the grid.\n");
    printf("Press 'q' to quit.\n");

    while (1) {
        system("clear"); // Clear the console
        printf("Current location: (%d, %d)\n", playerX, playerY);

        char move;
        scanf("%c", &move);

        if (move == 'q' || move == 'Q') {
            break;
        }

        int newX = playerX;
        int newY = playerY;

        if (move == 'w' || move == 'W') {
            newY--;
        } else if (move =='s' || move == 'S') {
            newY++;
        } else if (move == 'a' || move == 'A') {
            newX--;
        } else if (move == 'd' || move == 'D') {
            newX++;
        }

        if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10) {
            playerX = newX;
            playerY = newY;
        } else {
            printf("Invalid move.\n");
        }

        if (playerX == treasureX && playerY == treasureY) {
            printf("Congratulations! You found the treasure!\n");
            break;
        }
    }

    return 0;
}