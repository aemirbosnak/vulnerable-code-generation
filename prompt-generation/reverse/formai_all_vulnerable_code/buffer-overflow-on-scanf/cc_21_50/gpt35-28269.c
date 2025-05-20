//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    char house[ROWS][COLS];

    // Populate the house with empty spaces
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            house[i][j] = ' ';
        }
    }

    // Add furniture to the house
    house[0][1] = 'C'; // Couch
    house[2][2] = 'T'; // Table
    house[3][6] = 'B'; // Bookshelf
    house[1][8] = 'P'; // Piano
    house[9][3] = 'B'; // Bed

    // Add ghosts to the house
    srand(time(NULL)); // Seed the random number generator
    int numGhosts = rand() % 5 + 1; // Generate a random number of ghosts between 1 and 5
    char ghost = 'G';
    for(int i = 0; i < numGhosts; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if(house[row][col] == ' ') { // If the space is empty, add a ghost
            house[row][col] = ghost;
        }
        else { // If the space is not empty, try again
            i--;
        }
    }

    // Print the house
    printf("Here is the layout of the house:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("|%c", house[i][j]);
        }
        printf("|\n");
    }

    // Start the game
    int playerRow = ROWS - 1;
    int playerCol = 0;
    char direction;
    while(house[playerRow][playerCol] != 'G' && (playerRow != 0 || playerCol != COLS - 1)) { // While the player has not reached the goal or encountered a ghost
        printf("Enter a direction (up(u), down(d), left(l), right(r)): ");
        scanf(" %c", &direction);
        printf("\n");

        switch(direction) { // Move the player in the chosen direction
            case 'u': if(playerRow > 0) playerRow--; break;
            case 'd': if(playerRow < ROWS - 1) playerRow++; break;
            case 'l': if(playerCol > 0) playerCol--; break;
            case 'r': if(playerCol < COLS - 1) playerCol++; break;
            default: printf("Invalid direction. Try again.\n");
        }

        // Print the updated house with the player's location
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(i == playerRow && j == playerCol) {
                    printf("|%c*", house[i][j]);
                }
                else {
                    printf("|%c", house[i][j]);
                }
            }
            printf("|\n");
        }
    }

    if(house[playerRow][playerCol] == 'G') { // If the player encounters a ghost
        printf("You have encountered a ghost!\n");
    }
    else { // If the player reaches the goal
        printf("Congratulations! You have reached the goal!\n");
    }

    return 0;
}