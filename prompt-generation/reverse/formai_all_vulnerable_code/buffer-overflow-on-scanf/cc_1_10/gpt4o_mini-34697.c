//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>

// Function declarations
void start_game();
void choose_path();
void encounter_monster();
void find_treasure();
void game_over();

int main() {
    start_game();
    return 0;
}

void start_game() {
    char name[30];
    printf("Welcome, brave adventurer! What is your name? ");
    fgets(name, sizeof(name), stdin);
    printf("Ah, %s! A fine name for a treasure seeker!\n", name);
    printf("Your journey begins in a dark and mysterious forest...\n");
    choose_path();
}

void choose_path() {
    int choice;
    printf("You stand at a fork in the path. Do you wish to go:\n");
    printf("1. Left towards the spooky cave.\n");
    printf("2. Right towards the babbling brook.\n");
    printf("Choose (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        encounter_monster();
    } else if (choice == 2) {
        find_treasure();
    } else {
        printf("That's not a valid choice. Try again.\n");
        choose_path();
    }
}

void encounter_monster() {
    int action;
    printf("You chose the left path and find yourself near a spooky cave.\n");
    printf("Suddenly, a fierce monster appears before you! What will you do?\n");
    printf("1. Fight the monster.\n");
    printf("2. Run away.\n");
    printf("Choose (1 or 2): ");
    scanf("%d", &action);

    if (action == 1) {
        printf("You bravely decide to fight the monster!\n");
        printf("After a tough battle, you manage to defeat it!\n");
        printf("But you are injured... what will you do next?\n");
        choose_path(); // Choose a new path after healing
    } else if (action == 2) {
        printf("You run away as fast as you can and escape the monster!\n");
        printf("However, you find yourself lost. Try to find your way again.\n");
        choose_path();
    } else {
        printf("That's not a valid action. Try again.\n");
        encounter_monster();
    }
}

void find_treasure() {
    printf("You stroll along the brook, enjoying the sounds of nature.\n");
    printf("Suddenly, you spot something shiny in the water! Do you:\n");
    printf("1. Dive in to retrieve it.\n");
    printf("2. Ignore it and keep walking.\n");
    printf("Choose (1 or 2): ");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You dive in and retrieve a beautiful golden key!\n");
        printf("This key might unlock a hidden treasure. How exciting!\n");
        // Prompt to explore further or exit
    } else if (choice == 2) {
        printf("You decide to ignore the shiny object.\n");
        printf("Suddenly, a mysterious old man appears. He asks: 'Why did you ignore your fate?'\n");
        // Offer choices based on his words here
    } else {
        printf("That's not a valid choice. Please choose again.\n");
        find_treasure();
    }
}

void game_over() {
    printf("Game Over. Thank you for playing!\n");
    // Here, you could give an option to restart or exit the game.
}