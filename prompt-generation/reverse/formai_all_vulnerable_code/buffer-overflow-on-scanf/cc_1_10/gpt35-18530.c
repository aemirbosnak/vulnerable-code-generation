//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function definitions
void initializeShip(int *curX, int *curY);
void printMap(char map[][10], int curX, int curY, int fuel);
void moveShip(char map[][10], int *curX, int *curY, int dir, int *fuel);

int main() {
    // Initialize variables
    int curX, curY, input;
    int fuel = 20;
    char map[10][10] = {'.'};
    
    // Set seed for randomization
    srand(time(NULL));
    
    // Initialize ship location
    initializeShip(&curX, &curY);
    
    // Print welcome message
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are piloting a small spacecraft on a daring journey through the cosmos.\n");
    printf("Your mission is to collect as many resources as possible and make it back to Earth safely.\n");
    printf("Use the arrow keys to move your ship and collect resources when you land on them.\n");
    printf("You have 20 units of fuel to start and each move consumes 1 unit of fuel.\n");
    printf("Good luck!\n\n");
    
    // Game loop
    while (fuel > 0) {
        // Print map
        printMap(map, curX, curY, fuel);
        
        // Get user input
        printf("Enter 1 to move up, 2 to move right, 3 to move down, or 4 to move left: ");
        scanf("%d", &input);
        
        // Move ship and update fuel
        moveShip(map, &curX, &curY, input, &fuel);
    }
    
    // Print game over message
    printf("\nGame over. You ran out of fuel.\n");
    
    return 0;
}

void initializeShip(int *curX, int *curY) {
    // Randomly generate initial ship location
    *curX = rand() % 10;
    *curY = rand() % 10;
}

void printMap(char map[][10], int curX, int curY, int fuel) {
    // Clear console
    system("clear");
    
    // Print map with current ship location
    printf("Fuel: %d\n", fuel);
    printf("  0123456789\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
        for (int j = 0; j < 10; j++) {
            if (i == curY && j == curX) {
                printf("S");
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

void moveShip(char map[][10], int *curX, int *curY, int dir, int *fuel) {
    // Check for valid input
    if (dir < 1 || dir > 4) {
        printf("Invalid input. Please enter a number between 1 and 4.\n");
        return;
    }
    
    // Update ship location and fuel
    switch (dir) {
        case 1:
            if (*curY - 1 < 0) {
                printf("You cannot move off the map.\n");
                break;
            }
            (*curY)--;
            *fuel -= 1;
            break;
        case 2:
            if (*curX + 1 > 9) {
                printf("You cannot move off the map.\n");
                break;
            }
            (*curX)++;
            *fuel -= 1;
            break;
        case 3:
            if (*curY + 1 > 9) {
                printf("You cannot move off the map.\n");
                break;
            }
            (*curY)++;
            *fuel -= 1;
            break;
        case 4:
            if (*curX - 1 < 0) {
                printf("You cannot move off the map.\n");
                break;
            }
            (*curX)--;
            *fuel -= 1;
            break;
    }
    
    // Check for resource and update map
    if (map[*curY][*curX] == '.') {
        int resource = rand() % 3 + 1;
        switch (resource) {
            case 1:
                printf("You found a chunk of space rock. It is useless.\n");
                break;
            case 2:
                printf("You found a pile of space dust. It is worth 5 credits.\n");
                break;
            case 3:
                printf("You found a rare space crystal. It is worth 10 credits.\n");
                break;
        }
        *fuel -= 1;
        map[*curY][*curX] = 'X';
    }
}