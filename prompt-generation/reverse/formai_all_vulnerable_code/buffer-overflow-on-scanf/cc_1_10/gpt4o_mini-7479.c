//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: random
#include <stdio.h>

// Function to draw the fractal tree recursively
void drawTree(int branchLength, int level) {
    if (level == 0) {
        return; // Base case: stop drawing when level is zero
    }
    
    // Print the current branch (to simulate drawing)
    for (int i = 0; i < branchLength; i++) {
        printf(" "); // Print leading spaces for alignment
    }
    
    printf("|\n"); // Draw the current branch

    // Calculate new branch lengths for the next level
    int newBranchLength = branchLength - 2;
    if (newBranchLength < 1) {
        return; // Prevent drawing branches that are too short
    }
    
    // Draw left and right branches recursively
    drawTree(newBranchLength, level - 1);
    
    // Draw space to simulate tree branching
    for (int i = 0; i < branchLength; i++) {
        printf(" ");
    }
    
    printf("|\n"); // Draw the uncurled right branch as well
    drawTree(newBranchLength, level - 1);
}

int main() {
    int levels;

    // Prompt user for the number of levels of the tree
    printf("Enter the number of levels for the fractal tree (1-10): ");
    scanf("%d", &levels);
    
    // Validate input
    if (levels < 1 || levels > 10) {
        printf("Invalid level! Please enter a number between 1 and 10.\n");
        return 1;
    }

    // Start drawing the fractal tree
    printf("\nFractal Tree:\n");
    drawTree(levels * 2, levels); // Start with an initial branch length
    
    return 0;
}