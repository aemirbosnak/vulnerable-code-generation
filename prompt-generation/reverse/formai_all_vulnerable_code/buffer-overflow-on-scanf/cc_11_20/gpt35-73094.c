//FormAI DATASET v1.0 Category: Robot movement control ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x = 0, y = 0; // initial position of robot
    srand(time(NULL)); // random seed based on current time
    
    printf("Welcome to Robot Movement Control!\n");
    
    while (1) {
        printf("Current position: (%d, %d)\n", x, y);
        printf("Where would you like to move? (up, down, left, right): ");
        char direction[10];
        scanf("%s", direction);
        
        if (strcmp(direction, "up") == 0) {
            y++;
        }
        else if (strcmp(direction, "down") == 0) {
            y--;
        }
        else if (strcmp(direction, "left") == 0) {
            x--;
        }
        else if (strcmp(direction, "right") == 0) {
            x++;
        }
        else {
            printf("Invalid direction! Try again.\n");
            continue;
        }
        
        if (x == 0 && y == 0) {
            printf("Congratulations! You have returned to the origin.\n");
            break;
        }
        
        int randomNum = rand() % 10;
        
        if (randomNum == 0) {
            printf("Uh-oh! Your robot has malfunctioned and cannot move. Please try a different direction.\n");
            if (strcmp(direction, "up") == 0) {
                y--;
            }
            else if (strcmp(direction, "down") == 0) {
                y++;
            }
            else if (strcmp(direction, "left") == 0) {
                x++;
            }
            else if (strcmp(direction, "right") == 0) {
                x--;
            }
        }
        
        printf("Your robot has moved %s and is now at position (%d, %d)\n", direction, x, y);
    }
    
    return 0;
}