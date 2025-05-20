//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>

int main() {
    int fuel = 1000;
    int x = 0;
    int y = 0;

    while (fuel > 0) {
        printf("You are in space! What do you want to do? (1) Move up, (2) Move down, (3) Move left, (4) Move right, (5) Check fuel, (6) Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                y++;
                if (y == 0) {
                    fuel--;
                    printf("You have hit the top of space! You ran out of fuel. Game over.\n");
                    break;
                }
                else {
                    printf("You moved up.\n");
                }
                break;
            case 2:
                y--;
                if (y == -1) {
                    fuel--;
                    printf("You have hit the bottom of space! You ran out of fuel. Game over.\n");
                    break;
                }
                else {
                    printf("You moved down.\n");
                }
                break;
            case 3:
                x--;
                if (x == -1) {
                    fuel--;
                    printf("You have hit the left edge of space! You ran out of fuel. Game over.\n");
                    break;
                }
                else {
                    printf("You moved left.\n");
                }
                break;
            case 4:
                x++;
                if (x == 0) {
                    fuel--;
                    printf("You have hit the right edge of space! You ran out of fuel. Game over.\n");
                    break;
                }
                else {
                    printf("You moved right.\n");
                }
                break;
            case 5:
                printf("You have %d units of fuel remaining.\n", fuel);
                break;
            case 6:
                printf("You have left space.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}