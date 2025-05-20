//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void displayRoom();
void displayMenu();
void checkChoice(int choice);
void gameOver();

int health = 100;
int playerScore = 0;
int roomNumber = 1;

int main() {
    printf("\n**************************************\n");
    printf("Welcome to the Text-Based Adventure Game\n");
    printf("**************************************\n\n");

    displayRoom();
    displayMenu();

    return 0;
}

void displayRoom() {
    printf("\n*************************\n");
    printf("           Room %d\n", roomNumber);
    printf("*************************\n");
    printf("\nYou see a dark room with two doors and a chest in the middle of the room.\n");
    printf("\nYour Health: %d\n", health);
    printf("Your Score: %d\n\n", playerScore);
}

void displayMenu() {
    int choice;
    printf("What do you want to do? Choose an option:\n");
    printf("1. Open the chest\n");
    printf("2. Go through the left door\n");
    printf("3. Go through the right door\n");
    printf("4. Quit the game\n");

    scanf("%d", &choice);
    checkChoice(choice);
}

void checkChoice(int choice) {
    switch(choice) {
        case 1:
            printf("\nYou open the chest and find a rare gem.\n");
            playerScore += 10;
            break;
        case 2:
            printf("\nYou walk through the left door and find yourself in a room filled with monsters.\n");
            health -= 20;
            if(health <= 0) {
                gameOver();
            }
            break;
        case 3:
            printf("\nYou walk through the right door and find a room with a treasure box.\n");
            playerScore += 50;
            break;
        case 4:
            printf("\nYou have quit the game.\n");
            exit(0);
            break;
        default:
            printf("\nInvalid option. Please choose again.\n");
            break;
    }
    displayRoom();
    displayMenu();
}

void gameOver() {
    printf("\n**************************\n");
    printf("\t GAME OVER\n");
    printf("**************************\n\n");
    printf("Your final score: %d\n", playerScore);
    exit(0);
}