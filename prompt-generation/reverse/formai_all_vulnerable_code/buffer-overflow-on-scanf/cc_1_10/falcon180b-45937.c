//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to print a surrealistic pattern
void surrealisticPattern(int rows, int cols) {
    int i, j;
    srand(time(NULL)); // Seed the random number generator with the current time

    // Generate a random number between 1 and 4
    int pattern = rand() % 4 + 1;

    switch (pattern) {
        case 1: // Spiral pattern
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("*");
                }
            }
            break;
        case 2: // Diamond pattern
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    if (i == j) {
                        printf("*");
                    } else if (i == cols - j - 1) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;
        case 3: // Wave pattern
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("~");
                }
            }
            break;
        case 4: // Random pattern
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("%c", rand() % 26 + 'a');
                }
            }
            break;
    }
}

int main() {
    int rows, cols;

    // Get user input for the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Print the surrealistic pattern
    surrealisticPattern(rows, cols);

    return 0;
}