//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    char playerName[20];
    printf("What is your name?\n");
    scanf("%s", playerName);

    printf("Welcome, %s!\n", playerName);

    int playerAge;
    printf("How old are you, %s?\n", playerName);
    scanf("%d", &playerAge);

    if (playerAge < 18) {
        printf("Sorry, %s, you are too young to play this game.\n", playerName);
        return 0;
    }

    printf("You are %d years old and ready to start your adventure!\n", playerAge);
    printf("You find yourself in a dark forest. What do you do?\n");
    printf("1. Walk forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You walk forward and come across a river. What do you do?\n");
            printf("1. Cross the river\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        case 2:
            printf("You turn left and find a cave. What do you do?\n");
            printf("1. Go inside\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        case 3:
            printf("You turn right and find a mountain. What do you do?\n");
            printf("1. Climb the mountain\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    int choice2;
    scanf("%d", &choice2);

    switch (choice2) {
        case 1:
            printf("You cross the river and find a treasure chest. What do you do?\n");
            printf("1. Open the chest\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        case 2:
            printf("You turn back and find a treasure chest. What do you do?\n");
            printf("1. Open the chest\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        case 3:
            printf("You go around and find a treasure chest. What do you do?\n");
            printf("1. Open the chest\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    int choice3;
    scanf("%d", &choice3);

    switch (choice3) {
        case 1:
            printf("You open the chest and find a golden key. What do you do?\n");
            printf("1. Use the key to unlock the door\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        case 2:
            printf("You turn back and find a door. What do you do?\n");
            printf("1. Use the key to unlock the door\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        case 3:
            printf("You go around and find a door. What do you do?\n");
            printf("1. Use the key to unlock the door\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    int choice4;
    scanf("%d", &choice4);

    switch (choice4) {
        case 1:
            printf("You use the key to unlock the door and find a treasure room. What do you do?\n");
            printf("1. Take the treasure\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        case 2:
            printf("You turn back and find a treasure room. What do you do?\n");
            printf("1. Take the treasure\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        case 3:
            printf("You go around and find a treasure room. What do you do?\n");
            printf("1. Take the treasure\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    int choice5;
    scanf("%d", &choice5);

    switch (choice5) {
        case 1:
            printf("You take the treasure and win the game!\n");
            break;
        case 2:
            printf("You turn back and find a treasure room. What do you do?\n");
            printf("1. Take the treasure\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        case 3:
            printf("You go around and find a treasure room. What do you do?\n");
            printf("1. Take the treasure\n");
            printf("2. Turn back\n");
            printf("3. Go around\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("Thank you for playing!\n");
    return 0;
}