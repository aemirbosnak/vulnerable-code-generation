//FormAI DATASET v1.0 Category: Robot movement control ; Style: inquisitive
#include <stdio.h>

int main() {
    int forward = 1;
    int backward = 2;
    int left = 3;
    int right = 4;
    int stop = 5;

    int direction = 0;

    printf("Enter a direction: \n");
    printf("1: Forward \n");
    printf("2: Backward \n");
    printf("3: Left \n");
    printf("4: Right \n");
    printf("5: Stop \n");

    scanf("%d", &direction);

    while (direction != stop) {
        switch(direction) {
            case 1:
                printf("Moving forward!\n");
                // Code to move robot forward
                break;
            
            case 2:
                printf("Moving backward!\n");
                // Code to move robot backward
                break;
            
            case 3:
                printf("Moving left!\n");
                // Code to move robot left
                break;
            
            case 4:
                printf("Moving right!\n");
                // Code to move robot right
                break;
            
            default:
                printf("Invalid direction entered!\n");
                break;
        }
        
        printf("Enter a direction: \n");
        printf("1: Forward \n");
        printf("2: Backward \n");
        printf("3: Left \n");
        printf("4: Right \n");
        printf("5: Stop \n");

        scanf("%d", &direction);
    }

    printf("Stopping robot!\n");
    // Code to stop robot

    return 0;
}