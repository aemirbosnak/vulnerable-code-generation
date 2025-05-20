//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k, l, m, count = 0, flag = 0;
    int a[10][10], b[10][10], c[10][10], d[10][10], e[10][10];
    int sum = 0;
    int start, end;
    int min_val, max_val;
    int min_index, max_index;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &n, &n);

    printf("\nEnter the elements of first matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("\nEnter the elements of second matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
            sum += c[i][j];
        }
    }

    printf("\nSum of elements in the resultant matrix: %d\n", sum);

    printf("\nEnter the lower and upper bounds for random numbers: ");
    scanf("%d %d", &min_val, &max_val);

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            d[i][j] = rand() % (max_val - min_val + 1) + min_val;
        }
    }

    printf("\nRandom matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (d[i][j] == k) {
                count++;
                flag = 1;
            }
        }
    }

    if (flag == 1)
        printf("\nElement %d found %d times in the matrix.\n", k, count);
    else
        printf("\nElement %d not found in the matrix.\n", k);

    return 0;
}