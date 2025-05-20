//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>

void printStatistics(int totalNumbers, int sum, float mean, int min, int max) {
    printf("\nStatistics:\n");
    printf("Total Numbers: %d\n", totalNumbers);
    printf("Sum: %d\n", sum);
    printf("Mean: %.2f\n", mean);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
}

void printNumberPattern(int n) {
    int i, j;
    int totalNumbers = 0, sum = 0, min = 0, max = 0;
    
    printf("Number Triangle Pattern:\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
            totalNumbers++;
            sum += j;

            // Initialize min and max
            if (i == 1 && j == 1) {
                min = j;
                max = j;
            } else {
                if (j < min) {
                    min = j;
                }
                if (j > max) {
                    max = j;
                }
            }
        }
        printf("\n");
    }

    // Calculate mean
    float mean = (float)sum / totalNumbers;

    // Print statistics
    printStatistics(totalNumbers, sum, mean, min, max);
}

int main() {
    int rows;

    printf("Enter the number of rows for the triangle pattern: ");
    scanf("%d", &rows);

    if (rows <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printNumberPattern(rows);

    return 0;
}