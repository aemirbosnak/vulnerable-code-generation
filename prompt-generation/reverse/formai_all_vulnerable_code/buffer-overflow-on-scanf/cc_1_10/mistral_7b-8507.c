//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>

#define ROWS 6
#define COLS 6

void print_square(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%c", '*');
        printf("\n");
    }
}

void print_diamond(int size) {
    for (int i = 0; i < size; i++) {
        int space = size - i - 1;

        for (int j = 0; j < space; j++)
            printf(" ");

        for (int k = 0; k < (2 * i + 1); k++)
            printf("%c", '*');

        printf("\n");
    }

    for (int i = size - 1; i >= 0; i--) {
        int space = size - i - 1;

        for (int j = 0; j < space; j++)
            printf(" ");

        for (int k = 0; k < (2 * i + 1); k++)
            printf("%c", '*');

        printf("\n");
    }
}

int main() {
    int choice;

    printf("Patterns:\n1. Square\n2. Diamond\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            print_square(ROWS);
            break;
        case 2:
            print_diamond(ROWS);
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            return 1;
    }

    return 0;
}