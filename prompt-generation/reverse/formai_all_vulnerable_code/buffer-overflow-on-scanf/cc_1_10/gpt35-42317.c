//FormAI DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include <stdio.h>

/* define the size of the pattern */
#define SIZE 8

/* function to print each row */
void print_row(int row, int player)
{
    /* alternate between players in each row */
    if (row % 2 == player) {
        for (int i = 0; i < SIZE; i++) {
            if (i <= row) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
    } else {
        for (int i = 0; i < SIZE; i++) {
            if (i >= row - player) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
    }
    printf("\n");
}

/* function to print the full pattern */
void print_pattern(int player)
{
    for (int i = 0; i < SIZE; i++) {
        print_row(i, player);
    }
}

/* main function to run the game */
int main()
{
    /* prompt the user to choose a player */
    printf("Welcome to C Pattern Printing!\n");
    printf("Choose your player (0 or 1): ");
    int player;
    scanf("%d", &player);

    /* print the pattern */
    print_pattern(player);

    /* print the winner */
    printf("Congratulations to Player %d!\n", player);

    return 0;
}