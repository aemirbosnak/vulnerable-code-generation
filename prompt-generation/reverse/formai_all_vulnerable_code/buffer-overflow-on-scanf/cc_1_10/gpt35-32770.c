//FormAI DATASET v1.0 Category: Smart home light control ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

// Function to turn on the lights in a specific room
void turnOn(char room[]) {
    printf("Turning on %s lights.\n", room);
}

// Function to turn off the lights in a specific room
void turnOff(char room[]) {
    printf("Turning off %s lights.\n", room);
}

int main() {
    int choice;
    char room[20];

    printf("Welcome to Smart Home Light Control.\n");

    // Loop until the user chooses to exit
    while (1) {
        printf("\n");
        printf("1. Turn on lights\n");
        printf("2. Turn off lights\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // If user chooses 1, ask for room name and turn on the lights in that room
        if (choice == 1) {
            printf("Which room would you like to turn on the lights for?\n");
            scanf("%s", room);
            turnOn(room);
        }
        // If user chooses 2, ask for room name and turn off the lights in that room
        else if (choice == 2) {
            printf("Which room would you like to turn off the lights for?\n");
            scanf("%s", room);
            turnOff(room);
        }
        // If user chooses 3, exit the program
        else if (choice == 3) {
            printf("Exiting program.\n");
            break;
        }
        // If user chooses an invalid option, display an error message
        else {
            printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}