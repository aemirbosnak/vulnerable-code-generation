//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 50

typedef struct {
    char name[MAX_SIZE];
    int health;
    int damage;
    int speed;
    int defense;
} Player;

typedef struct {
    char name[MAX_SIZE];
    int health;
    int damage;
    int speed;
    int defense;
} Enemy;

void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void battle(Player *p, Enemy *e) {
    while (p->health > 0 && e->health > 0) {
        int p_damage = (rand() % p->damage) + 1;
        int e_damage = (rand() % e->damage) + 1;
        if (p->speed > e->speed) {
            printf("\nYour turn!\n");
            printf("Attack (1) or Defend (2)? ");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                e->health -= p_damage;
                printf("%s dealt %d damage to %s!\n", p->name, p_damage, e->name);
            } else if (choice == 2) {
                p->defense += 3;
                printf("%s increased their defense!\n", p->name);
            } else {
                printf("Invalid choice! Please try again.\n");
            }
            delay(1);
            printf("%s's turn!\n", e->name);
            if (e->damage > p->defense) {
                p->health -= (e_damage - p->defense);
                printf("%s dealt %d damage to %s! %s's health is now %d.\n", e->name, (e_damage - p->defense), p->name, p->name, p->health);
            } else {
                printf("%s's defense was too high! No damage dealt.\n", p->name);
            }
            p->defense = 0;
        } else {
            printf("%s's turn!\n", e->name);
            if (e->damage > p->defense) {
                p->health -= (e_damage - p->defense);
                printf("%s dealt %d damage to %s! %s's health is now %d.\n", e->name, (e_damage - p->defense), p->name, p->name, p->health);
            } else {
                printf("%s's defense was too high! No damage dealt.\n", p->name);
            }
            delay(1);
            printf("\nYour turn!\n");
            printf("Attack (1) or Defend (2)? ");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                e->health -= p_damage;
                printf("%s dealt %d damage to %s!\n", p->name, p_damage, e->name);
            } else if (choice == 2) {
                p->defense += 3;
                printf("%s increased their defense!\n", p->name);
            } else {
                printf("Invalid choice! Please try again.\n");
            }
            p->defense = 0;
        }
    }
    if (p->health <= 0) {
        printf("%s has been defeated!\n", p->name);
    } else {
        printf("%s has been defeated!\n", e->name);
    }
}

void intro() {
    printf("\n\nWelcome to Procedural Space Adventure!\n\n");
    delay(1);
    printf("You are the captain of the spaceship Pathfinder,\n");
    printf("and you are on a mission to explore the Alpha Centauri system.\n");
    delay(1);
    printf("Your crew consists of you, your co-pilot, and your first mate.\n");
    delay(1);
    printf("You have just arrived at the first planet in the system, Proxima b,\n");
    printf("and you are about to embark on an exciting adventure!\n\n");
}

void planet_menu() {
    printf("Please select what you want to do on this planet:\n");
    printf("1. Explore the planet\n");
    printf("2. Gather resources\n");
    printf("3. Talk to the locals\n");
    printf("4. Leave the planet\n");
    printf("Your choice: ");
}

int main() {
    srand(time(NULL));
    int choice;
    int resources = 0;
    char local[MAX_SIZE];
    Player p = {"Captain", 100, 25, 10, 0};
    Enemy e = {"Alien", 50, 20, 5, 3};
    intro();
    while (1) {
        planet_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("You explore the planet and find an alien!\n");
                delay(1);
                printf("You must battle the alien!\n");
                battle(&p, &e);
                if (p.health > 0) {
                    printf("You won the battle!\n");
                } else {
                    printf("You lost the battle. Game over!\n");
                    exit(0);
                }
                break;
            case 2:
                resources += (rand() % 10) + 1;
                printf("You gather resources. You now have %d resources.\n", resources);
                break;
            case 3:
                printf("You talk to the locals. They tell you their name is...\n");
                delay(1);
                printf("'%s'! They also give you some advice about the planet.\n", local);
                break;
            case 4:
                printf("You leave the planet and continue your journey.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}