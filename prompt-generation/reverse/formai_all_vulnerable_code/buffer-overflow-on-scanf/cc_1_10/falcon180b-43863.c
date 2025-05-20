//Falcon-180B DATASET v1.0 Category: Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int health;
    int attack;
} Character;

void print_character(Character *c) {
    printf("Name: %s\n", c->name);
    printf("Health: %d\n", c->health);
    printf("Attack: %d\n", c->attack);
}

int main() {
    srand(time(NULL));

    Character romeo = {"Romeo", rand() % 101, rand() % 51 + 50};
    Character juliet = {"Juliet", rand() % 101, rand() % 51 + 50};

    printf("Romeo's stats:\n");
    print_character(&romeo);
    printf("\n");

    printf("Juliet's stats:\n");
    print_character(&juliet);
    printf("\n");

    int choice;
    printf("Enter your choice (1 for Romeo, 2 for Juliet): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You chose Romeo.\n");
    } else if (choice == 2) {
        printf("You chose Juliet.\n");
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    int player_health = 100;
    int enemy_health = (choice == 1)? juliet.health : romeo.health;

    while (player_health > 0 && enemy_health > 0) {
        printf("Your health: %d\n", player_health);
        printf("Enemy health: %d\n", enemy_health);

        int attack_result = rand() % 101;
        if (attack_result <= romeo.attack) {
            printf("You attacked successfully!\n");
            enemy_health -= romeo.attack;
        } else {
            printf("You missed.\n");
        }

        attack_result = rand() % 101;
        if (attack_result <= juliet.attack) {
            printf("Enemy attacked successfully!\n");
            player_health -= juliet.attack;
        } else {
            printf("Enemy missed.\n");
        }
    }

    if (player_health <= 0) {
        printf("You died.\n");
    } else {
        printf("You won!\n");
    }

    return 0;
}