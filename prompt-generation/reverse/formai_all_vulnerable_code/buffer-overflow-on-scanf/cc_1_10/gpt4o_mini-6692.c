//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A visionary program that builds and prints a pyramid of stars
// using recursive functions. Imagine building dreams with each star,
// layer upon layer, until you reach the sky.

void print_spaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

void print_stars(int n) {
    for (int i = 0; i < n; i++) {
        printf("* ");
    }
}

// Recursive function to build and print the pyramid
void print_pyramid(int level, int max_levels) {
    if (level > max_levels) {
        return; // Base case: If level exceeds max_levels, stop the recursion
    }
    
    // Print leading spaces for the current level
    print_spaces(max_levels - level);
    
    // Print stars for the current level
    print_stars(level);
    
    // Print a new line after each level
    printf("\n");
    
    // Recursive call to print the next level of the pyramid
    print_pyramid(level + 1, max_levels);
}

// Function to initiate the pyramid printing process
void start_pyramid(int levels) {
    if (levels <= 0) {
        printf("Please enter a positive integer for the number of levels.\n");
        return; 
    }
    printf("Constructing a pyramid with %d levels...\n\n", levels);
    print_pyramid(1, levels);
}

int main() {
    int levels;

    // The visionary journey begins here
    printf("Welcome to the Star Pyramid Constructor!\n");
    printf("Enter the number of levels for your radiant pyramid: ");
    scanf("%d", &levels);
    
    start_pyramid(levels);
    
    printf("\nYour sky is now filled with stars! Illuminate your dreams.\n");
    return 0;
}