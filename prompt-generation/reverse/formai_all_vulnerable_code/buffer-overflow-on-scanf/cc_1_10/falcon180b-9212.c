//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 10

void print_table(int table[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int table[ROWS][COLS];
    int i, j, count = 0;
    srand(time(NULL));

    // Fill the table with random numbers between 1 and 100
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            table[i][j] = rand() % 100 + 1;
        }
    }

    // Print the table
    printf("Periodic Table:\n");
    print_table(table);

    // Ask the user to guess an element
    int element;
    do {
        printf("\nGuess an element (1-%d): ", 100);
        scanf("%d", &element);
        if (element < 1 || element > 100) {
            printf("Invalid input. Please try again.\n");
        }
    } while (element < 1 || element > 100);

    // Check if the element is in the table
    int found = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (table[i][j] == element) {
                printf("\nElement found at row %d, column %d.\n", i+1, j+1);
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (!found) {
        printf("Element not found in the table.\n");
    }

    return 0;
}