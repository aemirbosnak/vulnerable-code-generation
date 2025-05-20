//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Sherlock Holmes
#include <stdio.h>

void printFingerprint(int n) {
    printf("Fingerprint Pattern:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 0) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void printMagnifyingGlass(int n) {
    printf("Magnifying Glass Pattern:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                printf(" # ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void printHolmesHat(int height) {
    printf("Sherlock Holmes Hat Pattern:\n");
    int width = 2 * height + 1;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == height - i || j == height + i) {
                printf(" / ");
            } else if (j == height) {
                printf(" | ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    // The brim of the hat
    for (int i = 0; i < width; i++) {
        printf("___");
    }
    printf("\n\n");
}

void printClue(int rowCount) {
    printf("Clue Pattern:\n");
    for (int i = 1; i <= rowCount; i++) {
        for (int j = 1; j <= rowCount; j++) {
            if (j == 1 || j == rowCount || i == j || i + j == rowCount + 1) {
                printf(" @ ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n;

    printf("Greetings, dear reader!\n");
    printf("Let us embark on a journey of patterns inspired by my astute observations.\n");

    printf("Enter the size of the pattern (1-10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Alas, my calculations lead me to conclude that the size must be between 1 and 10.\n");
        return 1;
    }

    printFingerprint(n);
    printMagnifyingGlass(n);
    printHolmesHat(n);
    printClue(n);

    printf("The patterns have been revealed, akin to a series of clues in a grand mystery.\n");
    printf("May they enlighten your path as they have mine in pursuits of justice.\n");

    return 0;
}