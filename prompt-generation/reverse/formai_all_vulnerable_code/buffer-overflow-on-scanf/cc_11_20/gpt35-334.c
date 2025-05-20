//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to Remote Control Vehicle Simulation!\n");

    int speed = 0;
    int x = 0;
    int y = 0;
    char direction = 'N';

    printf("Enter the starting X-coordinate (0-100): ");
    scanf("%d", &x);
    printf("Enter the starting Y-coordinate (0-100): ");
    scanf("%d", &y);

    while (1) {
        printf("\nCurrent position: (%d,%d)\n", x, y);
        printf("Current speed: %d\n", speed);
        printf("Current direction: %c\n", direction);
        printf("Options:\n");
        printf("1. Change speed\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the new speed (0-10): ");
                scanf("%d", &speed);
                speed = (speed > 10) ? 10 : speed;
                speed = (speed < 0) ? 0 : speed;
                break;
            case 2:
                switch (direction) {
                    case 'N':
                        direction = 'W';
                        break;
                    case 'W':
                        direction = 'S';
                        break;
                    case 'S':
                        direction = 'E';
                        break;
                    case 'E':
                        direction = 'N';
                        break;
                }
                break;
            case 3:
                switch (direction) {
                    case 'N':
                        direction = 'E';
                        break;
                    case 'E':
                        direction = 'S';
                        break;
                    case 'S':
                        direction = 'W';
                        break;
                    case 'W':
                        direction = 'N';
                        break;
                }
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        if (direction == 'N')
            y += speed;
        else if (direction == 'E')
            x += speed;
        else if (direction == 'S')
            y -= speed;
        else if (direction == 'W')
            x -= speed;
    }
    return 0;
}