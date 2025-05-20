//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: futuristic
#include <stdio.h>

void printSpace(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printPyramid(int rows) {
    for (int i = 0; i < rows; i++) {
        printSpace(rows - i - 1);
        for (int j = 0; j <= i; j++) {
            printf("%d ", j + 1);
        }
        printf("\n");
    }
}

void printDiamond(int n) {
    int space = n - 1;
    for (int i = 0; i < n; i++) {
        printSpace(space);
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
        space--;
    }
    space = 0;
    for (int i = n; i >= 1; i--) {
        printSpace(space);
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
        space++;
    }
}

void printRectangle(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("# ");
        }
        printf("\n");
    }
}

void printHollowSquare(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printInvertedPyramid(int rows) {
    for (int i = rows; i > 0; i--) {
        printSpace(rows - i);
        for (int j = 0; j < i; j++) {
            printf("@ ");
        }
        printf("\n");
    }
}

void printDynamicPattern(int total) {
    for (int i = 1; i <= total; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%s ", (j % 2 == 0) ? "#" : "$");
        }
        printf("\n");
    }
}

int main() {
    int choice, n, rows, cols;

    printf("Welcome to the Futuristic Pattern Printer!\n");
    printf("------------------------------------------------\n");
    printf("Choose a pattern to print:\n");
    printf("1. Pyramid Pattern\n");
    printf("2. Diamond Pattern\n");
    printf("3. Rectangle Pattern\n");
    printf("4. Hollow Square Pattern\n");
    printf("5. Inverted Pyramid\n");
    printf("6. Dynamic Pattern\n");
    printf("Enter your choice (1-6): ");
    
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter the number of rows for the Pyramid: ");
            scanf("%d", &rows);
            printPyramid(rows);
            break;
        case 2:
            printf("Enter the number of rows for the Diamond: ");
            scanf("%d", &n);
            printDiamond(n);
            break;
        case 3:
            printf("Enter the number of rows for the Rectangle: ");
            scanf("%d", &rows);
            printf("Enter the number of columns for the Rectangle: ");
            scanf("%d", &cols);
            printRectangle(rows, cols);
            break;
        case 4:
            printf("Enter the size of the Hollow Square: ");
            scanf("%d", &n);
            printHollowSquare(n);
            break;
        case 5:
            printf("Enter the number of rows for the Inverted Pyramid: ");
            scanf("%d", &rows);
            printInvertedPyramid(rows);
            break;
        case 6:
            printf("Enter the total number of rows for the Dynamic Pattern: ");
            scanf("%d", &n);
            printDynamicPattern(n);
            break;
        default:
            printf("Invalid choice! Please restart the program and try again.\n");
            break;
    }

    printf("------------------------------------------------\n");
    printf("Thank you for using the Futuristic Pattern Printer!\n");

    return 0;
}