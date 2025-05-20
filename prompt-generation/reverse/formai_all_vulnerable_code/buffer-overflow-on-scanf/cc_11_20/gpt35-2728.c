//FormAI DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the C Pattern Printing Program! Let's have fun!\n");

    int i, j, rows;

    printf("How many rows do you want to print? Enter a number between 5 and 20: ");
    scanf("%d", &rows);

    if (rows < 5 || rows > 20) {
        printf("Oops! That's not a valid number. Let's try again another time.\n");
        exit(0);
    }

    printf("Great! Get ready to see some awesome patterns!\n");

    // Pattern 1
    printf("\nPattern 1:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 2
    printf("\nPattern 2:\n");
    for (i = 0; i < rows; i++) {
        for (j = rows - 1; j > i; j--) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 3
    printf("\nPattern 3:\n");
    for (i = 0; i < rows; i++) {
        for (j = rows - 1; j > i; j--) {
            printf(" ");
        }
        for (j = 0; j <= 2 * i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 4
    printf("\nPattern 4:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (i = rows - 1; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\nThanks for using the C Pattern Printing Program! Hope you had fun!\n");

    return 0;
}