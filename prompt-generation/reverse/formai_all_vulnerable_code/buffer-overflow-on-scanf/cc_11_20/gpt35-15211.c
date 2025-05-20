//FormAI DATASET v1.0 Category: Smart home light control ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to Smart Home Light Control System!\n");
    
    // Initialize variables
    int living_room = 0;
    int bedroom = 0;
    int kitchen = 0;
    
    // Loop to prompt user for input
    while(1) {
        int input;
        printf("\nEnter 1 to turn on the living room lights\n");
        printf("Enter 2 to turn on the bedroom lights\n");
        printf("Enter 3 to turn on the kitchen lights\n");
        printf("Enter 4 to turn off the living room lights\n");
        printf("Enter 5 to turn off the bedroom lights\n");
        printf("Enter 6 to turn off the kitchen lights\n");
        printf("Enter 0 to exit the system\n");
        scanf("%d", &input);
        
        // Process user input
        switch(input) {
            case 1:
                living_room = 1;
                printf("Living room lights turned on.\n");
                break;
            case 2:
                bedroom = 1;
                printf("Bedroom lights turned on.\n");
                break;
            case 3:
                kitchen = 1;
                printf("Kitchen lights turned on.\n");
                break;
            case 4:
                living_room = 0;
                printf("Living room lights turned off.\n");
                break;
            case 5:
                bedroom = 0;
                printf("Bedroom lights turned off.\n");
                break;
            case 6:
                kitchen = 0;
                printf("Kitchen lights turned off.\n");
                break;
            case 0:
                printf("Exiting Smart Home Light Control System.\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
        
        // Check if all lights are turned off
        if(living_room == 0 && bedroom == 0 && kitchen == 0) {
            printf("All lights are turned off. Good night!\n");
            exit(0);
        }
    }
    return 0;
}