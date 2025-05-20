//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void welcome();
void instructions();
void create_character();
void explore_forest();
void enter_cave();
void choose_path();
void display_status();

typedef struct {
    char name[30];
    int health;
    int damage;
} Character;

Character player;

int main() {
    welcome();
    create_character();
    instructions();
    choose_path();
    return 0;
}

void welcome() {
    printf("================================\n");
    printf("   Welcome to Shadows of Lore   \n");
    printf("   A Text-Based Adventure Game   \n");
    printf("================================\n");
}

void instructions() {
    printf("\nInstructions:\n");
    printf("1. You will embark on an adventure in a fantasy world.\n");
    printf("2. Make choices that affect the outcome of your journey.\n");
    printf("3. Your health and damage will be important in battles.\n");
    printf("4. Explore different paths and face various challenges.\n");
    printf("5. Have fun and enjoy the journey!\n");
    printf("\nPress Enter to continue...\n");
    getchar(); // waiting for user input
}

void create_character() {
    printf("\nEnter your character's name: ");
    fgets(player.name, sizeof(player.name), stdin);
    player.name[strcspn(player.name, "\n")] = '\0'; // remove newline character
    player.health = 100;
    player.damage = 20;
    printf("Character created: %s | Health: %d | Damage: %d\n", player.name, player.health, player.damage);
}

void choose_path() {
    int choice;
    printf("\nYou stand at a crossroads in a dark forest.\n");
    printf("1. Explore the forest.\n");
    printf("2. Enter the mysterious cave.\n");
    printf("Choose your path (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        explore_forest();
    } else if (choice == 2) {
        enter_cave();
    } else {
        printf("Invalid choice! You remain at the crossroads.\n");
        choose_path();
    }
}

void explore_forest() {
    printf("\nYou venture deeper into the forest...\n");
    printf("The trees whisper ancient secrets as you walk.\n");
    display_status();

    // Random encounter
    if (rand() % 2) {
        printf("A wild wolf appears!\n");
        player.health -= 20; // take damage
        printf("You fought bravely, but the wolf inflicted damage.\n");
        printf("Your health is now %d.\n", player.health);
    } else {
        printf("You find a healing herb and restore some health.\n");
        player.health += 10;
        printf("Your health is now %d.\n", player.health);
    }

    printf("\nPress Enter to return to the crossroads...\n");
    getchar(); // wait for user to press enter
    getchar(); // wait for user to press enter again
    choose_path();
}

void enter_cave() {
    printf("\nYou cautiously enter the cave...\n");
    printf("The darkness envelops you as you proceed.\n");
    display_status();

    // Random encounter in cave
    if (rand() % 2) {
        printf("A giant bat swoops down towards you!\n");
        player.health -= 30; // take damage
        printf("The bat scratches you and you stumble back!\n");
        printf("Your health is now %d.\n", player.health);
    } else {
        printf("You find a hidden treasure chest filled with gold!\n");
    }

    printf("\nPress Enter to return to the crossroads...\n");
    getchar(); // wait for user to press enter
    getchar(); // wait for user to press enter again
    choose_path();
}

void display_status() {
    printf("\nCurrent Status:\n");
    printf("Character: %s\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Damage: %d\n", player.damage);
}