//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: complex
#include <stdio.h>

// Function to print pattern for a specific row
void printPatternRow(int row, int totalRows) {
    // Print leading spaces
    for (int space = 0; space < totalRows - row; ++space) {
        printf("  ");
    }

    // Print the pattern of increasing numbers
    for (int num = 1; num <= row; ++num) {
        printf("%d ", num);
    }

    // Print the pattern of decreasing numbers
    for (int num = row - 1; num >= 1; --num) {
        printf("%d ", num);
    }

    // Move to the next line after each row
    printf("\n");
}

// Function to print diamond-like structure
void printDiamond(int totalRows) {
    // Printing the upper half of the diamond
    for (int row = 1; row <= totalRows; ++row) {
        printPatternRow(row, totalRows);
    }

    // Printing the lower half of the diamond
    for (int row = totalRows - 1; row >= 1; --row) {
        printPatternRow(row, totalRows);
    }
}

// Function to print a complex pattern of stars and numbers
void printComplexPattern(int totalRows) {
    for (int row = 1; row <= totalRows; ++row) {
        // Print stars
        for (int star = 1; star <= row; ++star) {
            printf("* ");
        }
        // Print numbers
        for (int num = 1; num <= row; ++num) {
            printf("%d ", num);
        }
        printf("\n");
    }
    
    for (int row = totalRows - 1; row >= 1; --row) {
        // Print stars
        for (int star = 1; star <= row; ++star) {
            printf("* ");
        }
        // Print numbers
        for (int num = 1; num <= row; ++num) {
            printf("%d ", num);
        }
        printf("\n");
    }
}

// Function to draw a right-angled triangle of numbers
void printRightAngledTriangle(int totalRows) {
    for (int row = 1; row <= totalRows; ++row) {
        for (int num = 1; num <= row; ++num) {
            printf("%d ", num);
        }
        printf("\n");
    }
}

// Function to draw an inverted right-angled triangle of numbers
void printInvertedTriangle(int totalRows) {
    for (int row = totalRows; row >= 1; --row) {
        for (int num = 1; num <= row; ++num) {
            printf("%d ", num);
        }
        printf("\n");
    }
}

// Main function to drive the program
int main() {
    int totalRows;

    // Prompt the user for the number of rows for the patterns
    printf("Enter the number of rows for the pattern (1 - 10): ");
    scanf("%d", &totalRows);

    // Validate the input range
    if (totalRows < 1 || totalRows > 10) {
        printf("Please enter a valid number between 1 and 10.\n");
        return 1;
    }

    printf("\nDiamond Pattern:\n");
    printDiamond(totalRows);
    
    printf("\nComplex Pattern of Stars and Numbers:\n");
    printComplexPattern(totalRows);
    
    printf("\nRight-Angled Triangle Pattern:\n");
    printRightAngledTriangle(totalRows);
    
    printf("\nInverted Right-Angled Triangle Pattern:\n");
    printInvertedTriangle(totalRows);
    
    return 0;
}