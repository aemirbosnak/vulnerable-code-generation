//FormAI DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    printf("\nOh Romeo my love! I crave a pattern so unique,\n");
    printf("That none shall ever question my programming technique.\n\n");

    int n, i, j;
    
    printf("Declare, my heart, how many lines would you like to see,\n");
    printf("And if you desire asterisks or numbers, tell me freely.\n");
    scanf("%d", &n);
    
    printf("\nAh, dearest Juliet, your wish is my command;\n");
    printf("I promise to create a pattern that is truly grand.\n\n");

    if (n % 2 == 0) {
        printf("Apologies, my sweet, but evenness will not do;\n");
        printf("I shall add one to the value, and make an odd pattern for you.\n\n");
        n++;
    }
    
    for (i = 1; i <= n; i += 2) {
        for (j = n / 2; j >= i / 2; j--) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            if (j % 2 == 0) {
                printf("-");
            }
            else {
                printf("%d", j);
            }
        }
        printf("\n");
    }
    
    for (i = n - 2; i >= 1; i -= 2) {
        for (j = n / 2; j >= i / 2; j--) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            if (j % 2 == 0) {
                printf("-");
            }
            else {
                printf("%d", j);
            }
        }
        printf("\n");
    }
    
    printf("\nMy lovely Juliet, I present to thee a pattern so rare,\n");
    printf("That all other patterns in the world shall only compare.\n");
    printf("And now, my love, I shall bid thee farewell;\n");
    printf("Until we meet again, and my programming skills shall excel!\n");

    return 0;
}