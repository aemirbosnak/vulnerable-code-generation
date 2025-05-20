//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed for random numbers
    int xPos = 0, yPos = 0; // starting position of the car
    int destX = rand() % 100, destY = rand() % 100; // random destination coordinates
    int choice;
    printf("Welcome to the GPS Navigation Program!\n");
    printf("Your current position is (%d, %d) and your destination is (%d, %d)\n", xPos, yPos, destX, destY);
    printf("\n");
    do {
        printf("Choose an action:\n");
        printf("1. Move North\n");
        printf("2. Move South\n");
        printf("3. Move East\n");
        printf("4. Move West\n");
        printf("5. Check Position\n");
        printf("6. Quit Program\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                yPos++;
                break;
            case 2:
                yPos--;
                break;
            case 3:
                xPos++;
                break;
            case 4:
                xPos--;
                break;
            case 5:
                printf("Your current position is (%d, %d)\n", xPos, yPos);
                printf("\n");
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Try again.\n");
                printf("\n");
                break;
        }
        // check if destination has been reached
        if(xPos == destX && yPos == destY) {
            printf("Congratulations! You have reached your destination!\n");
            printf("\n");
            destX = rand() % 100;
            destY = rand() % 100;
            printf("New destination: (%d, %d)\n", destX, destY);
            xPos = 0;
            yPos = 0;
        }
    } while(1);
    return 0;
}