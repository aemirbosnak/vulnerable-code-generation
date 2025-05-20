//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void welcomeMessage() {
    printf("========================================\n");
    printf("       Welcome to the Forest Adventure!  \n");
    printf("========================================\n");
    printf("You find yourself in a dark and spooky forest.\n");
    printf("Your goal is to find the hidden treasure!\n");
}

void story() {
    printf("You can explore the forest or look for the exit.\n");
    printf("Choose wisely! Type 'explore' to explore or 'exit' to try to leave.\n");
}

void explore() {
    printf("\nYou walk deeper into the forest...\n");
    printf("You encounter a wise old man who offers you a choice:\n");
    printf("1. Ask for a hint about the treasure\n");
    printf("2. Ask to be transported to a safe place\n");
    printf("3. Ignore him and continue exploring\n");
}

void hint() {
    printf("\nThe wise old man says:\n");
    printf("\"The treasure lies beneath the great oak tree, but beware of the guardian!\"\n");
    printf("What will you do next? Type 'search' to search for the oak tree or 'continue' to keep exploring.\n");
}

void guardian() {
    printf("\nYou approach the oak tree but are confronted by a fierce guardian!\n");
    printf("He challenges you to a riddle:\n");
    printf("\"I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?\"\n");
    
    char answer[20];
    printf("Your answer: ");
    scanf("%s", answer);
    
    if (strcmp(answer, "echo") == 0) {
        printf("Correct! The guardian lets you pass.\n");
        printf("You find the treasure!\n");
        printf("Congratulations, you win!\n");
    } else {
        printf("Incorrect. The guardian does not let you pass and you return to the clearing.\n");
        story();
    }
}

int main() {
    char command[10];

    welcomeMessage();
    story();

    while (1) {
        printf("Enter your command: ");
        scanf("%s", command);

        if (strcmp(command, "explore") == 0) {
            explore();
            while (1) {
                printf("Enter your choice: ");
                scanf("%s", command);
                
                if (strcmp(command, "1") == 0) {
                    hint();
                    break; // exit to the explore loop to continue
                } else if (strcmp(command, "2") == 0) {
                    printf("You have been transported to a safe place. Game over.\n");
                    return 0;
                } else if (strcmp(command, "3") == 0) {
                    guardian(); // move directly to the guardian
                    break; // exit to the explore branch
                } else {
                    printf("Invalid choice. Try again.\n");
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("You have successfully escaped! Game over.\n");
            return 0;
        } else {
            printf("Invalid command. Please type 'explore' or 'exit'.\n");
        }
    }

    return 0;
}