//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: artistic
#include <stdio.h>

void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printStars(int n) {
    for (int i = 0; i < n; i++) {
        printf("*");
    }
}

void printTree(int height) {
    int width = height * 2 - 1; // Width of the tree base
    // Print the leaf part of the tree
    for (int i = 0; i < height; i++) {
        // Calculate spaces and stars for each row
        int spaces = height - i - 1; 
        int stars = 2 * i + 1; 
        
        printSpaces(spaces);
        printStars(stars);
        
        printf("\n");
    }
    
    // Print trunk of the tree
    int trunkWidth = height / 2;
    int trunkHeight = height / 3;
    if (trunkHeight < 1) trunkHeight = 1; // Ensure trunk has at least 1 line

    printSpaces(height - trunkWidth);
    printStars(trunkWidth);
    
    printf("\n");
    
    for (int j = 1; j < trunkHeight; j++) {
        printSpaces(height - trunkWidth);
        printStars(trunkWidth);
        
        printf("\n");
    }
}

int main() {
    int height;
    printf("Enter the height of the tree: ");
    scanf("%d", &height);
    
    if (height < 3) {
        printf("Height should be at least 3 to create a recognizable tree!\n");
        return 1; // Exit if the height is less than 3
    }

    printf("\nHere's your tree of height %d:\n\n", height);
    printTree(height);
    
    printf("\nMay your wishes grow as high as this tree!\n");
    
    return 0;
}