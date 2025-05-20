//Falcon2-11B DATASET v1.0 Category: Pattern printing ; Style: future-proof
#include <stdio.h>
#include <string.h>

// Function to calculate the size of a triangle
int getTriangleSize(int size) {
    int i;
    int size_of_triangle = 0;
    for (i = 1; i <= size; i++) {
        size_of_triangle += (size - i) + 1;
    }
    return size_of_triangle;
}

// Function to calculate the number of spaces required for the triangle
int getSpaces(int size) {
    int spaces = 0;
    for (int i = 0; i < size; i++) {
        spaces += (size - i) + 1;
    }
    return spaces;
}

// Function to print the triangle
void printTriangle(int size) {
    int spaces = getSpaces(size);
    int spaces_to_print = getTriangleSize(size);

    // Print the spaces
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }

    // Print the first row of the triangle
    for (int i = 0; i < size; i++) {
        printf("*");
    }
    printf("\n");

    // Print the rest of the rows of the triangle
    for (int i = 0; i < spaces_to_print; i++) {
        // Print the spaces
        for (int j = 0; j < size; j++) {
            printf(" ");
        }

        // Print the triangle row
        for (int j = 0; j < size; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print the pattern of triangles
void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
        printTriangle(i);
    }
}

int main() {
    int n;
    printf("Enter the number of triangles: ");
    scanf("%d", &n);
    printPattern(n);
    return 0;
}