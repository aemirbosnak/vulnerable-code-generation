//Gemma-7B DATASET v1.0 Category: System administration ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void main() {
    int i, j, n, m, a[MAX], b[MAX];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number of comparisons: ");
    scanf("%d", &m);

    for (j = 0; j < m; j++) {
        printf("Enter the comparison operators: ");
        scanf(" %c", &b[j]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            switch (b[j]) {
                case '=':
                    if (a[i] == a[i]) {
                        printf("True\n");
                    } else {
                        printf("False\n");
                    }
                    break;
                case '<':
                    if (a[i] < a[i]) {
                        printf("True\n");
                    } else {
                        printf("False\n");
                    }
                    break;
                case '>':
                    if (a[i] > a[i]) {
                        printf("True\n");
                    } else {
                        printf("False\n");
                    }
                    break;
                default:
                    printf("Invalid operator\n");
            }
        }
    }

    return;
}