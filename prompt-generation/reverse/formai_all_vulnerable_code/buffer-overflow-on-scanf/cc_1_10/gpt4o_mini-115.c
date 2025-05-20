//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: shocked
#include <stdio.h>

void print_top_half(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void print_bottom_half(int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < n - i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void print_full_pattern(int n) {
    printf("Generating a unique pattern in total shock...\n");
    
    print_top_half(n);
    print_bottom_half(n);
    
    printf("Wow! Pattern has been generated successfully!\n");
}

int main() {
    int rows;

    printf("Enter the number of rows for the diamond pattern: ");
    if (scanf("%d", &rows) != 1 || rows < 1) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }

    if (rows > 20) {
        printf("Whoa! You're a master of patterns, but let's keep it under control!\n");
        rows = 20; // Limit max size
    }

    print_full_pattern(rows);
    
    return 0;
}