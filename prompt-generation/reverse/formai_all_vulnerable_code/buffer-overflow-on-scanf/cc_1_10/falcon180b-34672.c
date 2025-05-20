//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // size of the table
#define MIN 1 // minimum value for the table
#define MAX 100 // maximum value for the table

int main() {
    srand(time(NULL)); // seed the random number generator
    int table[SIZE][SIZE]; // 2D table to hold the numbers
    int i, j; // loop variables

    // initialize the table with random numbers
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            table[i][j] = rand() % (MAX - MIN + 1) + MIN; // generate a random number between MIN and MAX (inclusive)
        }
    }

    // print the table
    printf("Table:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    // ask the user for a number
    int num;
    printf("Enter a number between %d and %d:\n", MIN, MAX);
    scanf("%d", &num);

    // find the row and column of the number in the table
    int row, col;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (table[i][j] == num) {
                row = i;
                col = j;
                break;
            }
        }
    }

    // print the row and column of the number in the table
    printf("The number %d is in row %d and column %d\n", num, row, col);

    return 0;
}