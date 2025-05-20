//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Linus Torvalds
#include <stdio.h>

// Function prototypes
void print_diamond(int size);
void print_line(int total_width, int stars_count, int is_inverted);

int main() {
    int size;

    // Get user input for the size of the diamond
    printf("Enter the size of the diamond (positive integer): ");
    while (1) {
        int scanned = scanf("%d", &size);
        if (scanned == 1 && size > 0) {
            break; // Valid input
        } else {
            printf("Invalid input. Please enter a positive integer: ");
            while (getchar() != '\n'); // Clear invalid input
        }
    }

    // Print the diamond pattern
    print_diamond(size);

    return 0;
}

// Function to print the diamond pattern
void print_diamond(int size) {
    // Upper part of the diamond
    for (int i = 1; i <= size; i++) {
        print_line(size, i, 0); // Normal (non-inverted)
    }

    // Lower part of the diamond
    for (int i = size - 1; i >= 1; i--) {
        print_line(size, i, 1); // Inverted
    }
}

// Function to print a single line of the diamond
void print_line(int total_width, int stars_count, int is_inverted) {
    int spaces_count = total_width - stars_count;
    
    // Print leading spaces
    for (int j = 0; j < spaces_count; j++) {
        printf(" ");
    }

    // Print stars
    for (int k = 0; k < stars_count; k++) {
        printf("* ");
    }

    // New line after printing each line
    printf("\n");
}