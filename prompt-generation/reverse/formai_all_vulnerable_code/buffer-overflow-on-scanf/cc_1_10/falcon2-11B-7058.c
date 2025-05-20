//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage();
void makeHauntedHouse();
void move();
void findItem();
void fight();
void win();
void lose();
void roomDescription();
void endGame();

int main() {
    welcomeMessage();
    makeHauntedHouse();
    while (1) {
        roomDescription();
        printf("What would you like to do?\n");
        printf("1. Move\n");
        printf("2. Find item\n");
        printf("3. Fight\n");
        printf("4. Quit\n");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                move();
                break;
            case 2:
                findItem();
                break;
            case 3:
                fight();
                break;
            case 4:
                endGame();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void welcomeMessage() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Your mission is to escape from the haunted house.\n");
    printf("Good luck!\n");
}

void makeHauntedHouse() {
    srand(time(NULL));
    int numRooms = rand() % 10 + 1;
    int numDoors = rand() % 10 + 1;
    int numItems = rand() % 10 + 1;
    int numEnemies = rand() % 10 + 1;

    printf("The Haunted House has %d rooms, %d doors, %d items, and %d enemies.\n", numRooms, numDoors, numItems, numEnemies);
}

void roomDescription() {
    int roomNumber = rand() % 10 + 1;
    int doorNumber = rand() % 10 + 1;
    int itemNumber = rand() % 10 + 1;
    int enemyNumber = rand() % 10 + 1;

    printf("You are in Room %d.\n", roomNumber);
    printf("There is a door to Room %d.\n", doorNumber);
    printf("There is an item in Room %d.\n", itemNumber);
    printf("There is an enemy in Room %d.\n", enemyNumber);
}

void move() {
    printf("You move to Room %d.\n", rand() % 10 + 1);
}

void findItem() {
    printf("You find a key in Room %d.\n", rand() % 10 + 1);
}

void fight() {
    printf("You fight the enemy in Room %d.\n", rand() % 10 + 1);
    printf("You win!\n");
}

void win() {
    printf("Congratulations! You have escaped from the Haunted House!\n");
}

void lose() {
    printf("Game over. You failed to escape from the Haunted House.\n");
}

void endGame() {
    printf("Do you want to play again? (y/n): ");
    char playAgain;
    scanf(" %c", &playAgain);
    if (playAgain == 'y') {
        makeHauntedHouse();
    } else {
        printf("Thank you for playing!\n");
    }
}