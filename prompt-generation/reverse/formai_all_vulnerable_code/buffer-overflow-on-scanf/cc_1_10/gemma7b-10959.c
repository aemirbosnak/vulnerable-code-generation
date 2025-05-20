//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void traverse_space(int x, int y, int z) {
    printf("You are at coordinates (%d, %d, %d). \n", x, y, z);
    printf("What would you like to do? (travel, fight, explore): ");
    char input;
    scanf("%c", &input);

    switch (input) {
        case 't':
            printf("Please specify the direction you want to travel (north, south, east, west): ");
            char direction;
            scanf("%c", &direction);

            switch (direction) {
                case 'n':
                    x++;
                    traverse_space(x, y, z);
                    break;
                case 's':
                    x--;
                    traverse_space(x, y, z);
                    break;
                case 'e':
                    y++;
                    traverse_space(x, y, z);
                    break;
                case 'w':
                    y--;
                    traverse_space(x, y, z);
                    break;
                default:
                    printf("Invalid direction. Please try again.\n");
                    traverse_space(x, y, z);
            }
            break;
        case 'f':
            printf("Please select your target (a number between 1 and 10): ");
            int target;
            scanf("%d", &target);

            printf("You have attacked target %d.\n", target);
            break;
        case 'e':
            printf("You have explored the area.\n");
            break;
        default:
            printf("Invalid input. Please try again.\n");
            traverse_space(x, y, z);
    }
}

int main() {
    traverse_space(0, 0, 0);
    return 0;
}