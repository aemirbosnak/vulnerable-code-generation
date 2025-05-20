//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include<stdio.h>

//Function to perform counting sort within each bucket
void countingSort(int arr[], int n){
    int output[100];
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    int count[100] = {0};
    for (i = 0; i < n; i++)
        count[arr[i]]++;
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

//Function to perform bucket sort
void bucketSort(float arr[], int n){
    int i, j;
    float bucket[100][1000];
    int bucket_index[100] = { 0 };
    for (i = 0; i < n; i++){
        int bucket_id = arr[i] * 10;
        bucket[bucket_id][bucket_index[bucket_id]] = arr[i];
        bucket_index[bucket_id]++;
    }
    for (i = 0; i < 100; i++)
        countingSort(bucket[i], bucket_index[i]);
    int index = 0;
    for (i = 0; i < 100; i++)
        for (j = 0; j < bucket_index[i]; j++)
            arr[index++] = bucket[i][j];
}

//Main function to test the bucket sort implementation
int main(){
    int n, i;
    float arr[1000];
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%f", &arr[i]);
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
    return 0;
}