//FormAI DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void handleError(int errorType) {
    // perform error handling based on errorType
    switch (errorType) {
        case 1:
            printf("Error: Division by zero!\n");
            exit(1);
        case 2:
            printf("Error: File not found!\n");
            exit(1);
        default:
            printf("Unknown error!\n");
            exit(1);
    }
}

int main() {
    int dividend, divisor, quotient;

    // Prompt user for dividend and divisor
    printf("Enter dividend: ");
    scanf("%d", &dividend);
    printf("Enter divisor: ");
    scanf("%d", &divisor);

    // Check for division by zero error and handle
    if (divisor == 0) {
        handleError(1);
    }

    // Perform division and catch any unexpected errors
    quotient = dividend / divisor;
    if (quotient == 0) {
        handleError(3);
    }

    // Open a file and catch any file not found errors
    FILE *fp = fopen("example.txt", "r");
    if (!fp) {
        handleError(2);
    }

    // Print the quotient and close the file
    printf("Quotient: %d\n", quotient);
    fclose(fp);

    return 0;
}