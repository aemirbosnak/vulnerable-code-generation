//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: medieval
#include <stdio.h>

void printStar(int n);

int main() {
    // Proclaim the beginning of the star pattern drawing
    printf("Gather ye round, noble lords and ladies,\n");
    printf("For we shall craft a starry tapestry of grandeur!\n\n");

    int height;
    printf("Enter the height of thy starry tower (an odd integer): ");
    scanf("%d", &height);

    // Ensure the height is an odd number for a grand design
    if (height % 2 == 0) {
        printf("Verily, thou must input an odd integer!\n");
        return 1; // Exit if the input is not valid
    }

    // Bestow upon the drawing the power of the stars
    printf("\nBehold the majestic starry tower:\n");
    printStar(height);

    // Honor the completion of the pattern
    printf("\nThus concludes our visual ode to the heavens!\n");
    return 0;
}

// Function to print the starry pattern
void printStar(int n) {
    int spaces; // to hold the number of spaces
    int stars;  // to hold the number of stars

    // Ascend through the heights, creating the upper part of the tower
    for (int i = 0; i < n; i++) {
        spaces = (n - i) / 2; // Calculate spaces for centering stars
        stars = i * 2 + 1;    // Calculate the number of stars to print

        // Print leading spaces
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }

        // Print stars
        for (int j = 0; j < stars; j++) {
            printf("*");
        }

        // Move to the next line after each row
        printf("\n");
    }

    // Descend through the heights, creating the lower part of the tower
    for (int i = n - 2; i >= 0; i--) {
        spaces = (n - i) / 2; // Calculate spaces for centering stars
        stars = i * 2 + 1;    // Calculate the number of stars to print

        // Print leading spaces
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }

        // Print stars
        for (int j = 0; j < stars; j++) {
            printf("*");
        }

        // Move to the next line after each row
        printf("\n");
    }
}