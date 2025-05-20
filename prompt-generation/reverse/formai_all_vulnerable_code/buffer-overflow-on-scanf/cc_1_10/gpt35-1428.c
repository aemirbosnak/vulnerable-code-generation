//FormAI DATASET v1.0 Category: Table Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_table(int *table, int size) {
    printf("Current table:\n");
    for (int i = 0; i < size; i++) {
        if (table[i] == 1) {
            printf("[%d] ", i+1);
        } else {
            printf("%d ", i+1);
        }
    }
    printf("\n");
}

int main() {
    int size;
    do {
        printf("Enter the size of the table (even number greater than 0): ");
        scanf("%d", &size);
    } while (size <= 0 || size % 2 != 0);  // ensure size is even and greater than 0

    int *table = (int *) calloc(size, sizeof(int));  // initialize table with 0s
    int turns = size/2;  // number of turns player gets
    int points = 0;  // current number of points player has
    int current_player = 1;  // player 1 goes first

    srand(time(NULL));  // seed random number generator

    while (turns > 0) {
        printf("\nPlayer %d's turn\n", current_player);

        int choice;
        do {
            display_table(table, size);
            printf("Enter the number you want to turn over: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > size || table[choice-1] != 0);  // ensure choice is valid

        // randomly generate a number to compare with choice
        int random_num = rand() % size + 1;
        printf("Random number generated: %d\n", random_num);

        if (choice == random_num) {
            printf("Congratulations! You get a point!\n");
            points++;
        } else {
            printf("Sorry, no points awarded this turn.\n");
        }

        table[choice-1] = 1;  // mark number as turned over

        turns--;
        if (turns > 0) {
            printf("You have %d turn(s) left.\n", turns);
        }
        if (current_player == 1) {
            current_player = 2;
        } else {
            current_player = 1;
        }
    }

    printf("\nGame over!\nYou scored %d point(s)!\n", points);

    free(table);  // free allocated memory

    return 0;
}