//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void displayHeader() {
    printf("--------------------------------------------------\n");
    printf("       🌹 Fibonacci Sequence Visualizer 🌹\n");
    printf("--------------------------------------------------\n\n");
    printf("Behold this enchanting journey through the mystical world of Fibonacci!\n");
    printf("Where every number whispers secrets of romance, connection, and the beauty of growth.\n\n");
}

void displayFibNumbersWithStyle(int n) {
    if (n < 1) {
        printf("Oh dear, let your dreams take flight! The count must be positive.\n");
        return;
    }

    int a = 0, b = 1, next;
    printf("The Fibonacci Sequence in all its glory: \n");
    
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("🌼 %d\n", a);
            continue;
        }
        if (i == 2) {
            printf("🌸 %d\n", b);
            continue;
        }
        
        next = a + b;
        a = b;
        b = next;

        printf("💖 %d\n", next);
    }
    printf("\nEvery number here unfolds the romance of mathematics, revealing timeless patterns.\n");
}

void displayVisualization(int n) {
    if (n < 1) {
        printf("Alas! We need at least one twinkling star in our sky...\n");
        return;
    }
    
    printf("\nVisualizing the Fibonacci sequence, let the numbers dance in your heart:\n\n");

    int a = 0, b = 1, next;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%*s★\n", a + 10, "");
            continue;
        } else if (i == 1) {
            printf("%*s★\n", b + 10, "");
            continue;
        }

        next = a + b;
        a = b;
        b = next;

        for (int j = 0; j < next; j++) {
            printf("💞");
        }
        printf("\n");
    }
    printf("\nLet the beauty of Fibonacci envelop your spirit!\n");
}

int main() {
    int n;

    displayHeader();
    printf("How many numbers of romance shall we unveil today? (Input a positive integer): ");
    scanf("%d", &n);

    displayFibNumbersWithStyle(n);
    displayVisualization(n);

    printf("\n--------------------------------------------------\n");
    printf("Thank you for joining this whimsical voyage through Fibonacci's embrace!\n");
    printf("May you carry the beauty of these numbers in your heart forever.\n");
    printf("--------------------------------------------------\n");

    return 0;
}