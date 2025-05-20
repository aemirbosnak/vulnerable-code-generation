//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void introduction();
void forest();
void encounterCreature(int choice);
void ending(int outcome);
void waitForUser();

int main() {
    introduction();
    forest();
    return 0;
}

void introduction() {
    printf("Welcome to the Mystical Forest Adventure!\n");
    printf("In this game, you'll explore a magical forest and interact with various creatures.\n");
    printf("Choose wisely, as your decisions will affect the outcome of your adventure.\n");
    waitForUser();
}

void forest() {
    int choice;
    printf("\nYou stand at the edge of a dark, mystical forest.\n");
    printf("Do you want to:\n");
    printf("1. Enter the forest\n");
    printf("2. Walk away\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou bravely step into the forest.\n");
        encounterCreature(choice);
    } else {
        printf("\nYou decide to walk away, missing out on an adventure.\n");
        ending(0);
    }
}

void encounterCreature(int choice) {
    int creatureChoice;
    printf("\nAs you wander deeper into the forest, you encounter a friendly unicorn!\n");
    printf("What do you want to do?\n");
    printf("1. Approach the unicorn\n");
    printf("2. Run away\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &creatureChoice);
    
    if (creatureChoice == 1) {
        printf("\nThe unicorn leads you to a hidden waterfall filled with magical waters!\n");
        ending(1);
    } else {
        printf("\nYou run away from the unicorn and stumble into a band of mischievous fairies!\n");
        printf("What do you want to do?\n");
        printf("1. Join the fairies\n");
        printf("2. Try to escape\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &creatureChoice);
        
        if (creatureChoice == 1) {
            printf("\nThe fairies teach you their magical tricks and you become a part of their world.\n");
            ending(2);
        } else {
            printf("\nYou escape the fairies, but the forest begins to close in around you...\n");
            ending(0);
        }
    }
}

void ending(int outcome) {
    switch(outcome) {
        case 0:
            printf("\nYou return to your normal life, but the adventures you missed linger in your mind...\n");
            printf("Game Over. Better luck next time!\n");
            break;
        case 1:
            printf("\nYou drink from the magical waters and gain the powers to understand all creatures.\n");
            printf("You become a protector of the forest, living in harmony!\n");
            printf("Congratulations, you've won!\n");
            break;
        case 2:
            printf("\nWith the fairies' magic, you create wonders and spread joy throughout the land.\n");
            printf("Your name becomes known as the legendary friend of magic!\n");
            printf("Congratulations, you've won!\n");
            break;
        default:
            printf("Something went wrong in the ending...\n");
            break;
    }
    exit(0);
}

void waitForUser() {
    printf("Press Enter to continue...\n");
    while (getchar() != '\n');  // Wait for user to press Enter
    getchar();  // Wait for user to press Enter again for convenience
}