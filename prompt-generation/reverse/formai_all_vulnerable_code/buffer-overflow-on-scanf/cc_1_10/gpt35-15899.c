//FormAI DATASET v1.0 Category: Data mining ; Style: complex
#include<stdio.h>
#include<stdlib.h>

//Function to calculate mean of an array
float mean(int arr[], int n){
    int i;
    float sum=0;
    for(i=0; i<n; i++){
        sum += arr[i];
    }
    return sum/n;
}

//Function to calculate standard deviation of an array
float stdDev(int arr[], int n){
    int i;
    float meanValue = mean(arr, n);
    float stdDevVal = 0;
    for(i=0; i<n; i++){
        stdDevVal += (arr[i]-meanValue)*(arr[i]-meanValue);
    }
    stdDevVal = sqrt(stdDevVal/n);
    return stdDevVal;
}

//Function to calculate the correlation coefficient between two arrays
float correlationCoef(int arr1[], int arr2[], int n){
    int i;
    float meanValue1 = mean(arr1, n);
    float meanValue2 = mean(arr2, n);
    float stdDevVal1 = stdDev(arr1, n);
    float stdDevVal2 = stdDev(arr2, n);
    float correlationCoefVal = 0;
    for(i=0; i<n; i++){
        correlationCoefVal += ((arr1[i]-meanValue1)*(arr2[i]-meanValue2))/(stdDevVal1*stdDevVal2);
    }
    correlationCoefVal /= n;
    return correlationCoefVal;
}

int main(){
    int n, i;
    printf("Enter the size of the arrays: ");
    scanf("%d", &n);
    int arr1[n], arr2[n];
    printf("Enter the elements of array 1: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr1[i]);
    }
    printf("Enter the elements of array 2: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr2[i]);
    }
    float correlationCoefValue = correlationCoef(arr1, arr2, n);
    printf("Correlation coefficient between the two arrays is %f", correlationCoefValue);
    return 0;
}