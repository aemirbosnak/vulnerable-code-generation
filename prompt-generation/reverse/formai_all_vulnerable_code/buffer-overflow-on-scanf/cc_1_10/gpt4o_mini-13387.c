//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Donald Knuth
#include <stdio.h>

void print_pattern(int n) {
    // This function prints a diamond pattern based on the integer input n
    int i, j;

    // Print the upper part of the diamond
    for(i = 1; i <= n; i++) {
        // Print leading spaces
        for(j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print stars
        for(j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    // Print the lower part of the diamond
    for(i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for(j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print stars
        for(j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void print_triangle(int n) {
    // This function prints a pyramid triangle based on the integer input n
    int i, j;
    
    // Print pyramid triangle
    for(i = 1; i <= n; i++) {
        // Print leading spaces
        for(j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print numbers
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void print_reversed_number_triangle(int n) {
    // This function prints a reversed number triangle
    int i, j;
    
    // Print reversed number triangle
    for(i = n; i >= 1; i--) {
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void print_floyd_triangle(int n) {
    // This function prints Floyd's triangle
    int i, j, num = 1;
    
    // Print Floyd's triangle
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
}

void print_number_pyramid(int n) {
    // This function prints a number pyramid
    int i, j, space;
    
    // Print number pyramid
    for(i = 1; i <= n; i++) {
        for(space = 1; space <= n - i; space++) {
            printf(" ");
        }
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of rows for the patterns: ");
    scanf("%d", &n);
    
    printf("\nDiamond Pattern:\n");
    print_pattern(n);
    
    printf("\nTriangle with Numbers:\n");
    print_triangle(n);

    printf("\nReversed Number Triangle:\n");
    print_reversed_number_triangle(n);

    printf("\nFloyd's Triangle:\n");
    print_floyd_triangle(n);

    printf("\nNumber Pyramid:\n");
    print_number_pyramid(n);

    return 0;
}