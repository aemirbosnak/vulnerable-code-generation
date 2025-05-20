//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: intelligent
#include <stdio.h>

int main() {
    int x = 0;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int dir = 1;
    
    printf("Welcome to the Robot Movement Control System!\n");
    
    while (1) {
        printf("Current Position: (%d, %d)\n", x, y);
        printf("Direction: %d\n", dir);
        
        switch (dir) {
            case 1:
                printf("Moving Forward...\n");
                x += dx;
                y += dy;
                break;
            case 2:
                printf("Moving Backward...\n");
                x -= dx;
                y -= dy;
                break;
            case 3:
                printf("Moving Left...\n");
                dx = -1;
                dy = 0;
                break;
            case 4:
                printf("Moving Right...\n");
                dx = 1;
                dy = 0;
                break;
            default:
                printf("Invalid Direction!\n");
                break;
        }
        
        printf("New Position: (%d, %d)\n", x, y);
        printf("-------------------\n");
        
        printf("Do you want to continue? (y/n) ");
        char choice;
        scanf(" %c", &choice);
        
        if (choice == 'n') {
            break;
        }
    }
    
    printf("Exiting Robot Movement Control System...\n");
    
    return 0;
}