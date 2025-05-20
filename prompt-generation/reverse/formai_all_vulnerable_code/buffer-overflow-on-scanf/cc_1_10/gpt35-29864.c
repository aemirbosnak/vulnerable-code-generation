//FormAI DATASET v1.0 Category: Smart home light control ; Style: systematic
/* Smart Home Light Control Program */
#include <stdio.h>
#include <stdlib.h>

/* Function to turn on the lights */
void turnOnLights() {
    printf("Lights turned on.\n");
}

/* Function to turn off the lights */
void turnOffLights() {
    printf("Lights turned off.\n");
}

/* Function to dim the lights */
void dimLights(int brightness) {
    printf("Lights dimmed to %d.\n", brightness);
}

int main() {
    char option;
    int brightness = 0;
    
    /* Display options for the user */
    printf("Welcome to Smart Home Light Control\n\n");
    printf("Select an option:\n");
    printf("1. Turn on the lights\n");
    printf("2. Turn off the lights\n");
    printf("3. Dim the lights\n");
    printf("4. Exit\n");
    
    /* Take input from the user and perform the selected action */
    while(1) {
        printf("\nEnter your choice: ");
        scanf(" %c", &option);
        
        switch(option) {
            case '1':
                turnOnLights();
                break;
            case '2':
                turnOffLights();
                break;
            case '3':
                printf("Enter brightness level (1-10): ");
                scanf("%d", &brightness);
                
                /* Ensure the entered brightness is within range */
                if(brightness < 1) brightness = 1;
                if(brightness > 10) brightness = 10;
                
                dimLights(brightness);
                break;
            case '4':
                printf("\nExiting Smart Home Light Control. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option. Please select a valid option.\n");
        }
    }
    
    return 0;
}