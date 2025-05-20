//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: innovative
#include <stdio.h>

// Function to print the pyramid pattern
void printPyramid(int rows) {
    // Loop to handle the number of rows
    for (int i = 1; i <= rows; i++) {
        // Print leading spaces
        for (int j = rows; j > i; j--) {
            printf(" ");
        }
        // Print stars for the pyramid
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print the mirrored pyramid pattern
void printMirroredPyramid(int rows) {
    // Loop to handle the number of rows
    for (int i = rows; i >= 1; i--) {
        // Print leading spaces
        for (int j = rows; j > i; j--) {
            printf(" ");
        }
        // Print stars for the mirrored pyramid
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print the hourglass shape combining the two patterns
void printHourglass(int rows) {
    printf("\nHourglass Pattern:\n");
    printPyramid(rows);
    printMirroredPyramid(rows);
}

// Function to get the pattern size from the user
int getPatternSize() {
    int size;
    printf("Enter the number of rows for the pyramid pattern: ");
    scanf("%d", &size);
    return size;
}

int main() {
    // Get the number of rows from the user
    int rows = getPatternSize();
    
    // Print the hourglass pattern
    printHourglass(rows);

    return 0;
}