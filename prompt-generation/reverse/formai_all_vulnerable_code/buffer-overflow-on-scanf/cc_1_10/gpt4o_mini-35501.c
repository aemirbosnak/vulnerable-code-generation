//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define MAX_TREASURE 1000

typedef struct {
    int currentHealth;
    int treasure;
    int position;
} Player;

void initializePlayer(Player *p) {
    p->currentHealth = MAX_HEALTH;
    p->treasure = 0;
    p->position = 0;
}

void printStatus(Player *p) {
    printf("Health: %d\n", p->currentHealth);
    printf("Treasure: %d\n", p->treasure);
}

void encounterTrap(Player *p) {
    int damage = rand() % 20 + 5; // Random damage between 5-25
    p->currentHealth -= damage;
    printf("You've triggered a trap! You take %d damage.\n", damage);
    if (p->currentHealth <= 0) {
        printf("You've succumbed to your injuries. Game Over!\n");
        exit(0);
    }
}

void findTreasure(Player *p) {
    int found = rand() % 200; // Random treasure found between 0-199
    p->treasure += found;
    printf("You found %d gold pieces!\n", found);
}

void encounterMonster(Player *p) {
    int monsterDamage = rand() % 30 + 10; // Random monster damage between 10-40
    p->currentHealth -= monsterDamage;
    printf("A monster attacks you! You take %d damage.\n", monsterDamage);
    if (p->currentHealth <= 0) {
        printf("You have been slain by the monster. Game Over!\n");
        exit(0);
    }
}

void interactWithCave(Player *p) {
    int event = rand() % 3; // Three types of events: 0 = trap, 1 = treasure, 2 = monster
    if (event == 0) {
        encounterTrap(p);
    } else if (event == 1) {
        findTreasure(p);
    } else {
        encounterMonster(p);
    }
}

void move(Player *p) {
    char direction;
    printf("Enter direction to move (n/s/e/w): ");
    scanf(" %c", &direction);

    if (direction == 'n' || direction == 's' || direction == 'e' || direction == 'w') {
        p->position++;
        printf("You move to position %d.\n", p->position);
        interactWithCave(p);
    } else {
        printf("Invalid direction! Try again.\n");
    }
}

int main() {
    Player player;
    initializePlayer(&player);
    
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Cave Explorer!\n");
    printf("Your goal is to explore the cave, find treasure, and survive!\n");
    
    while (player.currentHealth > 0) {
        printStatus(&player);
        move(&player);
        printf("\n");
    }

    return 0;
}