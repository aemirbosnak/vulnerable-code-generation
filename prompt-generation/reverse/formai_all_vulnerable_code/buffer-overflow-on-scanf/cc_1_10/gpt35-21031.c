//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: retro
#include <stdio.h>
#include <string.h>

void printIntro() {
    printf("---------------------------------------\n");
    printf("|        Welcome to Retro World!      |\n");
    printf("|    You are about to embark on an    |\n");
    printf("|   adventure full of danger and      |\n");
    printf("|     opportunity. Let's begin...     |\n");
    printf("---------------------------------------\n");
    printf("\n");
}

void printOptions() {
    printf("What would you like to do?\n");
    printf("---------------------------------------\n");
    printf("| 1. Explore the forest               |\n");
    printf("| 2. Go fishing                        |\n");
    printf("| 3. Search for treasure              |\n");
    printf("| 4. Quit game                         |\n");
    printf("---------------------------------------\n");
    printf("Enter a number to choose an option: \n");
}

int main() {
    printIntro();
    char name[20];
    printf("What is your name, adventurer?\n");
    scanf("%s", &name);
    printf("Welcome, %s. Let's begin.\n\n", name);
    int quit = 0;

    while (!quit) {
        printOptions();
        int option;
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("You venture off into the forest...\n");
                printf("Uh oh, you've encountered a wild bear!\n");
                printf("Do you fight or run?\n");
                char answer[10];
                scanf("%s", &answer);
                if (strcmp(answer, "fight") == 0) {
                    printf("You bravely fought off the bear and continue exploring the forest.\n");
                } else if (strcmp(answer, "run") == 0) {
                    printf("You run away from the bear and get lost in the forest. You eventually find your way back to town.\n");
                } else {
                    printf("Sorry, I didn't understand that command. Please try again.\n");
                }
                break;
            case 2:
                printf("You grab a fishing rod and head to the lake.\n");
                printf("You catch a big fish! It's the biggest one you've ever seen.\n");
                printf("Do you keep it or throw it back?\n");
                char decision[10];
                scanf("%s", &decision);
                if (strcmp(decision, "keep") == 0) {
                    printf("You proudly take your catch back to town to show your friends.\n");
                } else if (strcmp(decision, "throw") == 0) {
                    printf("You throw the fish back into the lake and fish some more.\n");
                } else {
                    printf("Sorry, I didn't understand that command. Please try again.\n");
                }
                break;
            case 3:
                printf("You embark on a journey to find treasure...\n");
                printf("You come across an ancient temple deep in the jungle.\n");
                printf("Do you enter or turn back?\n");
                char choice[10];
                scanf("%s", &choice);
                if (strcmp(choice, "enter") == 0) {
                    printf("You enter the temple and are ambushed by temple guards!\n");
                    printf("You fight them off and find the treasure hidden inside.\n");
                } else if (strcmp(choice, "turn") == 0) {
                    printf("You turn back and head home.\n");
                } else {
                    printf("Sorry, I didn't understand that command. Please try again.\n");
                }
                break;
            case 4:
                printf("Thanks for playing, %s! Goodbye.\n", name);
                quit = 1;
                break;
            default:
                printf("That's not a valid option, %s. Please choose a number between 1 and 4.\n", name);
                break;
        }
    }
    return 0;
}