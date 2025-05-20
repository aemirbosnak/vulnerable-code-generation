//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>

void printDiamond(int n) {
    int space, i, j;

    // Print the upper part of the diamond
    for (i = 0; i < n; i++) {
        for (space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        for (j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Print the lower part of the diamond
    for (i = n - 2; i >= 0; i--) {
        for (space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        for (j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printHourglass(int n) {
    int i, j, k;

    // Print the upper part of the hourglass
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (k = n * 2 - 2 * i; k > 0; k--) {
            printf("*");
        }
        printf("\n");
    }

    // Print the lower part of the hourglass
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (k = 2 * i + 1; k > 0; k--) {
            printf("*");
        }
        printf("\n");
    }
}

void printTriangle(int n) {
    int i, j;

    // Print the triangle
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printInvertedTriangle(int n) {
    int i, j;

    // Print the inverted triangle
    for (i = n; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printDiamondWithNumbers(int n) {
    int i, j, space, num;

    // Print upper part with numbers
    for (i = 0; i < n; i++) {
        for (space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        num = 1;
        for (j = 0; j < 2 * i + 1; j++) {
            if (j % 2 == 0) {
                printf("%d", num++);
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    // Print lower part with numbers
    for (i = n - 2; i >= 0; i--) {
        for (space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        num = 1;
        for (j = 0; j < 2 * i + 1; j++) {
            if (j % 2 == 0) {
                printf("%d", num++);
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("🌟 Welcome to Pattern Wizard! 🌟\n");
    printf("Enter the size for your patterns (e.g., 5): ");
    scanf("%d", &n);

    printf("\n✨ Diamond Pattern ✨\n");
    printDiamond(n);
    
    printf("\n🕰️ Hourglass Pattern 🕰️\n");
    printHourglass(n);
    
    printf("\n🔺 Number Triangle 🔺\n");
    printTriangle(n);
    
    printf("\n🔻 Inverted Number Triangle 🔻\n");
    printInvertedTriangle(n);
    
    printf("\n💎 Diamond with Numbers 💎\n");
    printDiamondWithNumbers(n);

    printf("\n🎉 Hope you enjoyed the excitement! 🎉\n");

    return 0;
}