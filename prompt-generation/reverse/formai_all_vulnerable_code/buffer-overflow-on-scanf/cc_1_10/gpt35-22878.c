//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    int option;
    float x = 0, y = 0, z = 0;
    
    // Displaying instructions to the user
    printf("Welcome to C Drone Remote Control System!\n");
    printf("Please select an option from the following:\n");
    printf("1. Move drone up by 1 unit (z-axis)\n");
    printf("2. Move drone down by 1 unit (z-axis)\n");
    printf("3. Move drone forward by 1 unit (y-axis)\n");
    printf("4. Move drone backward by 1 unit (y-axis)\n");
    printf("5. Move drone right by 1 unit (x-axis)\n");
    printf("6. Move drone left by 1 unit (x-axis)\n");
    printf("7. Display current position\n");
    printf("8. Exit\n\n");
    
    // Taking input from the user
    while (option != 8) {
        printf("Enter your option: ");
        scanf("%d", &option);
        
        // Performing actions based on user input
        switch(option) {
            case 1:
                z += 1;
                printf("Drone moved up by 1 unit\n");
                break;
            case 2:
                z -= 1;
                printf("Drone moved down by 1 unit\n");
                break;
            case 3:
                y += 1;
                printf("Drone moved forward by 1 unit\n");
                break;
            case 4:
                y -= 1;
                printf("Drone moved backward by 1 unit\n");
                break;
            case 5:
                x += 1;
                printf("Drone moved right by 1 unit\n");
                break;
            case 6:
                x -= 1;
                printf("Drone moved left by 1 unit\n");
                break;
            case 7:
                printf("Current position: (%.2f, %.2f, %.2f)\n", x, y, z);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again\n");
                break;
        }
    }
    
    return 0;
}