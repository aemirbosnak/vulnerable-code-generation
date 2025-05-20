//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int health = 100;
int enemy_health = 100;
int has_key = 0;

void delay(int);
void intro();
void start_game();
void room_one();
void room_two();

int main() {
    intro();
    start_game();
    return 0;
}

void delay(int milliseconds) {
    clock_t start_time = clock(); 
    while (clock() < start_time + milliseconds);
}

void intro() {
    printf("Welcome to the Text Adventure Game!\n");
    delay(2000);
    printf("\nIn this game, you will navigate through a series of rooms and face various challenges and enemies.\n");
    delay(3000);
    printf("\nYou will start with 100 health points and face an enemy in each room. Defeat each enemy to move on to the next room.\n");
    delay(4000);
    printf("\nGood luck and have fun!\n\n");
    delay(2000);
}

void start_game() {
    printf("You find yourself at the entrance of a dungeon. ");
    printf("You see two doors in front of you, one to the left and one to the right.\n");
    delay(3000);

    char answer[10];
    printf("Which door do you choose? (left/right): ");
    fgets(answer, 10, stdin);

    if (strcmp(answer, "left\n") == 0) {
        room_one();
    }
    else if (strcmp(answer, "right\n") == 0) {
        room_two();
    }
    else {
        printf("Sorry, I didn't understand that.\n");
        start_game();
    }
}

void room_one() {
    printf("You enter the room and see a goblin!\n");
    delay(2000);

    while (health > 0 && enemy_health > 0) {
        printf("Your Health: %d\n", health);
        printf("Enemy Health: %d\n", enemy_health);

        char attack_type[10];
        printf("What type of attack will you use? (sword/magic): ");
        fgets(attack_type, 10, stdin);

        if (strcmp(attack_type, "sword\n") == 0) {
            int damage = rand() % 10 + 1;
            printf("You hit the goblin with your sword for %d damage!\n", damage);
            enemy_health -= damage;
        }
        else if (strcmp(attack_type, "magic\n") == 0) {
            int damage = rand() % 20 + 1;
            printf("You cast a spell on the goblin for %d damage!\n", damage);
            enemy_health -= damage;
        }
        else {
            printf("Sorry, I didn't understand that.\n");
            continue;
        }

        if (enemy_health <= 0) {
            printf("Congratulations, you defeated the goblin!\n");
            has_key = 1;
            break;
        }

        int enemy_damage = rand() % 15 + 1;
        printf("The goblin hits you for %d damage!\n", enemy_damage);
        health -= enemy_damage;

        if (health <= 0) {
            printf("Game over, you have 0 health points left.\n");
            exit(0);
        }
    }

    if (has_key == 1) {
        printf("You found a key on the goblin's body! You can use it to unlock a door.\n");
        start_game();
    }
}

void room_two() {
    if (has_key == 0) {
        printf("The door is locked, you need a key to open it.\n");
        start_game();
    }
    else {
        printf("You enter the room and see a giant spider!\n");
        delay(2000);

        while (health > 0 && enemy_health > 0) {
            printf("Your Health: %d\n", health);
            printf("Enemy Health: %d\n", enemy_health);

            char attack_type[10];
            printf("What type of attack will you use? (sword/magic): ");
            fgets(attack_type, 10, stdin);

            if (strcmp(attack_type, "sword\n") == 0) {
                int damage = rand() % 15 + 1;
                printf("You hit the spider with your sword for %d damage!\n", damage);
                enemy_health -= damage;
            }
            else if (strcmp(attack_type, "magic\n") == 0) {
                int damage = rand() % 25 + 1;
                printf("You cast a spell on the spider for %d damage!\n", damage);
                enemy_health -= damage;
            }
            else {
                printf("Sorry, I didn't understand that.\n");
                continue;
            }

            if (enemy_health <= 0) {
                printf("Congratulations, you defeated the giant spider!\n");
                break;
            }

            int enemy_damage = rand() % 20 + 1;
            printf("The spider hits you for %d damage!\n", enemy_damage);
            health -= enemy_damage;

            if (health <= 0) {
                printf("Game over, you have 0 health points left.\n");
                exit(0);
            }
        }

        printf("You have successfully completed the game!\n");
    }
}