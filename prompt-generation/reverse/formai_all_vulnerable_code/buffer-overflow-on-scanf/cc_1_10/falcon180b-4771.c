//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print pattern
void print_pattern(int rows, int cols, int pattern_type) {
    int i, j;
    switch(pattern_type) {
        case 1: // Random pattern
            for(i=0; i<rows; i++) {
                for(j=0; j<cols; j++) {
                    printf("%d ", rand_num(1, 10));
                }
                printf("\n");
            }
            break;
        case 2: // Diagonal pattern
            for(i=0; i<rows; i++) {
                for(j=0; j<cols; j++) {
                    if(i == j) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;
        case 3: // Checkerboard pattern
            for(i=0; i<rows; i++) {
                for(j=0; j<cols; j++) {
                    if((i + j) % 2 == 0) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;
        default: // Invalid pattern type
            printf("Invalid pattern type\n");
            break;
    }
}

int main() {
    int rows, cols, pattern_type;
    srand(time(NULL)); // Seed the random number generator with current time

    // Get user input for number of rows and columns
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Get user input for pattern type
    printf("Enter pattern type (1 - Random, 2 - Diagonal, 3 - Checkerboard): ");
    scanf("%d", &pattern_type);

    // Print pattern
    print_pattern(rows, cols, pattern_type);

    return 0;
}