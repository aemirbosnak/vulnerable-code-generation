//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include <stdio.h>

void printStarPyramid(int n) {
    printf("🎉 Let's Build a Star Pyramid! 🎉\n");
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            printf(" "); // Print spaces for alignment
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*"); // Print the stars
        }
        printf("\n");
    }
}

void printDiamond(int n) {
    printf("\n🌟 Now, Let's Create a Diamond Shape! 🌟\n");
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            printf(" "); // Print spaces for alignment on top
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*"); // Print the stars on top
        }
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            printf(" "); // Print spaces for alignment on bottom
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*"); // Print the stars on bottom
        }
        printf("\n");
    }
}

int main() {
    int rows;

    printf("✨ Welcome to the Star Pattern Printer! ✨\n");
    printf("How many rows would you like in your star pyramid? (Please enter a number): ");
    scanf("%d", &rows);

    printStarPyramid(rows);
    printDiamond(rows);

    printf("\n🎈 Thank you for using the Star Pattern Printer! 🎈\n");
    printf("🌈 Have a wonderful day filled with joy and positivity! 🌈\n");

    return 0;
}