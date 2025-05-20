//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

// Function to print a given pattern
void printPattern(int n, int m) {
    int i, j;

    // Iterate through each row
    for (i = 0; i < n; i++) {

        // Iterate through each column
        for (j = 0; j < m; j++) {

            // If the current cell is in the first row, print the first character of the pattern
            if (i == 0 && j == 0) {
                printf("%c", 65 + (i % 6));
            }

            // If the current cell is in the first column, print the second character of the pattern
            else if (i == 0 && j % 6!= 0) {
                printf("%c", 65 + ((i + j) % 6));
            }

            // If the current cell is in the last column, print the third character of the pattern
            else if (i % 6 == 0 && j == m - 1) {
                printf("%c", 65 + (i / 6));
            }

            // If the current cell is in the last row, print the fourth character of the pattern
            else if (i == n - 1 && j % 6!= 0) {
                printf("%c", 65 + ((i - 1 + j) % 6));
            }

            // If the current cell is in the middle of the pattern, print a space character
            else {
                printf(" ");
            }
        }

        // Move to the next line
        printf("\n");
    }
}

int main() {
    int n, m;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    // Check if the number of columns is valid
    if (m % 6!= 0) {
        printf("Error: The number of columns must be a multiple of 6.\n");
        return 1;
    }

    // Print the pattern
    printPattern(n, m);

    return 0;
}