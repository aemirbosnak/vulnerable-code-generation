//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntro();
void displayMenu();
void startGame();
int rollDice();
int calculateDamage(int diceRoll);

int main() {
    printIntro();
    displayMenu();
    return 0;
}

void printIntro() {
    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("You are a space explorer on a mission to find new planets.\n");
    printf("As you journey through space, you will encounter many dangers and challenges.\n");
    printf("Your goal is to make it to the end of your journey and discover new planets to inhabit.\n\n");
}

void displayMenu() {
    int choice = 0;
    printf("What would you like to do?\n");
    printf("1. Start a new game\n");
    printf("2. Quit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            startGame();
            break;
        case 2:
            printf("Thanks for playing Procedural Space Adventure!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            displayMenu();
            break;
    }
}

void startGame() {
    int health = 100;
    int distance = 0;
    int planetsVisited = 0;
    srand(time(NULL));

    printf("\nLet's begin your journey!\n");
    while (health > 0 && distance < 100) {
        int diceRoll = rollDice();
        printf("You rolled a %d!\n", diceRoll);
        int damage = calculateDamage(diceRoll);
        health = health - damage;
        if (health <= 0) {
            break;
        }
        distance += 10;
        printf("You have traveled %d light years.\n", distance);

        if (distance % 30 == 0) {
            planetsVisited++;
            printf("You have discovered a new planet! There are now %d planets in your database.\n", planetsVisited);
        }
    }

    if (health <= 0) {
        printf("You have died! Game over.\n");
    } else {
        printf("You have reached your destination! Congratulations!\n");
    }

    displayMenu();
}

int rollDice() {
    int roll = rand() % 6 + 1;
    return roll;
}

int calculateDamage(int diceRoll) {
    int damage = diceRoll * 10 - 5;
    if (damage < 0) {
        damage = 0;
    }
    return damage;
}