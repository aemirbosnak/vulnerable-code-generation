//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: shape shifting
#include <stdio.h>
#include <string.h>

// Function to print the string in a triangle shape
void printTriangle(const char *str, int length, int level) {
    if (level > length) return;
    for(int i = 0; i < level; i++) {
        putchar(str[i]);
    }
    putchar('\n');
    printTriangle(str, length, level + 1);
}

// Function to print the string in a diamond shape
void printDiamond(const char *str, int level, int max) {
    if (level > max) return;
    for(int i = 0; i < max - level; i++) putchar(' ');
    for(int i = 0; i < 2 * level - 1; i++) putchar(str[(i < level) ? i : (2 * level - 2 - i)]);
    putchar('\n');
    printDiamond(str, level + 1, max);
}

// Function to print the string in an inverted triangle shape
void printInvertedTriangle(const char *str, int length, int level) {
    if (level > length) return;
    for(int i = 0; i < length - level; i++) {
        putchar(str[i]);
    }
    putchar('\n');
    printInvertedTriangle(str, length, level + 1);
}

// Function to perform shape printing based on user's choice
void shapeShifter(const char *str, int choice) {
    int length = strlen(str);
    switch (choice) {
        case 1:
            printf("Triangle Shape:\n");
            printTriangle(str, length, 0);
            break;
        case 2:
            printf("Diamond Shape:\n");
            printDiamond(str, 1, length);
            break;
        case 3:
            printf("Inverted Triangle Shape:\n");
            printInvertedTriangle(str, length, 0);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    char str[100];
    int choice;

    printf("Enter a string (max 99 characters): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove trailing newline

    printf("Choose a shape to display the string:\n");
    printf("1. Triangle\n2. Diamond\n3. Inverted Triangle\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    shapeShifter(str, choice);

    return 0;
}