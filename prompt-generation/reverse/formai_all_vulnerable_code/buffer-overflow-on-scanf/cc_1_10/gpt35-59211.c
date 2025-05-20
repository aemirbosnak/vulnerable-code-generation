//FormAI DATASET v1.0 Category: Smart home automation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Function to check if the light is already on or off
bool lightState(bool light) {
    if(light == true) {
        printf("The light is currently turned on\n");
        return true;
    } else {
        printf("The light is currently turned off\n");
        return false;
    }
}

int main() {
    int input = 0;
    bool light = false;
    bool lock = false;
    char password[10] = "password";
    char enteredPassword[10];

    while(true) {
        printf("\nWelcome to Smart Home Automation!\nPlease select an option:\n");
        printf("1. Turn on/off the light\n");
        printf("2. Lock/unlock the door\n");
        printf("3. Exit\n");
        scanf("%d", &input);

        switch(input) {
            case 1:
                if(lightState(light) == true) {
                    printf("Do you want to turn off the light (Y/N)?\n");
                    char answer;
                    scanf(" %c", &answer);
                    if(answer == 'Y' || answer == 'y') {
                        light = false;
                        printf("The light is now turned off\n");
                    }
                } else {
                    printf("Do you want to turn on the light (Y/N)?\n");
                    char answer;
                    scanf(" %c", &answer);
                    if(answer == 'Y' || answer == 'y') {
                        light = true;
                        printf("The light is now turned on\n");
                    }
                }
                break;

            case 2:
                if(lock == true) {
                    printf("Enter the password to unlock the door: ");
                    scanf("%s", enteredPassword);

                    if(strcmp(password, enteredPassword) == 0) {
                        printf("The door is now unlocked\n");
                        lock = false;
                    } else {
                        printf("Incorrect password, try again!\n");
                    }
                } else {
                    printf("Enter a password to lock the door: ");
                    scanf("%s", password);
                    lock = true;
                    printf("The door is now locked\n");
                }
                break;

            case 3:
                printf("Exiting Smart Home Automation...\n");
                exit(0);
                break;

            default:
                printf("Invalid option, please try again!\n");
        }
    }

    return 0;
}