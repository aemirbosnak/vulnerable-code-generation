//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Linus Torvalds
#include <stdio.h>

void print_spaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

void print_stars(int count) {
    for (int i = 0; i < count; i++) {
        printf("* ");
    }
}

void print_pyramid(int height) {
    for (int row = 1; row <= height; row++) {
        print_spaces(height - row);
        print_stars(row);
        printf("\n");
    }
}

void print_reverse_pyramid(int height) {
    for (int row = height; row >= 1; row--) {
        print_spaces(height - row);
        print_stars(row);
        printf("\n");
    }
}

void print_diamond(int height) {
    print_pyramid(height);
    print_reverse_pyramid(height - 1);
}

int main() {
    int height;

    printf("Enter the height of the diamond pattern (1 to 20): ");
    scanf("%d", &height);

    // Input validation
    if (height < 1 || height > 20) {
        printf("Height must be between 1 and 20.\n");
        return 1;
    }

    printf("\nDiamond Pattern:\n");
    print_diamond(height);

    return 0;
}