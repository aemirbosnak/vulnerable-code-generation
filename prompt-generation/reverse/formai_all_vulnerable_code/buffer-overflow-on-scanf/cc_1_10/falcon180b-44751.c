//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#define MAX_NUM 1000000000
#define MAX_LEN 10000
#define MAX_DIG 10

int main() {
    double num = 0;
    int len = 0;
    int dig = 0;
    int count = 0;
    int sum = 0;
    int prod = 1;
    int i, j;
    int arr[MAX_NUM][MAX_LEN];
    int index = 0;
    time_t start, end;
    double elapsed;
    printf("Enter the number of digits: ");
    scanf("%d", &dig);
    printf("Enter the number of integers to generate: ");
    scanf("%d", &len);
    printf("Enter the number of integers to calculate: ");
    scanf("%d", &count);
    printf("Enter the operation (+ or *): ");
    char op;
    scanf(" %c", &op);
    srand(time(NULL));
    for (i = 0; i < len; i++) {
        num = rand() % MAX_NUM;
        arr[index][0] = num;
        index++;
        for (j = 1; j < dig; j++) {
            arr[index][j] = rand() % 10;
            index++;
        }
    }
    start = clock();
    for (i = 0; i < count; i++) {
        switch (op) {
            case '+':
                sum = 0;
                for (j = 0; j < dig; j++) {
                    sum += arr[i][j];
                }
                printf("Sum: %d\n", sum);
                break;
            case '*':
                prod = 1;
                for (j = 0; j < dig; j++) {
                    prod *= arr[i][j];
                }
                printf("Product: %d\n", prod);
                break;
            default:
                break;
        }
    }
    end = clock();
    elapsed = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %lf seconds\n", elapsed);
    return 0;
}