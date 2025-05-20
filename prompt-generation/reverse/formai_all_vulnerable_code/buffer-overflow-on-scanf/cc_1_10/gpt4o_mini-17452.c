//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>

// Function to compute factorial recursively
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to draw a tree structure representing recursion
void drawTree(int level) {
    if (level < 0) {
        return; // base case to stop recursion
    }
  
    // Draw the current level
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("|-- %d\n", level);
    
    // Recursive call to draw the next level
    drawTree(level - 1);
}

// Function to prompt user for input and compute factorial
void promptFactorial() {
    int number;
    printf("Enter a non-negative integer to compute its factorial: ");
    scanf("%d", &number);
  
    if (number < 0) {
        printf("! Invalid input. Please enter a non-negative integer.\n");
        return;
    }
  
    unsigned long long result = factorial(number);
    printf("Factorial of %d is: %llu\n", number, result);
}

// Main function
int main() {
    printf("Welcome to the Recursive Factorial Calculator!\n\n");
    while (1) {
        promptFactorial();
      
        char choice;
        printf("Would you like to calculate another factorial? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break; // Exit loop if user chooses not to continue
        }
    }
  
    printf("\nLet us visualize recursion through a tree structure:\n");
    int treeLevels = 5; // You can change the number of levels in the tree
    drawTree(treeLevels);
  
    printf("|-- 0\n"); // Final level to signify end of recursion
    printf("\nThank you for using the Recursive Factorial Calculator. Goodbye!\n");
    return 0;
}