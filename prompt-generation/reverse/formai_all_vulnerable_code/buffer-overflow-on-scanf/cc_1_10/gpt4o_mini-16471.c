//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CHOICES 3
#define MAX_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    int health;
    int items;
} Player;

void print_intro() {
    printf("Welcome to 'Quest for the Golden Amulet'!\n");
    printf("You are about to embark on a thrilling adventure to seek the legendary golden amulet hidden deep in the enchanted forest.\n");
    printf("Prepare for excitement, danger, and choices that will shape your destiny!\n\n");
}

void create_player(Player *player) {
    printf("Enter your hero's name: ");
    fgets(player->name, MAX_NAME_LEN, stdin);
    player->name[strcspn(player->name, "\n")] = '\0'; // Remove newline character
    player->health = 100;
    player->items = 0;
    printf("Welcome, brave %s! Your journey begins now!\n\n", player->name);
}

void show_status(Player *player) {
    printf("Player Status:\n");
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Items: %d\n", player->items);
    printf("-------------------------------\n");
}

int random_event() {
    return rand() % 3; // Random number between 0 and 2
}

void encounter(Player *player) {
    printf("You venture deeper into the forest...\n");
    int event = random_event();
    switch (event) {
        case 0:
            printf("You find a treasure chest! You've gained a magical potion!\n");
            player->items++;
            break;
        case 1:
            printf("A wild wolf appears!! You must fight!\n");
            player->health -= 30;
            printf("You've battled valiantly but lost some health! Current health: %d\n", player->health);
            break;
        case 2:
            printf("You stumble into a sparkling spring! You'll regain some health!\n");
            player->health += 20;
            if (player->health > 100) {
                player->health = 100;
            }
            printf("You feel rejuvenated! Current health: %d\n", player->health);
            break;
        default:
            break;
    }
    printf("-------------------------------\n");
}

void show_choices() {
    printf("What would you like to do?\n");
    printf("1. Continue deeper into the forest\n");
    printf("2. Search for items\n");
    printf("3. Check your status\n");
}

int main() {
    Player player;
    int choice;

    srand(time(NULL));
    print_intro();
    create_player(&player);

    while (player.health > 0) {
        show_choices();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                encounter(&player);
                break;
            case 2:
                printf("You carefully search the area...\n");
                if (rand() % 2 == 0) {
                    printf("You found an extra item!\n");
                    player.items++;
                } else {
                    printf("Nothing found. Keep looking!\n");
                }
                break;
            case 3:
                show_status(&player);
                break;
            default:
                printf("Invalid choice! Please select 1, 2, or 3.\n");
                break;
        }
        if (player.health <= 0) {
            printf("Oh no! You have fallen in battle! Your adventure has ended.\n");
            break;
        }
    }

    printf("Thank you for playing 'Quest for the Golden Amulet'! Until next time!\n");
    return 0;
}