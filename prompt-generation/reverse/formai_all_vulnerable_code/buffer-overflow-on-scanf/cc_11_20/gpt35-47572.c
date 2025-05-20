//FormAI DATASET v1.0 Category: Table Game ; Style: random
#include <stdio.h>

int main() {

    // Declare variables
    int table[10][10];
    int i,j;

    // Populate table with random numbers between 1 and 10
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            table[i][j] = rand() % 10 + 1;
        }
    }

    // Print table header
    printf("   ");
    for(i=1; i<=10; i++) {
        printf("%d  ", i);
    }
    printf("\n");

    // Print table rows with row numbers as headers
    for(i=0; i<10; i++) {
        printf("%d  ", i+1);
        for(j=0; j<10; j++) {
            printf("%d  ", table[i][j]);
        }
        printf("\n");
    }

    // Ask user for a pair of coordinates
    int row1, col1, row2, col2;
    printf("Enter the coordinates of two cells separated by a space (e.g. 3 4 5 6): ");
    scanf("%d%d%d%d", &row1, &col1, &row2, &col2);

    // Check if coordinates are valid
    if(row1 < 1 || row1 > 10 || col1 < 1 || col1 > 10 || row2 < 1 || row2 > 10 || col2 < 1 || col2 > 10) {
        printf("Invalid coordinates!\n");
        return 0;
    }

    // Swap values at the given coordinates
    int temp = table[row1-1][col1-1];
    table[row1-1][col1-1] = table[row2-1][col2-1];
    table[row2-1][col2-1] = temp;

    // Print updated table
    printf("   ");
    for(i=1; i<=10; i++) {
        printf("%d  ", i);
    }
    printf("\n");
    for(i=0; i<10; i++) {
        printf("%d  ", i+1);
        for(j=0; j<10; j++) {
            printf("%d  ", table[i][j]);
        }
        printf("\n");
    }

    return 0;
}