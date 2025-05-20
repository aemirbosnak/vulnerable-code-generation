//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// A happy little function to print a line of ASCII art
void print_happy_line(int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", '=');
    }
    printf("\n");
}

// A happy little function to print a happy little tree
void print_happy_tree(int height) {
    // Print the trunk
    print_happy_line(1);

    // Print the branches
    for (int i = 2; i <= height; i++) {
        // Print the spaces before the branches
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }

        // Print the branches
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("/");
        }

        // Print the spaces after the branches
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }

        // Print the newline
        printf("\n");
    }

    // Print the base of the tree
    print_happy_line(2 * height - 1);
}

int main() {
    // Get the height of the tree from the user
    int height;
    printf("Enter the height of the happy little tree: ");
    scanf("%d", &height);

    // Print the happy little tree
    print_happy_tree(height);

    return 0;
}