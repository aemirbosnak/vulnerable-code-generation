//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: configurable
#include <stdio.h>

void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printCharacterPattern(int rows, char ch, int type) {
    if (type == 1) { // Right-angled Triangle
        for (int i = 1; i <= rows; i++) {
            printSpaces(rows - i);
            for (int j = 1; j <= i; j++) {
                printf("%c ", ch);
            }
            printf("\n");
        }
    } else if (type == 2) { // Inverted Triangle
        for (int i = rows; i >= 1; i--) {
            printSpaces(rows - i);
            for (int j = 1; j <= i; j++) {
                printf("%c ", ch);
            }
            printf("\n");
        }
    } else if (type == 3) { // Diamond Shape
        for (int i = 1; i <= rows; i++) {
            printSpaces(rows - i);
            for (int j = 1; j <= (2 * i - 1); j++) {
                printf("%c", ch);
            }
            printf("\n");
        }
        for (int i = rows - 1; i >= 1; i--) {
            printSpaces(rows - i);
            for (int j = 1; j <= (2 * i - 1); j++) {
                printf("%c", ch);
            }
            printf("\n");
        }
    } else {
        printf("Invalid type selected.\n");
    }
}

int main() {
    int rows, type;
    char ch;

    printf("Welcome to the Pattern Generator!\n");
    printf("Please enter the number of rows (1-20): ");
    if (scanf("%d", &rows) != 1 || rows < 1 || rows > 20) {
        printf("Invalid input for rows. It must be between 1 and 20 and an integer.\n");
        return 1;
    }

    printf("Please enter the character you want to use: ");
    scanf(" %c", &ch); // The space before %c ignores any whitespace

    printf("Select the pattern type:\n");
    printf("1. Right-angled Triangle\n");
    printf("2. Inverted Triangle\n");
    printf("3. Diamond Shape\n");
    printf("Enter your choice (1-3): ");
   
    if (scanf("%d", &type) != 1 || type < 1 || type > 3) {
        printf("Invalid type selection. It must be between 1 and 3.\n");
        return 1;
    }

    printf("\nGenerating your pattern:\n");
    printCharacterPattern(rows, ch, type);

    return 0;
}