//FormAI DATASET v1.0 Category: Data mining ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void dataMining(int arr[], int n){
    int i,j;
    int max,min,diff;
    float mean,variance,stddev;
    srand(time(NULL));
    for(i=0;i<n;i++){
        arr[i] = rand()%100; //populating the array with random numbers between 0 and 99
    }
    printf("The data set is: ");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]); //printing the dataset
    }
    max = arr[0]; //initialize max with the first element of the array
    for(i=1;i<n;i++){
        if(arr[i] > max){
            max = arr[i]; //if the current element is greater than max, update max
        }
    }
    printf("\nThe maximum value is: %d", max);
    min = arr[0]; //initialize min with the first element of the array
    for(i=1;i<n;i++){
        if(arr[i] < min){
            min = arr[i]; //if the current element is less than min, update min
        }
    }
    printf("\nThe minimum value is: %d", min);
    mean = 0; //initialize mean with 0
    for(i=0;i<n;i++){
        mean += arr[i]; //calculate the sum of all elements
    }
    mean = mean/n; //divide the sum by the number of elements to get the mean
    printf("\nThe mean value is: %.2f", mean);
    variance = 0; //initialize variance with 0
    for(i=0;i<n;i++){
        variance += (arr[i] - mean)*(arr[i] - mean); //calculate the sum of squares of deviation from mean
    }
    variance = variance/n; //divide the sum by the number of elements to get the variance
    printf("\nThe variance value is: %.2f", variance);
    stddev = sqrt(variance); //calculate the square root of the variance to get the standard deviation
    printf("\nThe standard deviation value is: %.2f", stddev);
    diff = max-min; //calculate the difference between max and min
    printf("\nThe difference between maximum and minimum value is: %d", diff);
}

int main(){
    int n, i;
    printf("Enter the number of elements in the data set: ");
    scanf("%d", &n);
    int arr[n];
    dataMining(arr, n); //calling the dataMining function
    return 0;
}