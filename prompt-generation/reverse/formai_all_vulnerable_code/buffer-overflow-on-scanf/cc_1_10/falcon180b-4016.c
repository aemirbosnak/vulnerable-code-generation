//Falcon-180B DATASET v1.0 Category: Recursive ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = malloc(n1 * sizeof(int));
    int* R = malloc(n2 * sizeof(int));
    for(int i=0; i<n1; i++){
        L[i] = arr[left + i];
    }
    for(int j=0; j<n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right){
    if(left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Original array:\n");
    printArray(arr, n);
    mergeSort(arr, 0, n-1);
    printf("Sorted array:\n");
    printArray(arr, n);
    free(arr);
    return 0;
}