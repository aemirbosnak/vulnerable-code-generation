//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <player1> <player2>\n", argv[0]);
        exit(1);
    }

    srand(time(NULL));

    int player1, player2;

    if (sscanf(argv[1], "%d", &player1)!= 1) {
        fprintf(stderr, "Invalid player1 input: %s\n", argv[1]);
        exit(1);
    }

    if (sscanf(argv[2], "%d", &player2)!= 1) {
        fprintf(stderr, "Invalid player2 input: %s\n", argv[2]);
        exit(1);
    }

    printf("Player 1: %d\n", player1);
    printf("Player 2: %d\n", player2);

    int result = 0;

    while (1) {
        int choice1 = rand() % 3;
        int choice2 = rand() % 3;

        if (choice1 == choice2) {
            result = 0;
        } else if (choice1 > choice2) {
            result = -1;
        } else if (choice2 > choice1) {
            result = 1;
        }

        if (result!= 0) {
            break;
        }

        printf("Player 1: ");
        switch (choice1) {
            case 0:
                printf("Rock\n");
                break;
            case 1:
                printf("Paper\n");
                break;
            case 2:
                printf("Scissors\n");
                break;
        }

        printf("Player 2: ");
        switch (choice2) {
            case 0:
                printf("Rock\n");
                break;
            case 1:
                printf("Paper\n");
                break;
            case 2:
                printf("Scissors\n");
                break;
        }

        printf("Result: ");
        switch (result) {
            case 0:
                printf("Tie\n");
                break;
            case -1:
                printf("Player 2 wins\n");
                break;
            case 1:
                printf("Player 1 wins\n");
                break;
        }
    }

    return 0;
}