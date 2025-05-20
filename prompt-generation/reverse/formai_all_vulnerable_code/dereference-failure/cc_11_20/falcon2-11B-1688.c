//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[20];
    printf("Enter your name: ");
    fgets(name, 20, stdin);
    
    char* verb = "walk";
    char* noun = "forest";
    char* noun2 = "beast";
    char* noun3 = "castle";
    
    char command[100];
    printf("You are standing in a forest. What do you want to do? ");
    fgets(command, 100, stdin);
    
    char *words[3];
    strcpy(words[0], "walk");
    strcpy(words[1], "forest");
    strcpy(words[2], "castle");
    
    int choice = 0;
    while (choice!= 4) {
        if (strcmp(command, "quit") == 0) {
            printf("Goodbye.\n");
            return 0;
        }
        else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("%s\n", words[0]);
            printf("%s\n", words[1]);
            printf("%s\n", words[2]);
            printf("Enter 'quit' to exit.\n");
        }
        else if (strcmp(command, words[0]) == 0) {
            printf("You walk through the forest. You encounter a beast.\n");
            printf("Do you want to fight the beast? (y/n): ");
            fgets(command, 100, stdin);
            if (strcmp(command, "y") == 0) {
                printf("You defeat the beast and gain 10 points.\n");
            }
            else {
                printf("You run away from the beast.\n");
            }
        }
        else if (strcmp(command, words[1]) == 0) {
            printf("You arrive at a castle. Do you want to enter? (y/n): ");
            fgets(command, 100, stdin);
            if (strcmp(command, "y") == 0) {
                printf("You enter the castle. You find a treasure chest. Do you want to open it? (y/n): ");
                fgets(command, 100, stdin);
                if (strcmp(command, "y") == 0) {
                    printf("You find 100 gold coins in the treasure chest. You gain 100 points.\n");
                }
                else {
                    printf("You leave the treasure chest alone.\n");
                }
            }
            else {
                printf("You decide not to enter the castle.\n");
            }
        }
        else if (strcmp(command, words[2]) == 0) {
            printf("You arrive at a castle. Do you want to enter? (y/n): ");
            fgets(command, 100, stdin);
            if (strcmp(command, "y") == 0) {
                printf("You enter the castle. You find a treasure chest. Do you want to open it? (y/n): ");
                fgets(command, 100, stdin);
                if (strcmp(command, "y") == 0) {
                    printf("You find 100 gold coins in the treasure chest. You gain 100 points.\n");
                }
                else {
                    printf("You leave the treasure chest alone.\n");
                }
            }
            else {
                printf("You decide not to enter the castle.\n");
            }
        }
        else {
            printf("Invalid command.\n");
        }
        
        printf("Enter 'help' for a list of commands, or 'quit' to exit.\n");
    }
    
    return 0;
}