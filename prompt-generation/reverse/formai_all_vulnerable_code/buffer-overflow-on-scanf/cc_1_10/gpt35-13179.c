//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

    int i, j, arr[100], size, max, min, sum=0;
    float mean, variance, standard_deviation;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Generate random numbers for the array
    srand(time(0));
    for(i=0; i<size; i++){
        arr[i] = rand()%101;
        printf("%d ", arr[i]);
    }

    // find the maximum element in the array
    max = arr[0];
    for(i=0; i<size; i++){
        if(max < arr[i])
            max = arr[i];
    }
    printf("\nMaximum element in the array: %d\n", max);

    // find the minimum element in the array
    min = arr[0];
    for(i=0; i<size; i++){
        if(min > arr[i])
            min = arr[i];
    }
    printf("Minimum element in the array: %d\n", min);

    // find the mean of the elements in the array
    for(i=0; i<size; i++){
        sum += arr[i];
    }
    mean = (float)sum/size;
    printf("Mean of the elements in the array: %.2f\n", mean);

    // find the variance of the elements in the array
    variance = 0;
    for(i=0; i<size; i++){
        variance += pow(arr[i]-mean, 2);
    }
    variance = variance/size;
    printf("Variance of the elements in the array: %.2f\n", variance);

    // find the standard deviation of the elements in the array
    standard_deviation = sqrt(variance);
    printf("Standard deviation of the elements in the array: %.2f\n", standard_deviation);

    return 0;
}