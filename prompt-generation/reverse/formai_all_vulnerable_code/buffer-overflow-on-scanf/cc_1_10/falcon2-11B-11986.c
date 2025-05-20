//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    char* city;
} player;

void main() {
    player player1;
    player player2;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please choose a player:\n");
    printf("1. Player 1\n");
    printf("2. Player 2\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You have chosen Player 1.\n");
            break;
        case 2:
            printf("You have chosen Player 2.\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    if (choice == 1) {
        printf("Player 1:\n");
        printf("Name: ");
        scanf("%s", player1.name);
        printf("Age: ");
        scanf("%d", &player1.age);
        printf("City: ");
        scanf("%s", player1.city);
    } else if (choice == 2) {
        printf("Player 2:\n");
        printf("Name: ");
        scanf("%s", player2.name);
        printf("Age: ");
        scanf("%d", &player2.age);
        printf("City: ");
        scanf("%s", player2.city);
    }

    printf("Let's start the adventure!\n");

    while (1) {
        printf("What do you want to do?\n");
        printf("1. Explore the town\n");
        printf("2. Go to the castle\n");
        printf("3. Rest in the inn\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        int choice2;
        scanf("%d", &choice2);

        switch (choice2) {
            case 1:
                printf("You are exploring the town.\n");
                break;
            case 2:
                printf("You are going to the castle.\n");
                break;
            case 3:
                printf("You are resting in the inn.\n");
                break;
            case 4:
                printf("You are quitting the game.\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}