//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a pattern of stars
void print_stars(int n) {
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    // Seed the random number generator with current time
    srand(time(NULL));

    // Get the number of rows and columns from user
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Print the pattern of stars
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Generate a random number between 1 and 3
            int num = rand_num(1, 3);

            // Print the pattern based on the random number
            switch (num) {
                case 1:
                    print_stars(1);
                    break;
                case 2:
                    print_stars(2);
                    break;
                case 3:
                    print_stars(3);
                    break;
            }
        }
    }

    return 0;
}