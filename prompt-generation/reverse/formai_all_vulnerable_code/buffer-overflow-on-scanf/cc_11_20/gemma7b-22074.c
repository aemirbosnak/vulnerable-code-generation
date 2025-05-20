//Gemma-7B DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>

int main() {
    int n, i, j, x, y, z, a[100], b[100], c[100], d[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    x = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                b[x] = a[i] + a[j];
                x++;
            }
        }
    }

    y = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                c[y] = a[i] - a[j];
                y++;
            }
        }
    }

    z = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                d[z] = a[i] * a[j];
                z++;
            }
        }
    }

    printf("The sum of pairs: ");
    for (i = 0; i < x; i++) {
        printf("%d ", b[i]);
    }

    printf("\nThe difference of pairs: ");
    for (i = 0; i < y; i++) {
        printf("%d ", c[i]);
    }

    printf("\nThe product of pairs: ");
    for (i = 0; i < z; i++) {
        printf("%d ", d[i]);
    }

    return 0;
}