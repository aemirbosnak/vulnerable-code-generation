//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_ARG_LENGTH 20
#define MAX_NUM_ARGS 8

void displayWelcomeMessage() {
    printf("Welcome, brave traveler, to the Kingdom of Codoria!\n");
    printf("Here you may issue commands to navigate our realm.\n");
    printf("Type 'help' for assistance or 'exit' to bid farewell.\n");
}

void displayHelp() {
    printf("Herein lies the list of commands:\n");
    printf("1. greet - Asks your name and greets you.\n");
    printf("2. quest - Accept a quest for honor!\n");
    printf("3. explore - Roam the lands of Codoria.\n");
    printf("4. status - Check your current status.\n");
    printf("5. exit - Leave the kingdom.\n");
}

void greet() {
    char name[MAX_ARG_LENGTH];
    printf("What be thy name, noble traveler? ");
    scanf("%s", name);
    printf("Hail, %s! May your journey be prosperous!\n", name);
}

void quest() {
    printf("You have been granted a quest to slay the Dragon of Doom!\n");
    printf("Prepare thy sword and armor, noble warrior!\n");
}

void explore() {
    printf("You wander through the enchanted forest of Lorenthia...\n");
    printf("Suddenly, a band of merry elves appears!\n");
    printf("They offer you a magical potion. What shall you do?\n");
    printf("1. Accept the potion.\n");
    printf("2. Decline and continue your journey.\n");
    
    int choice;
    printf("Choose wisely: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You received a potion of strength! Your might increases!\n");
    } else {
        printf("You chose to decline. The elves nod and wave goodbye.\n");
    }
}

void status() {
    printf("Your current status:\n");
    printf("Health: 100\n");
    printf("Strength: 10\n");
    printf("Magic: 5\n");
}

void executeCommand(char *command) {
    if (strcmp(command, "help") == 0) {
        displayHelp();
    } else if (strcmp(command, "greet") == 0) {
        greet();
    } else if (strcmp(command, "quest") == 0) {
        quest();
    } else if (strcmp(command, "explore") == 0) {
        explore();
    } else if (strcmp(command, "status") == 0) {
        status();
    } else if (strcmp(command, "exit") == 0) {
        printf("Farewell, noble traveler! Until we meet again!\n");
        exit(0);
    } else {
        printf("Alas! I know not what thou speakest of. Please issue a valid command.\n");
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    displayWelcomeMessage();

    while (1) {
        printf("\nEnter thy command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline
        executeCommand(command);
    }

    return 0;
}