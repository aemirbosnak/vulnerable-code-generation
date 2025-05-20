//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j;
    int n, m;
    int sum = 0;
    int product = 1;
    int difference;
    int quotient;
    int remainder;
    int max;
    int min;
    float average;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The sum of the array is: %d\n", sum);

    for(i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("The product of the array is: %d\n", product);

    for(i = 0; i < n; i++) {
        product *= arr[i];
    }

    printf("The difference between the largest and smallest numbers in the array is: %d\n", difference);

    max = arr[0];
    min = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    difference = max - min;

    printf("The average of the array is: %.2f\n", average);

    for(i = 0; i < n; i++) {
        average += arr[i];
    }

    average /= n;

    return 0;
}