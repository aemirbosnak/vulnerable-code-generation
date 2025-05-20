//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>

int main() {
    int x = 0;
    int y = 0;
    int direction = 0;
    
    printf("Enter initial x and y coordinates: ");
    scanf("%d %d", &x, &y);
    
    while (1) {
        printf("Enter movement command: ");
        scanf("%d", &direction);
        
        switch (direction) {
            case 1:
                if (x < 10) {
                    x++;
                    printf("Moving forward 1 unit\n");
                } else {
                    printf("Cannot move forward\n");
                }
                break;
                
            case 2:
                if (y < 10) {
                    y++;
                    printf("Moving up 1 unit\n");
                } else {
                    printf("Cannot move up\n");
                }
                break;
                
            case 3:
                if (x > 0) {
                    x--;
                    printf("Moving backward 1 unit\n");
                } else {
                    printf("Cannot move backward\n");
                }
                break;
                
            case 4:
                if (y > 0) {
                    y--;
                    printf("Moving down 1 unit\n");
                } else {
                    printf("Cannot move down\n");
                }
                break;
                
            case 5:
                printf("Exiting program\n");
                break;
                
            default:
                printf("Invalid movement command\n");
                break;
        }
    }
    
    return 0;
}