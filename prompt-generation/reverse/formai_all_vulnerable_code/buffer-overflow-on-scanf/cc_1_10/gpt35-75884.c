//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

int main() {
    int current_speed = 0;
    srand(time(NULL));
    
    printf("Starting remote control vehicle simulation...\n");
    
    while(1) {
        printf("Current Speed: %d\n", current_speed);
        printf("Enter a command:\n");
        printf("1. Increase Speed\n");
        printf("2. Decrease Speed\n");
        printf("3. Stop Vehicle\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(current_speed == MAX_SPEED) {
                    printf("Vehicle is already at maximum speed!\n");
                } else {
                    current_speed++;
                    printf("Vehicle speed increased to %d.\n", current_speed);
                }
                break;
            case 2:
                if(current_speed == 0) {
                    printf("Vehicle is already stopped!\n");
                } else {
                    current_speed--;
                    printf("Vehicle speed decreased to %d.\n", current_speed);
                }
                break;
            case 3:
                current_speed = 0;
                printf("Vehicle stopped.\n");
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}