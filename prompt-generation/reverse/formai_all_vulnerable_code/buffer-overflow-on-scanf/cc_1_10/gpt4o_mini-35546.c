//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Ken Thompson
#include <stdio.h>

void print_row(int row, int total_rows) {
    int spaces = total_rows - row;
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
    for (int i = 0; i < (2 * row - 1); i++) {
        if (i % 2 == 0) 
            printf("*");
        else 
            printf(" ");
    }
    printf("\n");
}

void print_triangle(int levels) {
    for (int row = 1; row <= levels; row++) {
        print_row(row, levels);
    }
}

void print_inverse_triangle(int levels) {
    for (int row = levels; row >= 1; row--) {
        print_row(row, levels);
    }
}

void print_square(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void print_diamond(int levels) {
    print_triangle(levels);
    print_inverse_triangle(levels - 1);
}

void print_rectangle(int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main() {
    int choice, size, height, width, levels;

    while (1) {
        printf("Choose a pattern to print:\n");
        printf("1. Triangle\n");
        printf("2. Inverse Triangle\n");
        printf("3. Diamond\n");
        printf("4. Square\n");
        printf("5. Rectangle\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of levels for triangle: ");
                scanf("%d", &levels);
                print_triangle(levels);
                break;
            case 2:
                printf("Enter number of levels for inverse triangle: ");
                scanf("%d", &levels);
                print_inverse_triangle(levels);
                break;
            case 3:
                printf("Enter number of levels for diamond: ");
                scanf("%d", &levels);
                print_diamond(levels);
                break;
            case 4:
                printf("Enter size for square: ");
                scanf("%d", &size);
                print_square(size);
                break;
            case 5:
                printf("Enter height for rectangle: ");
                scanf("%d", &height);
                printf("Enter width for rectangle: ");
                scanf("%d", &width);
                print_rectangle(height, width);
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}