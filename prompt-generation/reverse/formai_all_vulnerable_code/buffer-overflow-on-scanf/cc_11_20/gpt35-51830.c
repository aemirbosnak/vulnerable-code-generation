//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>

int main() {
    printf("Hey there, I'm a C pattern printing program and I am super excited!\n");
    printf("Give me a number and watch me create some magic:\n");

    int n;
    scanf("%d", &n);

    printf("Alright, get ready to be amazed!\n");
    printf("Behold! My fantastic C pattern:\n");

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("Woohoo! Wasn't that awesome? Let's try another one!\n");

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || i == 1 || i == n) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("Amazing, right? But wait, there's more!\n");
    printf("Check out this incredible C pattern with a twist:\n");

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1 || i == j && i <= n / 2 + 1 || i == n - j + 1 && i <= n / 2 + 1 || i == n / 2 + 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("Whew, that was intense! Hope you enjoyed these amazing patterns. Until next time!\n");

    return 0;
}