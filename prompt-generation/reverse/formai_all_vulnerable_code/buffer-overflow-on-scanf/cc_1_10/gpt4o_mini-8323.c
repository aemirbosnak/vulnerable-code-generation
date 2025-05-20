//GPT-4o-mini DATASET v1.0 Category: Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define MONSTER_HEALTH 30
#define TREASURE_VALUE 20

typedef struct Player {
    char name[50];
    int health;
    int score;
} Player;

typedef struct Monster {
    char name[20];
    int health;
} Monster;

void greet_player(Player *player) {
    printf("Welcome to the Dungeon, brave adventurer!\n");
    printf("Enter your name: ");
    fgets(player->name, 50, stdin);
    player->health = MAX_HEALTH;
    player->score = 0;
    printf("Hello %s, prepare yourself for the adventure!\n", player->name);
}

void print_status(Player player) {
    printf("\nStatus:\n");
    printf("Health: %d\n", player.health);
    printf("Score: %d\n", player.score);
}

void encounter_monster(Player *player) {
    Monster monster;
    snprintf(monster.name, sizeof(monster.name), "Goblin");
    monster.health = MONSTER_HEALTH;

    printf("\nA wild %s appears!\n", monster.name);

    while (monster.health > 0 && player->health > 0) {
        printf("You attack the %s!\n", monster.name);
        monster.health -= 10;

        if (monster.health > 0) {
            printf("The %s attacks you!\n", monster.name);
            player->health -= 15;
        } else {
            printf("You defeated the %s!\n", monster.name);
            player->score += 50;
        }

        print_status(*player);
    }

    if (player->health <= 0) {
        printf("You have been slain by the %s!\nGame Over.\n", monster.name);
        exit(0);
    }
}

void find_treasure(Player *player) {
    printf("\nYou found a treasure chest!\n");
    player->score += TREASURE_VALUE;
    printf("You gain %d points!\n", TREASURE_VALUE);
    print_status(*player);
}

void display_menu() {
    printf("\nChoose an action:\n");
    printf("1. Explore the dungeon\n");
    printf("2. Check Status\n");
    printf("3. Exit Game\n");
}

int main() {
    Player player;
    int choice;

    srand(time(NULL));

    greet_player(&player);

    while (player.health > 0) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rand() % 2 == 0) {
                    encounter_monster(&player);
                } else {
                    find_treasure(&player);
                }
                break;
            case 2:
                print_status(player);
                break;
            case 3:
                printf("Thank you for playing!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}