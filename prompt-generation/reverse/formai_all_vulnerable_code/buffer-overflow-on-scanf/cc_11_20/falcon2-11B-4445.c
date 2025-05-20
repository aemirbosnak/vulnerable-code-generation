//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[100];
    int health;
    int level;
} Character;

typedef struct {
    char name[100];
    int damage;
    int defense;
} Weapon;

void printCharacter(Character c) {
    printf("Name: %s\nHealth: %d\nLevel: %d\n", c.name, c.health, c.level);
}

void printWeapon(Weapon w) {
    printf("Name: %s\nDamage: %d\nDefense: %d\n", w.name, w.damage, w.defense);
}

int main() {
    srand(time(NULL));
    Character player = { "Player", 100, 1 };
    Weapon sword = { "Sword of the Stars", 20, 5 };
    Weapon shield = { "Shield of the Future", 10, 10 };

    printf("Welcome to the Future Rogue-like Game!\n\n");
    printf("Your character:\n");
    printCharacter(player);
    printf("\n");

    printf("Your weapons:\n");
    printWeapon(sword);
    printf("\n");

    printf("You find a shield in a nearby chest!\n");
    printWeapon(shield);
    printf("\n");

    printf("You encounter a group of robots!\n");
    printf("There are %d robots with %d health each.\n", 3, 100);
    printf("What will you do?\n");
    printf("1. Attack with sword\n");
    printf("2. Attack with shield\n");
    printf("3. Do nothing\n");

    int choice = 0;
    while (choice!= 1 && choice!= 2 && choice!= 3) {
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        if (choice!= 1 && choice!= 2 && choice!= 3) {
            printf("Invalid choice, please try again.\n");
        }
    }

    if (choice == 1) {
        for (int i = 0; i < 3; i++) {
            Character enemy = { "Robot " + (i + 1), 100, 1 };
            printf("You attack the %d robot with your sword!\n", i + 1);
            printf("The robot has %d health left.\n", enemy.health);
            printf("What will you do?\n");
            printf("1. Attack with sword\n");
            printf("2. Attack with shield\n");
            printf("3. Do nothing\n");

            int choice = 0;
            while (choice!= 1 && choice!= 2 && choice!= 3) {
                printf("Please enter your choice: ");
                scanf("%d", &choice);
                if (choice!= 1 && choice!= 2 && choice!= 3) {
                    printf("Invalid choice, please try again.\n");
                }
            }

            if (choice == 1) {
                enemy.health -= sword.damage;
                printf("You deal %d damage to the robot.\n", sword.damage);
                if (enemy.health <= 0) {
                    printf("The robot is defeated!\n");
                    break;
                }
            }

            if (choice == 2) {
                enemy.health -= shield.damage;
                printf("You deal %d damage to the robot.\n", shield.damage);
                if (enemy.health <= 0) {
                    printf("The robot is defeated!\n");
                    break;
                }
            }
        }

        printf("You defeated all the robots!\n");
    } else if (choice == 2) {
        for (int i = 0; i < 3; i++) {
            Character enemy = { "Robot " + (i + 1), 100, 1 };
            printf("You attack the %d robot with your shield!\n", i + 1);
            printf("The robot has %d health left.\n", enemy.health);
            printf("What will you do?\n");
            printf("1. Attack with sword\n");
            printf("2. Attack with shield\n");
            printf("3. Do nothing\n");

            int choice = 0;
            while (choice!= 1 && choice!= 2 && choice!= 3) {
                printf("Please enter your choice: ");
                scanf("%d", &choice);
                if (choice!= 1 && choice!= 2 && choice!= 3) {
                    printf("Invalid choice, please try again.\n");
                }
            }

            if (choice == 1) {
                enemy.health -= sword.damage;
                printf("You deal %d damage to the robot.\n", sword.damage);
                if (enemy.health <= 0) {
                    printf("The robot is defeated!\n");
                    break;
                }
            }

            if (choice == 2) {
                enemy.health -= shield.damage;
                printf("You deal %d damage to the robot.\n", shield.damage);
                if (enemy.health <= 0) {
                    printf("The robot is defeated!\n");
                    break;
                }
            }
        }

        printf("You defeated all the robots!\n");
    } else if (choice == 3) {
        printf("You do nothing.\n");
    }

    return 0;
}