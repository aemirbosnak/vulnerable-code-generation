//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {

    int i, j, n, m, sum = 0;
    double x, y, z;
    char op;

    srand(time(NULL));
    n = rand() % MAX_SIZE + 1;
    m = rand() % MAX_SIZE + 1;

    int arr1[MAX_SIZE], arr2[MAX_SIZE];

    for (i = 0; i < n; i++) {
        arr1[i] = rand() % 100;
    }

    for (i = 0; i < m; i++) {
        arr2[i] = rand() % 100;
    }

    printf("Enter the operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &op);

    switch (op) {
        case 1:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    sum += arr1[i] + arr2[j];
                }
            }
            printf("The sum of the two arrays is: %d\n", sum);
            break;
        case 2:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    sum += arr1[i] - arr2[j];
                }
            }
            printf("The difference of the two arrays is: %d\n", sum);
            break;
        case 3:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    sum += arr1[i] * arr2[j];
                }
            }
            printf("The product of the two arrays is: %d\n", sum);
            break;
        case 4:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    if (arr2[j] == 0) {
                        printf("Division by zero is not allowed!\n");
                        exit(1);
                    }
                    sum += arr1[i] / arr2[j];
                }
            }
            printf("The quotient of the two arrays is: %d\n", sum);
            break;
        default:
            printf("Invalid operation selected!\n");
    }

    return 0;
}