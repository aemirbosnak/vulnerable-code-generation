//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the C Drone Remote Control program!\n\n");

    int altitude = 0;
    int direction = 0;
    int speed = 0;
    int battery = 100;
    int distance = 0;

    while (battery > 0) {
        printf("What would you like to do?\n");
        printf("1. Increase altitude\n");
        printf("2. Decrease altitude\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Increase speed\n");
        printf("6. Decrease speed\n");
        printf("7. Check battery life\n");
        printf("8. Check distance traveled\n");
        printf("9. Land drone\n");
        printf("Enter a number to select an action: ");

        int action;
        scanf("%d", &action);

        switch (action) {
            case 1:
                altitude++;
                printf("Increased altitude to %d.\n", altitude);
                break;
            case 2:
                altitude--;
                printf("Decreased altitude to %d.\n", altitude);
                break;
            case 3:
                direction--;
                printf("Turned left. Direction is now %d.\n", direction);
                break;
            case 4:
                direction++;
                printf("Turned right. Direction is now %d.\n", direction);
                break;
            case 5:
                speed++;
                printf("Increased speed to %d.\n", speed);
                break;
            case 6:
                speed--;
                printf("Decreased speed to %d.\n", speed);
                break;
            case 7:
                printf("Battery life is %d%%.\n", battery);
                break;
            case 8:
                printf("Distance traveled is %d meters.\n", distance);
                break;
            case 9:
                printf("Landing drone...\n");
                printf("Drone has landed safely. Thank you for using the C Drone Remote Control program!\n");
                exit(0);
            default:
                printf("Invalid input. Please enter a number between 1-9.\n");
        }

        battery -= 5;
        distance += speed;
        printf("\n");
    }

    printf("Battery life is too low. Please charge drone and try again.\n");
    
    return 0;
}