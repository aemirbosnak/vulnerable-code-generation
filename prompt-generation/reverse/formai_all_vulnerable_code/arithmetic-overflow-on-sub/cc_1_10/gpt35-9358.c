//FormAI DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h>

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // variable to keep track of the number of stars to be printed
    int starCount = 1;

    // loop through rows
    for (int i = 0; i < rows; i++) {

        // loop through columns
        for (int j = 0; j < (rows - i - 1); j++) {
            printf(" ");
        }

        // loop through stars
        for (int k = 0; k < starCount; k++) {
            printf("* ");
        }

        // print a new line character and increment starCount
        printf("\n");
        starCount += 2;
    }

    // reset starCount
    starCount = (rows * 2) - 3;

    // loop through rows in reverse
    for (int i = rows - 1; i > 0; i--) {

        // loop through columns
        for (int j = 0; j < (rows - i); j++) {
            printf(" ");
        }

        // loop through stars
        for (int k = 0; k < starCount; k++) {
            printf("* ");
        }

        // print a new line character and decrement starCount
        printf("\n");
        starCount -= 2;
    }

    return 0;
}