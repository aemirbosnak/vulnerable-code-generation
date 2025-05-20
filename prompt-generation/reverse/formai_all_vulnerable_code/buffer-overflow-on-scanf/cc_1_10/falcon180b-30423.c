//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Define the function that takes an array of doubles and returns the sum of their squares
double sum_of_squares(double* arr, int n){
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += pow(arr[i], 2);
    }
    return sum;
}

//Define the function that takes an array of doubles and returns the average
double average(double* arr, int n){
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum/n;
}

//Define the function that takes an array of doubles and returns the standard deviation
double std_dev(double* arr, int n){
    double avg = average(arr, n);
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += pow(arr[i]-avg, 2);
    }
    return sqrt(sum/n);
}

int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    double* arr = (double*)malloc(n*sizeof(double));
    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++){
        scanf("%lf", &arr[i]);
    }

    double sum_of_squares_val = sum_of_squares(arr, n);
    double avg_val = average(arr, n);
    double std_dev_val = std_dev(arr, n);

    printf("The sum of squares of the elements is: %.2lf\n", sum_of_squares_val);
    printf("The average of the elements is: %.2lf\n", avg_val);
    printf("The standard deviation of the elements is: %.2lf\n", std_dev_val);

    free(arr);
    return 0;
}