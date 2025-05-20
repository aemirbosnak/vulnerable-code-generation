//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: peaceful
#include <stdio.h>

int main() {
    int choice = 0;
    char field[10];
    printf("Welcome to the peaceful game of rock-paper-scissors!\n");

    while (choice!= 3) {
        printf("Choose your move: 1 for rock, 2 for paper, 3 for scissors\n");
        scanf("%d", &choice);

        if (choice == 1) {
            sprintf(field, "ROCK\n");
        } else if (choice == 2) {
            sprintf(field, "PAPER\n");
        } else if (choice == 3) {
            sprintf(field, "SCISSORS\n");
        } else {
            printf("Invalid choice!\n");
            continue;
        }

        printf("You chose %s\n", field);
        printf("Computer chose %s\n", "ROCK");

        if (choice == 1 && (choice + 1) % 3 == 0) {
            printf("You win!\n");
        } else if (choice == 1 && (choice + 2) % 3 == 0) {
            printf("Computer wins!\n");
        } else if (choice == 2 && (choice + 1) % 3 == 0) {
            printf("You win!\n");
        } else if (choice == 2 && (choice + 2) % 3 == 0) {
            printf("Computer wins!\n");
        } else if (choice == 3 && (choice + 1) % 3 == 0) {
            printf("You win!\n");
        } else if (choice == 3 && (choice + 2) % 3 == 0) {
            printf("Computer wins!\n");
        } else {
            printf("It's a tie!\n");
        }

        printf("\nDo you want to play again? (y/n)\n");
        scanf("%c", &choice);
        if (choice!= 'y') {
            break;
        }
    }

    return 0;
}