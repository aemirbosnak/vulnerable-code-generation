//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

int main() {
    int direction, x = 0, y = 0;
    int remote[4] = {0};
    int i;

    srand(time(NULL));

    printf("Remote Control Car Simulation\n");
    printf("Press numbers 1, 2, 3, or 4 to control the car:\n1 - Forward\n2 - Backward\n3 - Left\n4 - Right\n");

    while (1) {
        for (i = 0; i < 5; i++) {
            printf("Enter button number: ");
            scanf("%d", &direction);

            switch (direction) {
                case FORWARD:
                    remote[FORWARD]++;
                    x += rand() % 3 - 1;
                    y += rand() % 3 - 1;
                    break;
                case BACKWARD:
                    remote[BACKWARD]++;
                    x -= rand() % 3 - 1;
                    y -= rand() % 3 - 1;
                    break;
                case LEFT:
                    remote[LEFT]++;
                    x -= rand() % 3 - 1;
                    break;
                case RIGHT:
                    remote[RIGHT]++;
                    x += rand() % 3 - 1;
                    break;
                default:
                    printf("Invalid button number. Try again.\n");
                    i--;
                    break;
            }

            printf("Car position: (%d, %d)\n", x, y);
            system("pause");
            system("cls");
        }

        printf("Total Forward button presses: %d\n", remote[FORWARD]);
        printf("Total Backward button presses: %d\n", remote[BACKWARD]);
        printf("Total Left button presses: %d\n", remote[LEFT]);
        printf("Total Right button presses: %d\n", remote[RIGHT]);

        break;
    }

    return 0;
}