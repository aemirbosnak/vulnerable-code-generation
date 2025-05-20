//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define MAX_ENERGY 100
#define MONSTER_DAMAGE 25
#define HEAL_AMOUNT 15
#define ENERGY_COST 20

typedef struct Player {
    int health;
    int energy;
    char *name;
} Player;

typedef struct Monster {
    char *type;
    int damage;
} Monster;

void intro() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Will you survive the night?\n");
    printf("Choose your player name: ");
}

void createPlayer(Player *p) {
    p->health = MAX_HEALTH;
    p->energy = MAX_ENERGY;
    printf("Your player is created with %d health and %d energy.\n", p->health, p->energy);
}

void encounterMonster(Player *p, Monster *m) {
    printf("A wild %s appears! It hits you for %d damage!\n", m->type, m->damage);
    p->health -= m->damage;
    printf("You now have %d health remaining.\n", p->health);
    
    if (p->health <= 0) {
        printf("You have been defeated...\n");
    }
}

void healPlayer(Player *p) {
    if (p->energy < ENERGY_COST) {
        printf("Not enough energy to heal!\n");
    } else {
        p->health += HEAL_AMOUNT;
        p->energy -= ENERGY_COST;
        if (p->health > MAX_HEALTH) {
            p->health = MAX_HEALTH;
        }
        printf("You heal for %d health. You now have %d health and %d energy.\n", HEAL_AMOUNT, p->health, p->energy);
    }
}

void rest(Player *p) {
    p->energy = MAX_ENERGY;
    printf("You take a break and regain full energy. Current energy: %d\n", p->energy);
}

void printStats(Player *p) {
    printf("Player Stats - Health: %d, Energy: %d\n", p->health, p->energy);
}

void randomEncounter(Player *p) {
    Monster monsters[] = {
        {"Zombie", MONSTER_DAMAGE},
        {"Ghost", MONSTER_DAMAGE},
        {"Werewolf", MONSTER_DAMAGE}
    };

    srand(time(NULL));
    int randomIndex = rand() % (sizeof(monsters) / sizeof(monsters[0]));

    encounterMonster(p, &monsters[randomIndex]);
}

int main() {
    Player player;
    char name[50];
    int choice;

    intro();
    scanf("%49s", name);
    player.name = name;
    createPlayer(&player);

    while (player.health > 0) {
        printf("\nWhat would you like to do?\n");
        printf("1. Explore\n");
        printf("2. Heal\n");
        printf("3. Rest\n");
        printf("4. Check Stats\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                randomEncounter(&player);
                break;
            case 2:
                healPlayer(&player);
                break;
            case 3:
                rest(&player);
                break;
            case 4:
                printStats(&player);
                break;
            case 5:
                printf("Exiting the simulator. Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }

        if (player.health <= 0) {
            printf("Game Over. You're dead!\n");
            break;
        }
    }

    return 0;
}