//Falcon-180B DATASET v1.0 Category: Educational ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int size;
    int sum = 0;
    int i, j;
    int num;
    int count = 0;
    int avg;
    int max = 0;
    int min = 1000000;
    int *ptr;
    int random_num;
    int flag = 0;
    int num_of_elements = 0;

    // ask user for size of array
    printf("Enter the size of array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // generate random numbers and add to array
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        random_num = rand() % 1000;
        arr[i] = random_num;
        sum += random_num;
    }

    // calculate average
    avg = sum / size;

    // find max and min values
    for (i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // sort array in ascending order
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                num = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = num;
            }
        }
    }

    // find mode
    count = 0;
    max = arr[0];
    for (i = 0; i < size; i++) {
        num_of_elements = 0;
        for (j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                num_of_elements++;
            }
        }
        if (num_of_elements > count) {
            count = num_of_elements;
            max = arr[i];
        }
    }

    // print results
    printf("The sum of the array is: %d\n", sum);
    printf("The average of the array is: %.2f\n", avg);
    printf("The max value in the array is: %d\n", max);
    printf("The min value in the array is: %d\n", min);
    printf("The mode of the array is: %d\n", max);

    // ask user if they want to sort array in descending order
    printf("Do you want to sort the array in descending order? (y/n): ");
    scanf(" %c", &flag);

    if (flag == 'y' || flag == 'Y') {
        // sort array in descending order
        for (i = 0; i < size - 1; i++) {
            for (j = 0; j < size - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    num = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = num;
                }
            }
        }
        // print sorted array
        printf("\nThe sorted array in descending order is:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}