//FormAI DATASET v1.0 Category: Smart home light control ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 20
#define MAX_COMMAND_LENGTH 50

// Define a struct to represent a light bulb
typedef struct {
    char name[MAX_NAME_LENGTH];
    bool isOn;
} LightBulb;

// Define a function to turn on/off a light bulb
void toggleLightBulb(LightBulb* bulb) {
    if (bulb->isOn) {
        printf("%s light turned off.\n", bulb->name);
        bulb->isOn = false;
    } else {
        printf("%s light turned on.\n", bulb->name);
        bulb->isOn = true;
    }
}

int main() {
    int numBulbs;

    printf("Welcome to the Smart Home Light Control!\n");

    printf("How many light bulbs do you have in your house? ");
    scanf("%d", &numBulbs);

    // Declare an array of LightBulbs with the size numBulbs
    LightBulb bulbs[numBulbs];

    // Prompt the user to enter the name of each light bulb
    for (int i = 0; i < numBulbs; i++) {
        printf("Enter the name of light bulb #%d: ", i + 1);
        scanf("%s", bulbs[i].name);
        bulbs[i].isOn = false;
    }

    printf("\n");

    // Loop to receive user input to turn on/off a light bulb
    while (true) {
        int bulbNum;
        char command[MAX_COMMAND_LENGTH];

        printf("Enter the name of the light bulb you want to toggle or 'exit' to exit: ");
        scanf("%s", command);

        // Check if user wants to exit the program
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Search for the light bulb with the given name and toggle it
        bool bulbFound = false;

        for (int i = 0; i < numBulbs; i++) {
            if (strcmp(bulbs[i].name, command) == 0) {
                toggleLightBulb(&bulbs[i]);
                bulbFound = true;
                break;
            }
        }

        // Print an error message if the light bulb was not found
        if (!bulbFound) {
            printf("Could not find light bulb with name '%s'\n", command);
        }
    }

    printf("Thank you for using Smart Home Light Control!\n");

    return 0;
}