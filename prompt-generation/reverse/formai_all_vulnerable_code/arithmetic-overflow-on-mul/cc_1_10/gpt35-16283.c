//FormAI DATASET v1.0 Category: Smart home light control ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to turn lights on or off
void turnLights(char* room, int status) {
    if(status == 1) {
        printf("Turning on the lights in %s\n", room);
    }
    else {
        printf("Turning off the lights in %s\n", room);
    }
}

// Function to dim the lights
void dimLights(char* room, int dimPercentage) {
    printf("Dimming the lights in %s to %d%%\n", room, dimPercentage);
}

// Function to change the color of the lights
void changeColor(char* room, char* color) {
    printf("Changing the lights in %s to the color %s\n", room, color);
}

// Function to set a timer
void setTimer(char* room, int minutes) {
    time_t now = time(NULL);
    time_t endTime = now + (minutes * 60);
    printf("Timer set for %d minutes in %s. Lights will turn off at %s", minutes, room, ctime(&endTime));
}

int main() {
    int userInput;
    char room[20];
    int dimPercentage;
    char color[20];
    int timerMinutes;

    printf("Welcome to the smart home light control program!\n");
    printf("Which room would you like to control? (living room, kitchen, bedroom)\n");
    scanf("%s", room);

    do {
        printf("What would you like to do in %s?\n", room);
        printf("1. Turn lights on\n");
        printf("2. Turn lights off\n");
        printf("3. Dim lights\n");
        printf("4. Change color\n");
        printf("5. Set timer\n");
        printf("6. Exit program\n");

        scanf("%d", &userInput);

        switch(userInput) {
            case 1:
                turnLights(room, 1);
                break;
            case 2:
                turnLights(room, 0);
                break;
            case 3:
                printf("What percentage would you like to dim the lights to?\n");
                scanf("%d", &dimPercentage);
                dimLights(room, dimPercentage);
                break;
            case 4:
                printf("What color would you like to change the lights to?\n");
                scanf("%s", color);
                changeColor(room, color);
                break;
            case 5:
                printf("How many minutes would you like to set the timer for?\n");
                scanf("%d", &timerMinutes);
                setTimer(room, timerMinutes);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

    } while(userInput != 6);

    return 0;
}