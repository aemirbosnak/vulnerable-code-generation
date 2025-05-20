//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    
    int room[6][6] = { // initialize the haunted house as a 6x6 grid
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    
    int playerRow = 0;
    int playerCol = 0;
    room[playerRow][playerCol] = 1; // initialize player's starting location
    
    int ghostRow = rand() % 6;
    int ghostCol = rand() % 6;
    room[ghostRow][ghostCol] = 2; // initialize ghost's random location
    
    while (1) { // main game loop
        printf("Welcome to the Haunted House Simulator\n");
        printf("You are currently in room (%d, %d)\n", playerRow, playerCol);
        
        if (playerRow == ghostRow && playerCol == ghostCol) {
            printf("You encountered the ghost! GAME OVER\n");
            break;
        } else {
            room[playerRow][playerCol] = 1;
            
            printf("Choose a direction to move (N, E, S, W): ");
            char direction;
            scanf("%c", &direction);
            
            if (direction == 'N') {
                if (playerRow == 0) {
                    printf("You can't move further North\n");
                } else {
                    playerRow--;
                }
            } else if (direction == 'E') {
                if (playerCol == 5) {
                    printf("You can't move further East\n");
                } else {
                    playerCol++;
                }
            } else if (direction == 'S') {
                if (playerRow == 5) {
                    printf("You can't move further South\n");
                } else {
                    playerRow++;
                }
            } else if (direction == 'W') {
                if (playerCol == 0) {
                    printf("You can't move further West\n");
                } else {
                    playerCol--;
                }
            } else {
                printf("Invalid direction, please choose N, E, S, or W\n");
            }
        }
        
        printf("\n");
    }
    
    return 0;
}