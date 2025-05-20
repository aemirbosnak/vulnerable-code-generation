//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 100
#define PI 3.14159265358979323846

int main() {
    int size;
    double *array;
    char operation;
    int i;

    srand(time(NULL));
    size = rand() % MAX_SIZE + 1;
    array = (double *)malloc(size * sizeof(double));
    for (i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    printf("Enter the operation you want to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%c", &operation);

    switch (operation) {
        case '1':
            for (i = 0; i < size; i++) {
                array[i] += rand() % 100;
            }
            break;
        case '2':
            for (i = 0; i < size; i++) {
                array[i] -= rand() % 100;
            }
            break;
        case '3':
            for (i = 0; i < size; i++) {
                array[i] *= rand() % 100;
            }
            break;
        case '4':
            for (i = 0; i < size; i++) {
                array[i] /= rand() % 100;
            }
            break;
        default:
            printf("Invalid operation!\n");
            exit(1);
    }

    printf("The result of the operation is:\n");
    for (i = 0; i < size; i++) {
        printf("%f ", array[i]);
    }

    free(array);
    return 0;
}