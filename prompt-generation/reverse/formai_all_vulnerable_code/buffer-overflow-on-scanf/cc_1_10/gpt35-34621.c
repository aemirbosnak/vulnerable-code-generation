//FormAI DATASET v1.0 Category: Smart home light control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PASSWORD "mypassword"

int main(void) {
    bool isLocked = true;
    char password[20];
    int lightStatus = 0;

    printf("Welcome to the Smart Home Light Control System.\n");

    while (isLocked) {
        printf("Please enter the password to unlock the system: ");
        scanf("%s", password);

        if (strcmp(password, PASSWORD) == 0) {
            printf("The system is now unlocked!\n");
            isLocked = false;
        } else {
            printf("Incorrect password. Please try again.\n");
        }
    }

    while (true) {

        printf("\nEnter a number to choose an action:\n");
        printf("1. Turn the light on.\n");
        printf("2. Turn the light off.\n");
        printf("3. Check the light status.\n");
        printf("4. Exit the program.\n\n");

        int input = 0;
        scanf("%d", &input);

        switch (input) {
            case 1:
                lightStatus = 1;
                printf("The light is now on.\n");
                break;
            case 2:
                lightStatus = 0;
                printf("The light is now off.\n");
                break;
            case 3:
                if (lightStatus == 1) {
                    printf("The light is currently on.\n");
                } else {
                    printf("The light is currently off.\n");
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}