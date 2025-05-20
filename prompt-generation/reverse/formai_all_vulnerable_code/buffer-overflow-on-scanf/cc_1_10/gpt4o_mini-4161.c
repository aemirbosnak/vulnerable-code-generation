//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: innovative
#include <stdio.h>

// Function to print space between characters
void print_space(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

// Function to print the upper part of the diamond
void print_upper_diamond(int n) {
    for (int i = 1; i <= n; i++) {
        print_space(n - i);
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print the lower part of the diamond
void print_lower_diamond(int n) {
    for (int i = n - 1; i >= 1; i--) {
        print_space(n - i);
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print heart shape
void print_heart() {
    printf("  *****     *****  \n");
    printf("********* *********\n");
    printf("*******************\n");
    printf(" ***************** \n");
    printf("  ***************  \n");
    printf("   *************   \n");
    printf("    ***********    \n");
    printf("      ******       \n");
    printf("       ****        \n");
    printf("        **         \n");
}

// Function to print a square with given size
void print_square(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to print a triangle of numbers
void print_number_triangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

// Function to print an inverted triangle of stars
void print_inverted_triangle(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print a rectangle with given width and height
void print_rectangle(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the size of the diamond (number of rows in upper part): ");
    scanf("%d", &n);

    printf("\nUpper Part of Diamond:\n");
    print_upper_diamond(n);

    printf("\nLower Part of Diamond:\n");
    print_lower_diamond(n);

    printf("\nHeart Shape:\n");
    print_heart();

    int square_size;
    printf("\nEnter size for square pattern: ");
    scanf("%d", &square_size);
    printf("\nSquare Pattern of Size %d:\n", square_size);
    print_square(square_size);

    int triangle_size;
    printf("\nEnter size for number triangle pattern: ");
    scanf("%d", &triangle_size);
    printf("\nNumber Triangle Pattern of Size %d:\n", triangle_size);
    print_number_triangle(triangle_size);

    int inverted_size;
    printf("\nEnter size for inverted triangle pattern: ");
    scanf("%d", &inverted_size);
    printf("\nInverted Triangle Pattern of Size %d:\n", inverted_size);
    print_inverted_triangle(inverted_size);

    int rect_width, rect_height;
    printf("\nEnter width and height for rectangle pattern: ");
    scanf("%d %d", &rect_width, &rect_height);
    printf("\nRectangle Pattern of Width %d and Height %d:\n", rect_width, rect_height);
    print_rectangle(rect_width, rect_height);

    return 0;
}