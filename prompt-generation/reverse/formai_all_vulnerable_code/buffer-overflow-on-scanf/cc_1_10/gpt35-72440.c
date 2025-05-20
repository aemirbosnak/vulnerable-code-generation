//FormAI DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>

void printMap(int map[5][5]) {
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            printf("%d ", map[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int map[5][5] = {
        { 2, 4, 1, 5, 3 },
        { 3, 1, 5, 2, 4 },
        { 4, 2, 3, 1, 5 },
        { 5, 3, 2, 4, 1 },
        { 1, 5, 4, 3, 2 }
    };
    
    int row = 0, col = 0, moves = 0;
    
    printf("Welcome to the puzzle game!\n");
    printf("Your goal is to get to the center of the map.\n");
    printf("You are currently at row %d, column %d.\n", row, col);
    
    while (map[row][col] != 3) {
        printMap(map);
        printf("Enter a direction (N/S/E/W): ");
        
        char direction;
        scanf(" %c", &direction);
        
        switch (direction) {
            case 'N':
                if (row > 0) {
                    row--;
                }
                break;
            case 'S':
                if (row < 4) {
                    row++;
                }
                break;
            case 'E':
                if (col < 4) {
                    col++;
                }
                break;
            case 'W':
                if (col > 0) {
                    col--;
                }
                break;
            default:
                printf("Invalid direction. Try again.\n");
                continue;
        }
        
        moves++;
        printf("You are now at row %d, column %d.\n", row, col);
    }
    
    printf("Congratulations! You made it to the center of the map in %d moves!\n", moves);
    
    return 0;
}