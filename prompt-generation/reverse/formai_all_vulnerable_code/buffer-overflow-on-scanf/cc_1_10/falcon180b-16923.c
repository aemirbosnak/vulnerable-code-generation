//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int main() {
    int i, j, n, m, k, l, cnt = 0, flag = 0, choice, sum = 0;
    float avg, num, rem, term = 1, fact = 1, num1, num2, res;
    char str[100];

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 0;
    }

    printf("Enter 1 for arithmetic progression (a_n = a_1 + (n-1)*d)\n");
    printf("Enter 2 for geometric progression (a_n = a_1*r^(n-1))\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the first term: ");
            scanf("%f", &num1);
            printf("Enter the common difference: ");
            scanf("%f", &term);
            for (i = 1; i <= n; i++) {
                printf("a_%d = %.2f\n", i, num1 + (i - 1) * term);
            }
            break;

        case 2:
            printf("Enter the first term: ");
            scanf("%f", &num1);
            printf("Enter the common ratio: ");
            scanf("%f", &term);
            for (i = 1; i <= n; i++) {
                printf("a_%d = %.2f\n", i, num1 * pow(term, i - 1));
            }
            break;

        default:
            printf("Invalid choice! Please enter 1 or 2.\n");
            return 0;
    }

    return 0;
}