//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main() {
    srand(time(0));
    int choice;
    char player_name[100];
    char computer_name[100];
    char result[100];
    char winner[100];

    printf("Hello, welcome to Rock, Paper, Scissors!\n\n");
    printf("Please enter your name: ");
    fgets(player_name, 100, stdin);
    printf("Welcome, %s!\n\n", player_name);

    printf("Choose your move: ");
    printf("1. Rock\n2. Paper\n3. Scissors\n");
    scanf("%d", &choice);

    if(choice == ROCK) {
        printf("You chose: Rock!\n");
    } else if (choice == PAPER) {
        printf("You chose: Paper!\n");
    } else if (choice == SCISSORS) {
        printf("You chose: Scissors!\n");
    } else {
        printf("Invalid input!\n");
        return 1;
    }

    switch(choice) {
        case ROCK:
            if(rand() % 2 == 0) {
                printf("The computer chose: Rock!\n");
            } else {
                printf("The computer chose: Paper!\n");
            }
            break;
        case PAPER:
            if(rand() % 2 == 0) {
                printf("The computer chose: Paper!\n");
            } else {
                printf("The computer chose: Scissors!\n");
            }
            break;
        case SCISSORS:
            if(rand() % 2 == 0) {
                printf("The computer chose: Scissors!\n");
            } else {
                printf("The computer chose: Rock!\n");
            }
            break;
        default:
            printf("Invalid input!\n");
            return 1;
    }

    printf("The results are in...\n");
    if(choice == ROCK && rand() % 2 == 0) {
        printf("The winner is: Computer!\n");
    } else if (choice == PAPER && rand() % 2 == 0) {
        printf("The winner is: Player!\n");
    } else if (choice == SCISSORS && rand() % 2 == 0) {
        printf("The winner is: Player!\n");
    } else if (choice == ROCK || choice == PAPER || choice == SCISSORS) {
        printf("The winner is: Tied!\n");
    } else {
        printf("Invalid input!\n");
    }
    printf("Thank you for playing!\n");

    return 0;
}