//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Function to print the header of the pattern
void printHeader(int size) {
    printf("+");
    for (int i = 0; i < size - 2; i++) {
        printf("--+");
    }
    printf("--+\n");
}

// Function to print the body of the pattern
void printBody(int size, int numSpaces) {
    for (int i = 0; i < numSpaces; i++) {
        printf(" ");
    }
    printf("|");
    for (int i = 0; i < size - 2; i++) {
        printf("   ");
        printf("\\   ");
    }
    printf("   /");
    for (int i = 0; i < numSpaces; i++) {
        printf(" ");
    }
    printf("|\n");
}

// Function to print the footer of the pattern
void printFooter(int size) {
    printf("+");
    for (int i = 0; i < size - 2; i++) {
        printf("--+");
    }
    printf("--+\n");
}

// Main function to control the program flow
int main() {
    // Get the size of the pattern from the user
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    // Print the header of the pattern
    printHeader(size);

    // Print the body of the pattern
    for (int i = 1; i <= size - 2; i++) {
        printBody(size, i);
    }

    // Print the footer of the pattern
    printFooter(size);

    return 0;
}