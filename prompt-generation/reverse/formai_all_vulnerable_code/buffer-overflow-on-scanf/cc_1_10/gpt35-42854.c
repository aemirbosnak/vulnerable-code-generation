//FormAI DATASET v1.0 Category: Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define player structure
typedef struct player {
    char name[20];
    int health;
    int attack;
    int defence;
} Player;

// Define monster structure
typedef struct monster {
    char name[20];
    int health;
    int attack;
    int defence;
} Monster;

// Function to generate random integer between min and max (inclusive)
int randomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed random generator
    srand(time(NULL));

    // Create player instance
    Player player;
    printf("Enter your name: ");
    scanf("%s", player.name);
    player.health = 100;
    player.attack = 10;
    player.defence = 5;

    // Create monster instance
    Monster monster;
    strcpy(monster.name, "Goblin");
    monster.health = 50;
    monster.attack = 8;
    monster.defence = 3;

    // Game loop
    int running = 1;
    while (running) {
        // Print player and monster status
        printf("\n%s:\n\tHealth: %d\n\tAttack: %d\n\tDefence: %d\n", player.name, player.health, player.attack, player.defence);
        printf("\n%s:\n\tHealth: %d\n\tAttack: %d\n\tDefence: %d\n", monster.name, monster.health, monster.attack, monster.defence);

        // Player attacks monster
        printf("\n%s attacks %s!", player.name, monster.name);
        int damage = randomInt(player.attack - monster.defence, player.attack);
        if (damage < 0) {
            damage = 0;
        }
        printf("\n%s takes %d damage!", monster.name, damage);
        monster.health -= damage;
        if (monster.health <= 0) {
            printf("\n%s is defeated!\n", monster.name);
            running = 0;
            continue;
        }

        // Monster attacks player
        printf("\n%s attacks %s!", monster.name, player.name);
        damage = randomInt(monster.attack - player.defence, monster.attack);
        if (damage < 0) {
            damage = 0;
        }
        printf("\n%s takes %d damage!", player.name, damage);
        player.health -= damage;
        if (player.health <= 0) {
            printf("\n%s is defeated!\n", player.name);
            running = 0;
            continue;
        }

        // Wait for user input
        printf("\nPress enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}