//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntro();
int choosePath();
void travel(int);
void spaceBattle(int);
void displayEnd(int);

int main() {
    printIntro();
    int path = choosePath();
    travel(path);
    spaceBattle(path);
    displayEnd(path);
    return 0;
}

void printIntro() {
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are the captain of a spaceship and your mission is to defend the galaxy.\n");
    printf("Choose your path carefully and make decisions that will impact the fate of the universe.\n\n");
}

int choosePath() {
    int choice;
    printf("Choose your path:\n");
    printf("1. The peaceful planet of Zorax\n");
    printf("2. The dangerous asteroid belt of Colossus\n");
    printf("3. The mysterious planet of Orion\n");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

void travel(int path) {
    printf("You set a course for ");
    switch(path) {
        case 1:
            printf("Zorax.\n");
            break;
        case 2:
            printf("Colossus.\n");
            break;
        case 3:
            printf("Orion.\n");
            break;
        default:
            printf("unknown territory.\n");
            break;
    }
    printf("As you make your way through space, you encounter several obstacles and challenges.\n");
    srand(time(NULL));
    int event = rand() % 4;
    switch(event) {
        case 0:
            printf("You encounter an asteroid field and must dodge the flying debris.\n");
            break;
        case 1:
            printf("Your navigation system malfunctions, causing you to drift off course.\n");
            break;
        case 2:
            printf("You discover a wormhole that transports you to a distant part of the galaxy.\n");
            break;
        case 3:
            printf("You come across a distress signal and decide to investigate.\n");
            break;
    }
    printf("\n");
}

void spaceBattle(int path) {
    int enemyHealth;
    switch(path) {
        case 1:
            enemyHealth = 50;
            break;
        case 2:
            enemyHealth = 75;
            break;
        case 3:
            enemyHealth = 100;
            break;
    }
    printf("You come face-to-face with an enemy spaceship!\n");
    printf("You must battle it out to determine the fate of the universe.\n");
    int playerHealth = 100; 
    while(playerHealth > 0 && enemyHealth > 0) {
        printf("Your health: %d   Enemy health: %d\n", playerHealth, enemyHealth);
        printf("Enter your attack (1-10): ");
        int attack;
        scanf("%d", &attack);
        if (attack < 1 || attack > 10) {
            printf("Invalid attack!\n");
        } else {
            enemyHealth -= attack;
            if (enemyHealth <= 0) {
                break;
            }
            int enemyAttack = rand() % 10 + 1;
            playerHealth -= enemyAttack;
            printf("The enemy attacks you for %d damage!\n", enemyAttack);
            if (playerHealth <= 0) {
                break;
            }
            printf("\n");
        }
    }
    printf("\n");
}

void displayEnd(int path) {
    switch(path) {
        case 1:
            printf("Congratulations, you saved the peaceful planet of Zorax!\n");
            break;
        case 2:
            printf("Victory! You defeated the enemies lurking in the asteroid belt of Colossus!\n");
            break;
        case 3:
            printf("You have uncovered the secrets of the mysterious planet of Orion!\n");
            break;
    }
    printf("Thanks for playing the Procedural Space Adventure!\n");
}