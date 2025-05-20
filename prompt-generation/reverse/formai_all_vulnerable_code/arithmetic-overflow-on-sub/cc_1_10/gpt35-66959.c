//FormAI DATASET v1.0 Category: Smart home light control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 5
#define MAX_LIGHTS 10

int main()
{
    int numOfUsers = 0, numOfLights = 0, userChoice, lightChoice;
    char users[MAX_USERS][30], lights[MAX_LIGHTS][30];
    char action[10], state[10];

    // Get the number of users
    printf("Welcome to our Smart Home Light Control System!\n\n");
    printf("Please enter the number of users: ");
    scanf("%d", &numOfUsers);

    // Get the names of the users
    for (int i = 0; i < numOfUsers; i++) {
        printf("Enter the name of user %d: ", i + 1);
        scanf("%s", users[i]);
    }

    // Get the number of lights
    printf("\nPlease enter the number of lights: ");
    scanf("%d", &numOfLights);

    // Get the names of the lights
    for (int i = 0; i < numOfLights; i++) {
        printf("Enter the name of light %d: ", i + 1);
        scanf("%s", lights[i]);
    }

    // Loop until the user chooses to exit
    while (1) {
        printf("\nPlease choose from the following options:\n");
        printf("1. Turn a light on/off\n");
        printf("2. Add a new user\n");
        printf("3. Add a new light\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch(userChoice) {
            case 1:
                // Turn a light on/off
                printf("\nPlease choose the light you want to control:\n");
                for (int i = 0; i < numOfLights; i++) {
                    printf("%d. %s\n", i + 1, lights[i]);
                }
                
                printf("Enter your choice: ");
                scanf("%d", &lightChoice);

                printf("Enter the action you want to perform (on/off): ");
                scanf("%s", action);

                printf("Enter the state you want to set (0-255): ");
                scanf("%s", state);

                printf("\nSending command to light %s to turn %s with state %s...\n", lights[lightChoice-1], action, state);
                break;

            case 2:
                // Add a new user
                printf("\nEnter the name of the new user: ");
                scanf("%s", users[numOfUsers]);

                numOfUsers++;
                printf("The user has been added successfully!\n");
                break;

            case 3:
                // Add a new light
                printf("\nEnter the name of the new light: ");
                scanf("%s", lights[numOfLights]);

                numOfLights++;
                printf("The light has been added successfully!\n");
                break;

            case 4:
                // Exit
                printf("\nThank you for using our Smart Home Light Control System!\n");
                exit(EXIT_SUCCESS);

            default:
                // Invalid choice
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}