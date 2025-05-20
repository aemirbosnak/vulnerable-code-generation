//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int arr[MAX], n, i;

//Function to get the maximum element in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

//Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = getMax(arr, n);
    int bucket[MAX];
    int count[MAX] = {0};

    //Create empty buckets
    for(int i=0; i<MAX; i++) {
        bucket[i] = -1;
    }

    //Place elements in the respective buckets
    for(int i=0; i<n; i++) {
        int index = arr[i]/max * MAX;
        bucket[index] = i;
        count[index]++;
    }

    //Sort the elements using the buckets
    int j = 0;
    for(int i=0; i<MAX; i++) {
        if(bucket[i]!= -1) {
            arr[j] = bucket[i];
            j++;
        }
    }
}

//Function to print the sorted array
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//Main function
int main() {
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    //Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    //Sort the array using bucket sort
    bucketSort(arr, n);

    //Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}