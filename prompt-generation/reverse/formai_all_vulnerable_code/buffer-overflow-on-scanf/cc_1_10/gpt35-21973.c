//FormAI DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, x, y, i, j = -1;
    float sum = 0.0, avg, std_dev = 0.0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers: ", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    avg = sum/n;

    for(i = 0; i < n; i++) {
        std_dev += pow(arr[i] - avg, 2);
    }

    std_dev = sqrt(std_dev/n);

    printf("The average is: %.2f \n", avg);
    printf("The standard deviation is: %.2f \n", std_dev);

    printf("Enter two integers (separated by a space): ");
    scanf("%d %d", &x, &y);

    printf("The greatest common divisor of %d and %d is: ", x, y);

    if(x > y) {
        int temp = x;
        x = y;
        y = temp;
    }

    while(j != 0) {
        j = y % x;
        y = x;
        x = j;
    }

    printf("%d \n", y);

    return 0;
}