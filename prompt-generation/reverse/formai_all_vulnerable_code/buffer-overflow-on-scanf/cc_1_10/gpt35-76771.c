//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: medieval
#include <stdio.h>

// Function to display the map
void displayMap(int x, int y) {
    printf("You are currently at location (%d,%d).\n", x, y);
    printf("-----------------------------\n");
    printf("|    Castle    |     Forest  |\n");
    printf("-----------------------------\n");
    printf("|   Plains     |   Mountains |\n");
    printf("-----------------------------\n");
}

int main() {
    int xPos = 2;
    int yPos = 2;
    displayMap(xPos, yPos);

    char direction = ' ';
    while (direction != 'Q') {
        printf("Enter direction (N/S/E/W) or Q to quit: ");
        scanf(" %c", &direction);

        switch (direction) {
            case 'N':
                if (yPos > 0) {
                    yPos--;
                } else {
                    printf("You cannot go that way.\n");
                }
                break;
            case 'S':
                if (yPos < 3) {
                    yPos++;
                } else {
                    printf("You cannot go that way.\n");
                }
                break;
            case 'E':
                if (xPos < 3) {
                    xPos++;
                } else {
                    printf("You cannot go that way.\n");
                }
                break;
            case 'W':
                if (xPos > 0) {
                    xPos--;
                } else {
                    printf("You cannot go that way.\n");
                }
                break;
            case 'Q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid direction. Try again.\n");
                break;
        }

        displayMap(xPos, yPos);
    }

    return 0;
}