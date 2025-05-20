//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char playerName[50];
    int playerPoints = 0;

    printf("Welcome to the Dungeon Adventure Game!\n\n");
    printf("What's your name, adventurer?\n");
    scanf("%s", playerName);

    printf("\n\nWell, %s, welcome to the dungeon!\n", playerName);
    printf("Your mission is to find the hidden treasure.\n");
    printf("You start with %d points.\n", playerPoints);
    printf("Good luck!\n\n");

    //First room
    printf("You find yourself in a room with three doors.\n");
    printf("Do you enter door 1, 2, or 3?\n");
    int doorChoice;
    scanf("%d", &doorChoice);

    if (doorChoice == 1) {
        printf("You chose door 1. You enter a dark room.\n");
        printf("As you walk forward a pit opens up underneath you.\n");
        printf("You lose 10 points.\n");
        playerPoints -= 10;
    }
    else if (doorChoice == 2) {
        printf("You chose door 2. You enter a room filled with gold!\n");
        printf("But beware! A dragon is guarding it.\n");
        printf("You must defeat the dragon to get the gold.\n");
        playerPoints += 20; //Reward for defeating the dragon
    }
    else if (doorChoice == 3) {
        printf("You chose door 3. You enter a room with a chest.\n");
        printf("You open the chest and find 5 points!\n");
        playerPoints += 5;
    }
    else {
        printf("Invalid choice. You lose a turn.\n");
    }
    
    //Second room
    printf("\n\nYou move on to the next room.\n");
    printf("This room has two doors.\n");
    printf("Do you enter door 1 or 2?\n");
    scanf("%d", &doorChoice);

    if (doorChoice == 1) {
        printf("You chose door 1. You enter a room with a riddle.\n");
        printf("You need to solve the riddle to get the treasure.\n");
        printf("Riddle: What has a face but no eyes, hands but no arms?\n");
        char riddleAnswer[50];
        scanf("%s", riddleAnswer);
        if (strcmp(riddleAnswer, "clock") == 0) {
            printf("Correct! You get 15 points!\n");
            playerPoints += 15;
        } else {
            printf("Sorry, that's incorrect. You lose a turn.\n");
        }
    }
    else if (doorChoice == 2) {
        printf("You chose door 2. You enter a room with a maze.\n");
        printf("You have to find your way through the maze to get the treasure.\n");
        printf("You make it through the maze and get 10 points!\n");
        playerPoints += 10;
    }
    else {
        printf("Invalid choice. You lose a turn.\n");
    }

    //Final room
    printf("\n\nYou've made it to the final room.\n");
    printf("There's only one door left.\n");
    printf("Do you enter?\n");
    char finalChoice[10];
    scanf("%s", finalChoice);
    if (strcmp(finalChoice, "yes") == 0) {
        printf("You've done it! You found the treasure and win!\n");
        printf("Your final point total is %d.\n", playerPoints);
    } else {
        printf("You're so close, yet so far. Game over.\n");
        printf("Your final point total is %d.\n", playerPoints);
    }

    return 0;
}