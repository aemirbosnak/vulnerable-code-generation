//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The space adventurer, Romeo.
typedef struct Romeo {
    char name[20];
    int health;
    int age;
    int money;
} Romeo;

// The space adventurer, Juliet.
typedef struct Juliet {
    char name[20];
    int health;
    int age;
    int money;
} Juliet;

// The function that creates a new space adventurer.
void new_adventurer(char *name, int age, int money, Romeo *r) {
    strcpy(r->name, name);
    r->age = age;
    r->health = 100;
    r->money = money;
    printf("Welcome, Romeo!\n");
}

// The function that creates a new space adventurer.
void new_space_adventurer(char *name, int age, int money, Juliet *j) {
    strcpy(j->name, name);
    j->age = age;
    j->health = 100;
    j->money = money;
    printf("Welcome, Juliet!\n");
}

// The function that calculates the damage done to a space adventurer.
int damage_calculation(int damage, int defense) {
    int actual_damage = damage - defense;
    if (actual_damage < 0) {
        actual_damage = 0;
    }
    return actual_damage;
}

// The function that allows one adventurer to attack another.
void attack_adventurer(Romeo *r, Juliet *j) {
    int damage = rand() % 50 + 1;
    int actual_damage = damage_calculation(damage, j->health);
    j->health -= actual_damage;
    printf("%s attacked %s and dealt %d damage!\n", r->name, j->name, actual_damage);

    if (j->health <= 0) {
        printf("%s has died!\n", j->name);
    }
}

int main() {
    Romeo Romeo;
    Juliet Juliet;

    printf("Welcome to the Space Adventure game!\n");
    printf("First, let's create our heroes.\n");

    char name[20];
    int age;
    int money;

    // Create Romeo
    printf("Enter the name of Romeo:\n");
    scanf("%s", name);
    printf("Enter the age of Romeo:\n");
    scanf("%d", &age);
    printf("Enter the money of Romeo:\n");
    scanf("%d", &money);
    new_adventurer(name, age, money, &Romeo);

    // Create Juliet
    printf("Enter the name of Juliet:\n");
    scanf("%s", name);
    printf("Enter the age of Juliet:\n");
    scanf("%d", &age);
    printf("Enter the money of Juliet:\n");
    scanf("%d", &money);
    new_space_adventurer(name, age, money, &Juliet);

    printf("Now for the adventure!\n");

    while (1) {
        printf("What do you want to do?\n");
        printf("1) Attack\n");
        printf("2) Run\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            attack_adventurer(&Romeo, &Juliet);
            break;
        case 2:
            printf("You ran away!\n");
            exit(0);
        default:
            printf("Invalid choice, try again.\n");
            break;
        }
    }

    return 0;
}