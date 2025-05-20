//FormAI DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>

// Function to turn on the light
void turn_on_light() {
    printf("Light is turned on.\n");
}

// Function to turn off the light
void turn_off_light() {
    printf("Light is turned off.\n");
}

// Main function that controls the light
int main() {
    int light_status = 0; // Light is turned off initially
    int input;
    
    printf("Welcome to Smart Home Light Control!\n\n");
    
    while(1) {
        printf("Enter your choice:\n");
        printf("1. Turn on the light\n");
        printf("2. Turn off the light\n");
        printf("3. Exit\n");
        scanf("%d", &input);
        
        switch(input) {
            case 1:
                if(light_status == 0) {
                    turn_on_light();
                    light_status = 1;
                } else {
                    printf("Light is already turned on!\n");
                }
                break;
            case 2:
                if(light_status == 1) {
                    turn_off_light();
                    light_status = 0;
                } else {
                    printf("Light is already turned off!\n");
                }
                break;
            case 3:
                printf("Thank you for using Smart Home Light Control!\n");
                return 0;
            default:
                printf("Invalid input. Please try again!\n");
        }
    }
    
    return 0;
}