//FormAI DATASET v1.0 Category: Smart home light control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to turn on/off the light 
void lightControl(bool status) {
    if(status) {
        printf("The light is turned on.\n");
    } else {
        printf("The light is turned off.\n");
    }
}

int main() {
    bool isLightOn = false;

    // Authentication check
    printf("Please enter the password: ");
    char password[10];
    scanf("%s", password);
    if(strcmp(password, "secure123") != 0) {
        printf("Incorrect password, access denied.\n");
        exit(EXIT_FAILURE);
    }

    printf("Welcome to the smart home light control system!\n");
    
    // Loop to simulate continuous user inputs
    while(true) {
        // User input to switch on/off the light
        printf("Type 'on' to turn on the light, 'off' to turn off the light: ");
        char input[10];
        scanf("%s", input);

        // Switch statement to handle user input
        switch(input[0]) {
            case 'o':
                isLightOn = true;
                lightControl(isLightOn);
                break;
            case 'f':
                isLightOn = false;
                lightControl(isLightOn);
                break;
            default:
                printf("Invalid input, please try again.\n");
                break;
        }
    }

    return EXIT_SUCCESS;
}