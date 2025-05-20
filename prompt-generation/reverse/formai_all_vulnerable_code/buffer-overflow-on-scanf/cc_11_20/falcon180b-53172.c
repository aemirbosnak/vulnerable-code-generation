//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000
#define PI 3.14159265358979323846

int main() {
    int size;
    double *array;
    double sum = 0, avg, std_dev = 0;
    int i, j;
    char choice;

    srand(time(NULL));
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    array = (double*) malloc(size * sizeof(double));

    if (array == NULL) {
        printf("Not enough memory\n");
        exit(1);
    }

    printf("Do you want to populate the array with random numbers? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        for (i = 0; i < size; i++) {
            array[i] = rand() % 100;
        }
    } else {
        printf("Enter %d numbers:\n", size);
        for (i = 0; i < size; i++) {
            scanf("%lf", &array[i]);
        }
    }

    printf("Enter the operation you want to perform:\n");
    printf("1. Sum\n");
    printf("2. Average\n");
    printf("3. Standard deviation\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (i = 0; i < size; i++) {
                sum += array[i];
            }
            printf("The sum is: %.2lf\n", sum);
            break;
        case 2:
            for (i = 0; i < size; i++) {
                sum += array[i];
            }
            avg = sum / size;
            printf("The average is: %.2lf\n", avg);
            break;
        case 3:
            for (i = 0; i < size; i++) {
                sum += pow(array[i] - avg, 2);
            }
            std_dev = sqrt(sum / size);
            printf("The standard deviation is: %.2lf\n", std_dev);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    free(array);
    return 0;
}