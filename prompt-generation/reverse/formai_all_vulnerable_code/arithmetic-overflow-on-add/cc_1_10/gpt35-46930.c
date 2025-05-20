//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include <stdio.h>

int main() {
    int x, y;
    printf("Enter the x coordinate of drone: ");
    scanf("%d", &x);
    printf("Enter the y coordinate of drone: ");
    scanf("%d", &y);
    printf("\n\n\n");
    printf("*********** DRONE REMOTE CONTROL ***********\n");
    printf("Current drone position: (%d, %d)\n\n", x, y);
    printf("Enter direction code: \n");
    printf("1 - Move up\n");
    printf("2 - Move down\n");
    printf("3 - Move left\n");
    printf("4 - Move right\n");
    printf("5 - Move diagonally up-left\n");
    printf("6 - Move diagonally up-right\n");
    printf("7 - Move diagonally down-left\n");
    printf("8 - Move diagonally down-right\n");
    printf("9 - Hover in current position\n");

    int direction;
    printf("\nEnter direction code: ");
    scanf("%d", &direction);
    switch(direction) {
        case 1:
            y++;
            break;
        case 2:
            y--;
            break;
        case 3:
            x--;
            break;
        case 4:
            x++;
            break;
        case 5:
            x--;
            y++;
            break;
        case 6:
            x++;
            y++;
            break;
        case 7:
            x--;
            y--;
            break;
        case 8:
            x++;
            y--;
            break;
        case 9: 
            break;
        default:
            printf("Invalid direction code\n");
            break;
    }
    
    printf("\n");
    printf("New drone position: (%d, %d)\n", x, y);
    return 0;
}