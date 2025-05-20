//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

//Function to generate random number
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

//Function to print a pattern
void print_pattern(int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int n, m;

    //Get user input for pattern size
    printf("Enter the size of the pattern (n): ");
    scanf("%d", &n);

    //Get user input for pattern type
    char pattern_type;
    printf("Enter the type of pattern (1 for square, 2 for triangle): ");
    scanf(" %c", &pattern_type);

    //Calculate the number of rows and columns for the pattern
    int rows, cols;
    switch (pattern_type) {
        case '1':
            rows = n;
            cols = n;
            break;
        case '2':
            rows = 2 * n - 1;
            cols = n;
            break;
        default:
            printf("Invalid pattern type.\n");
            return 0;
    }

    //Print the pattern
    printf("\nPrinting %c pattern:\n", pattern_type);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                printf("* ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    //Print the pattern with random numbers
    printf("\nPrinting %c pattern with random numbers:\n", pattern_type);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                printf("* ");
            } else {
                int num = rand_num(1, 10);
                printf("%d ", num);
            }
        }
        printf("\n");
    }

    return 0;
}