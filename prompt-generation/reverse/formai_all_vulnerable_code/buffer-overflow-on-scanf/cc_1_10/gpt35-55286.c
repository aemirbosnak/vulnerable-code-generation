//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Welcome message
    printf("Welcome to the AMAZING C Pattern Printing Program!\n\n");

    // Getting user input for pattern size
    int size;
    printf("Please enter the size of pattern you want to print: ");
    scanf("%d", &size);

    // Making sure the pattern size is valid
    while (size <= 0) {
        printf("Invalid size! Please enter a positive integer: ");
        scanf("%d", &size);
    }

    // Printing the first half of the pattern
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        for (int k = 1; k <= (size - i); k++) {
            printf("  ");
        }

        for (int l = i; l >= 1; l--) {
            printf("%d ", l);
        }

        printf("\n");
    }

    // Printing the second half of the pattern
    for (int i = size; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        for (int k = 1; k <= (size - i); k++) {
            printf("  ");
        }

        for (int l = i; l >= 1; l--) {
            printf("%d ", l);
        }

        printf("\n");
    }

    // Closing message
    printf("\nThank you for using the AMAZING C Pattern Printing Program!\n");

    return 0;
}