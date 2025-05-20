//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define ENEMY_HEALTH 50

typedef struct {
    int health;
    int attackPower;
} Character;

typedef struct {
    int health;
} Alien;

void print_intro() {
    printf("Welcome to the Shocking Space Adventure!\n");
    printf("You are an elite space explorer on a mission to investigate an alien planet.\n");
    printf("Your health: %d\n", MAX_HEALTH);
}

void encounter_alien(Character *player, Alien *alien) {
    printf("You encounter a terrifying alien creature!\n");
    printf("Alien Health: %d\n", alien->health);

    while (alien->health > 0 && player->health > 0) {
        printf("\n1. Attack Alien!\n2. Run Away!\n");
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("You attack the alien!\n");
            alien->health -= player->attackPower;
            printf("Alien health: %d\n", alien->health);
            if (alien->health > 0) {
                player->health -= 10; // Alien counters
                printf("The alien attacks back!\n");
                printf("Your health: %d\n", player->health);
            }
        } else if (choice == 2) {
            printf("You chose to run away! What a cowardly move!\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    
    if (player->health <= 0) {
        printf("You were defeated by the alien.\n");
        exit(0);
    } else if (alien->health <= 0) {
        printf("You have defeated the alien!\n");
        printf("But wait... what's this!\n");
    }
}

void shocking_twist() {
    printf("As you look around, the alien's body starts to dissolve into the ground...\n");
    printf("Suddenly, the ground shakes and bursts open, revealing a hidden spaceship!\n");
    printf("It is equipped with advanced technology and your ultimate escape!\n");
    printf("However, there's a catch...\n");
    printf("You must choose to enter the ship or look for more aliens to fight! What will you do?\n");
    
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You entered the ship and activated it!\n");
        printf("You escaped the planet, but not without leaving behind some dark secrets...\n");
    } else {
        printf("You chose to look for more aliens...\n");
        printf("But you encounter a swarm of them! There’s no escape!\n");
        exit(0);
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    Character player = { MAX_HEALTH, rand() % 20 + 10 }; // Random attack power
    Alien alien = { ENEMY_HEALTH };

    print_intro();
    encounter_alien(&player, &alien);
    shocking_twist();

    printf("Congratulations! You've made your choice and survived this shocking adventure.\n");
    printf("Your final health: %d\n", player.health);
    return 0;
}