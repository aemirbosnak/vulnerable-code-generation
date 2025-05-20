//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: interoperable
#include <stdio.h>

void print_pyramid(int n) {
    printf("\nPyramid Pattern:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("%d", i);
        }
        printf("\n");
    }
}

void print_star_triangle(int n) {
    printf("\nStar Triangle Pattern:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void print_inverted_triangle(int n) {
    printf("\nInverted Triangle Pattern:\n");
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("# ");
        }
        printf("\n");
    }
}

void print_complex_pattern(int n) {
    printf("\nComplex Pattern:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            if (k % 2 == 0) {
                printf("*");
            } else {
                printf("%d", i);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the height of the patterns (a positive integer): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive integer greater than zero.\n");
        return 1;
    }
    
    print_pyramid(n);
    print_star_triangle(n);
    print_inverted_triangle(n);
    print_complex_pattern(n);

    return 0;
}