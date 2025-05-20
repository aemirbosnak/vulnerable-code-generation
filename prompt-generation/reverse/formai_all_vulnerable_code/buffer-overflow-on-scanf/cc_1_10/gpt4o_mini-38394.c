//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void intro();
void firstChoice();
void forest();
void cave();
void treasure();
void monsterFight();

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Start the adventure
    intro();
    firstChoice();

    return 0;
}

void intro() {
    printf("=========================================\n");
    printf("    WELCOME TO THE MYSTICAL ADVENTURE!  \n");
    printf("=========================================\n");
    printf("You find yourself in a mysterious land,\n");
    printf("full of enchanted forests and hidden caves.\n");
    printf("Will you become the hero you were meant to be?\n\n");
}

void firstChoice() {
    int choice;
    printf("You arrive at a fork in the road.\n");
    printf("Do you want to go:\n");
    printf("1. Into the Forest\n");
    printf("2. Into the Cave\n");
    printf("Choose 1 or 2: ");
    scanf("%d", &choice);

    if (choice == 1) {
        forest();
    } else if (choice == 2) {
        cave();
    } else {
        printf("Invalid choice. Please choose 1 or 2.\n");
        firstChoice();
    }
}

void forest() {
    printf("\nYou venture into the forest.\n");
    printf("The trees are tall and the air is fresh.\n");
    printf("Suddenly, you hear a rustling in the bushes!\n");
    printf("Do you want to:\n");
    printf("1. Investigate the sound\n");
    printf("2. Ignore and keep walking\n");
    printf("Choose 1 or 2: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You cautiously approach the bushes...\n");
        printf("A friendly fairy emerges! She offers you healing potions.\n");
        printf("You gain 2 healing potions!\n");
        firstChoice();
    } else if (choice == 2) {
        printf("You ignore the sound and continue your journey.\n");
        firstChoice();
    } else {
        printf("Invalid choice. Please choose 1 or 2.\n");
        forest();
    }
}

void cave() {
    printf("\nYou step into the dark cave.\n");
    printf("It's damp and eerie, but you feel adventurous!\n");
    printf("As you delve deeper, you see a glimmer of light...\n");
    printf("Do you:\n");
    printf("1. Approach the light\n");
    printf("2. Turn back\n");
    printf("Choose 1 or 2: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        treasure();
    } else if (choice == 2) {
        printf("You choose to turn back and explore the outside world.\n");
        firstChoice();
    } else {
        printf("Invalid choice. Please choose 1 or 2.\n");
        cave();
    }
}

void treasure() {
    printf("\nYou approach the glowing treasure chest!\n");
    printf("It radiates magic and wonder.\n");
    printf("Suddenly, a monster jumps out!\n");
    printf("Do you want to:\n");
    printf("1. Fight the monster\n");
    printf("2. Try to negotiate\n");
    printf("Choose 1 or 2: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        monsterFight();
    } else if (choice == 2) {
        printf("You attempt to negotiate with the monster...\n");
        printf("To your surprise, the monster agrees to share the treasure with you!\n");
        printf("You leave the cave with gold and mystic gems!\n");
        printf("Congratulations, you are a true adventurer!\n");
    } else {
        printf("Invalid choice. Please choose 1 or 2.\n");
        treasure();
    }
}

void monsterFight() {
    printf("You draw your sword and prepare for battle!\n");
    int playerHealth = 10;
    int monsterHealth = 8;

    while (playerHealth > 0 && monsterHealth > 0) {
        printf("Your Health: %d  |  Monster's Health: %d\n", playerHealth, monsterHealth);
        printf("You attack! It's a hit!\n");
        monsterHealth -= rand() % 5 + 1; // random damage between 1 and 5
        printf("The monster roars in anger!\n");

        if (monsterHealth <= 0) {
            printf("You defeated the monster!\n");
            printf("You open the treasure chest and find incredible loot!\n");
            printf("Congratulations, you are a hero!\n");
            return;
        }

        printf("The monster attacks!\n");
        playerHealth -= rand() % 3 + 1; // random damage between 1 and 3
        if (playerHealth <= 0) {
            printf("You have been defeated! Game Over!\n");
            return;
        }
    }
}