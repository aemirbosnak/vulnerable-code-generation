//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: minimalist
#include <stdio.h>

#define MAP_SIZE 10

void initializeMap(char map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '.';
        }
    }
}

void displayMap(char map[MAP_SIZE][MAP_SIZE], int userX, int userY) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == userX && j == userY) {
                printf("U ");
            } else {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
}

void getDirection(int userX, int userY, int destX, int destY) {
    if (userX < destX) {
        printf("Move Down\n");
    } else if (userX > destX) {
        printf("Move Up\n");
    }
    if (userY < destY) {
        printf("Move Right\n");
    } else if (userY > destY) {
        printf("Move Left\n");
    }
}

int main() {
    char map[MAP_SIZE][MAP_SIZE];
    int userX = 0, userY = 0;
    int destX, destY;

    initializeMap(map);
    
    printf("Enter the destination coordinates (x y): ");
    scanf("%d %d", &destX, &destY);
    
    if (destX < 0 || destX >= MAP_SIZE || destY < 0 || destY >= MAP_SIZE) {
        printf("Invalid coordinates. Please enter values between 0 and %d for both x and y.\n", MAP_SIZE-1);
        return 1;
    }

    while (userX != destX || userY != destY) {
        displayMap(map, userX, userY);
        getDirection(userX, userY, destX, destY);

        // Update position
        if (userX < destX) userX++;
        else if (userX > destX) userX--;
        if (userY < destY) userY++;
        else if (userY > destY) userY--;
    }

    printf("You have arrived at your destination (%d, %d)!\n", destX, destY);
    return 0;
}