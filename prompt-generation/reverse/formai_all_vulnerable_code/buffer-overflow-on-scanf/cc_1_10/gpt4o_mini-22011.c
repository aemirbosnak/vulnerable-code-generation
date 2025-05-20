//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>

// Function to print the pyramid pattern
void printPyramid(int rows) {
    int num;
    for (int i = 1; i <= rows; i++) {
        // Print leading spaces
        for (int j = i; j < rows; j++) {
            printf(" ");
        }
        // Print numbers in ascending order
        num = 1;
        for (int j = 1; j <= (2 * i - 1); j++) {
            if (j <= i) {
                printf("%d ", num);
                num++;
            } else {
                printf("%d ", --num);
            }
        }
        // Move to the next line
        printf("\n");
    }
}

// Function to validate user input
int getInput() {
    int rows;
    printf("Enter the number of rows for the pyramid (1-20): ");
    
    // Check if the input is an integer
    while (1) {
        if (scanf("%d", &rows) != 1 || rows < 1 || rows > 20) {
            printf("Invalid input! Please enter a valid number between 1 and 20: ");
            while (getchar() != '\n'); // clear the input buffer
        } else {
            break; // valid input is received
        }
    }
    
    return rows;
}

// Main function
int main() {
    int rows;
    
    // Get a valid number of rows from the user
    rows = getInput();
    
    // Print the pyramid pattern
    printf("\nGenerated Pyramid Pattern:\n");
    printPyramid(rows);
    
    return 0;
}