//FormAI DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int is_light_on = 0; // Initially, light is off
    char user_prompt;

    printf("Welcome to Smart Home Lighting System\n");
    printf("-------------------------------------\n");

    while(1) {
        printf("Enter 'ON' to turn on the light or 'OFF' to turn it off: ");
        scanf("%s", &user_prompt);

        // Convert the user input to uppercase
        user_prompt = toupper(user_prompt);

        // Check if user wants to turn on the light
        if(user_prompt == 'O') {
            printf("Turning on the light...\n");
            is_light_on = 1; // set the light flag to on
        } 
        // Check if user wants to turn off the light
        else if(user_prompt == 'F') {
            printf("Turning off the light...\n");
            is_light_on = 0; // set the light flag to off
        } 
        // If user input invalid input
        else {
            printf("Invalid input! Try Again.\n");
            continue; // Prompt the user again
        }

        // Ask user if they want to see the current status of light
        printf("Do you want to see the current status of the light? (y/n): ");
        scanf(" %c", &user_prompt); // include space before %c to avoid reading newline character

        // Check if user wants to see current status of light
        if(toupper(user_prompt) == 'Y') {
            if(is_light_on) {
                printf("The light is currently ON.\n");
            } else {
                printf("The light is currently OFF.\n");
            }
        } 

        // Ask user if they want to continue or exit
        printf("Do you want to continue or exit? (c/e): ");
        scanf(" %c", &user_prompt);

        // Check if the user wants to exit
        if(toupper(user_prompt) == 'E') {
            printf("Exiting Smart Home Lighting System...\n");
            break; // Exit the while loop
        } 
    }

    return 0;
}