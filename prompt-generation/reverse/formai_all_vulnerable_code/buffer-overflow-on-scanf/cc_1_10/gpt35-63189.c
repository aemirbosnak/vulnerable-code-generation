//FormAI DATASET v1.0 Category: Smart home light control ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* shape shifting modes */
#define NORMAL_MODE 0
#define PARTY_MODE 1
#define ROMANTIC_MODE 2

/* function declarations */
void printMenu();
void lightOff(int mode);
void lightOn(int mode);
void changeMode(int *mode);
void executeCommand(char *input, int *mode);
void partyMode();
void romanticMode();

/* main function */
int main() {
    int mode = NORMAL_MODE;
    char input[20];

    printf("Welcome to the Smart Home Light Control Program!\n");

    while(1) {
        printMenu();
        printf("Enter a command: ");
        scanf("%s", input);
        executeCommand(input, &mode);
    }

    return 0;
}

/* prints the available options */
void printMenu() {
    printf("\nAvailable Commands: \n");
    printf("\t- on: Turn the lights on.\n");
    printf("\t- off: Turn the lights off.\n");
    printf("\t- mode: Change the shape shifting mode of the lights.\n");
    printf("\t- exit: Exit the program.\n");
}

/* turns off the lights based on current mode */
void lightOff(int mode) {
    printf("Turning off the lights in ");
    
    switch(mode) {
        case NORMAL_MODE:
            printf("normal mode.\n");
            break;
        case PARTY_MODE:
            printf("party mode.\n");
            break;
        case ROMANTIC_MODE:
            printf("romantic mode.\n");
            break;
    }
}

/* turns on the lights based on current mode */
void lightOn(int mode) {
    printf("Turning on the lights in ");
    
    switch(mode) {
        case NORMAL_MODE:
            printf("normal mode.\n");
            break;
        case PARTY_MODE:
            printf("party mode.\n");
            break;
        case ROMANTIC_MODE:
            printf("romantic mode.\n");
            break;
    }
}

/* changes the shape shifting mode of the lights */
void changeMode(int *mode) {
    printf("Select a mode (1: Party, 2: Romantic): ");
    int newMode;
    scanf("%d", &newMode);

    if(newMode == 1) {
        *mode = PARTY_MODE;
        partyMode();
    }
    else if(newMode == 2) {
        *mode = ROMANTIC_MODE;
        romanticMode();
    }
    else {
        printf("Invalid mode selected.\n");
    }
}

/* executes the input command */
void executeCommand(char *input, int *mode) {
    if(strcmp(input, "on") == 0) {
        lightOn(*mode);
    }
    else if(strcmp(input, "off") == 0) {
        lightOff(*mode);
    }
    else if(strcmp(input, "mode") == 0) {
        changeMode(mode);
    }
    else if(strcmp(input, "exit") == 0) {
        printf("Exiting program...\n");
        exit(0);
    }
    else {
        printf("Invalid command.\n");
    }
}

/* party mode shape shifting */
void partyMode() {
    printf("Entering party mode...\n");
    for(int i = 0; i < 5; i++) {
        printf("Flashing lights!\n");
        lightOn(PARTY_MODE);
        lightOff(PARTY_MODE);
    }
}

/* romantic mode shape shifting */
void romanticMode() {
    printf("Entering romantic mode...\n");
    for(int i = 0; i < 3; i++) {
        printf("Dimming the lights...\n");
        lightOn(ROMANTIC_MODE);
        printf("Turning on candles...\n");
        lightOff(ROMANTIC_MODE);
    }
}