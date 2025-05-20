//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

void display_intro() {
    printf("Welcome to the Enchanted Forest Adventure!\n");
    printf("You are an adventurer seeking to uncover the mysteries of the enchanted forest.\n");
    printf("Your journey begins now...\n\n");
}

void display_choices() {
    printf("You find yourself standing at the edge of a dark forest.\n");
    printf("You can go:\n");
    printf("1. Into the forest\n");
    printf("2. To the riverbank\n");
    printf("3. Back to the village\n");
    printf("What do you want to do? (Enter 1, 2, or 3): ");
}

void forest_adventure() {
    printf("\nYou bravely venture into the forest...\n");
    printf("As you walk deeper, you hear whispers around you.\n");
    printf("Suddenly, a mystical creature appears before you!\n");
    printf("What will you do?\n");
    printf("1. Talk to the creature\n");
    printf("2. Run away\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You engage in a conversation with the creature and learn about a hidden treasure!\n");
        printf("Congratulations! You have unlocked a secret quest.\n");
    } else {
        printf("You run away and lose your chance to discover the forest's secrets.\n");
        printf("Perhaps the village is a safer option for now...\n");
    }
}

void riverbank_adventure() {
    printf("\nYou walk towards the serene riverbank...\n");
    printf("As you approach, you see a shimmering object in the water.\n");
    printf("What will you do?\n");
    printf("1. Reach for the object\n");
    printf("2. Sit by the river and relax\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You reach into the water and retrieve a magical amulet! It glows with mysterious energy.\n");
    } else {
        printf("You sit by the river and relax, letting your worries drift away with the current.\n");
    }
}

void village_adventure() {
    printf("\nYou decide to return to the safety of your village...\n");
    printf("Upon arriving, the villagers greet you with warmth.\n");
    printf("You share stories about your adventures in the enchanted forest...\n");
}

int main() {
    char input[MAX_INPUT];
    int game_running = 1;

    display_intro();

    while(game_running) {
        display_choices();
        
        scanf("%s", input);
        
        if (strcmp(input, "1") == 0) {
            forest_adventure();
        } else if (strcmp(input, "2") == 0) {
            riverbank_adventure();
        } else if (strcmp(input, "3") == 0) {
            village_adventure();
        } else {
            printf("Invalid choice. Please choose 1, 2, or 3.\n");
            continue;
        }

        printf("\nWould you like to continue your adventure? (yes/no): ");
        scanf("%s", input);

        if (strcmp(input, "no") == 0) {
            game_running = 0;
            printf("Thank you for playing! Your adventures will be remembered...\n");
        }
    }

    return 0;
}