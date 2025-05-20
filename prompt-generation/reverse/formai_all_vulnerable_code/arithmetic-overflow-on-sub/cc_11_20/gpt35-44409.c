//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>

int main() {
    printf("Get ready for an exciting C Pattern printing program!\n\n");
    int n;
    printf("How many rows do you want in your pattern? ");
    scanf("%d", &n);
    printf("\n");

    printf("Here we go:\n\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", j+1);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", j+1);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", i+1);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", i+1);
        }
        printf("\n");
    }

    printf("Wow, wasn't that exciting?! Stay tuned for more fun with C programming!\n");

    return 0;
}