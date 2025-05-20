//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int health = 100, dronePosition = 0, xPos = 0, yPos = 0;
    char command[25];
    printf("Welcome to the Medieval Remote Control!\n");
    printf("Your drone is ready for battle!\n");
    printf("Enter a command (up, down, left, right, fire, status, end):\n");

    while(health > 0) {
        scanf("%s", command);
        if(strcmp(command, "up") == 0) {
            dronePosition += rand() % 5 + 1;
            printf("The drone went up %d meters!\n", dronePosition);
        }
        else if(strcmp(command, "down") == 0) {
            dronePosition -= rand() % 5 + 1;
            if(dronePosition < 0) {
                dronePosition = 0;
            }
            printf("The drone went down %d meters!\n", dronePosition);
        }
        else if(strcmp(command, "left") == 0) {
            xPos -= rand() % 5 + 1;
            if(xPos < 0) {
                xPos = 0;
            }
            printf("The drone moved left %d meters!\n", xPos);
        }
        else if(strcmp(command, "right") == 0) {
            xPos += rand() % 5 + 1;
            printf("The drone moved right %d meters!\n", xPos);
        }
        else if(strcmp(command, "fire") == 0) {
            int hit = rand() % 2;
            if(hit == 1) {
                printf("You hit the enemy! Great job!\n");
                health -= rand() % 25 + 1;
            }
            else {
                printf("Your aim was off, better luck next time!\n");
            }
        }
        else if(strcmp(command, "status") == 0) {
            printf("Drone Position: %d meters above ground, X Position: %d meters from origin\n", dronePosition, xPos);
        }
        else if(strcmp(command, "end") == 0) {
            printf("Thanks for using Medieval Remote Control. See you next time!\n");
            break;
        }
        else {
            printf("Invalid command! Please try again.\n");
        }
    }

    if(health <= 0) {
        printf("Your drone was destroyed. Better luck next time!");
    }

    return 0;
}