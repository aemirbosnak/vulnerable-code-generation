//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10

int main() {
    int i, j, n, m, x, y, k, count = 0, flag = 0;
    int arr[SIZE][SIZE];
    char ch;
    srand(time(NULL));

    do {
        printf("Enter the size of the matrix (1 to %d): ", SIZE);
        scanf("%d", &n);
    } while (n < 1 || n > SIZE);

    do {
        printf("Enter the density of non-zero elements (0 to 100): ");
        scanf("%d", &m);
    } while (m < 0 || m > 100);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (rand() % 100 < m) {
                arr[i][j] = rand() % 100;
            } else {
                arr[i][j] = 0;
            }
        }
    }

    printf("\nThe matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the elements to be added:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &x);
            arr[i][j] += x;
        }
    }

    printf("\nThe updated matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the elements to be subtracted:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &y);
            arr[i][j] -= y;
        }
    }

    printf("\nThe final matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}