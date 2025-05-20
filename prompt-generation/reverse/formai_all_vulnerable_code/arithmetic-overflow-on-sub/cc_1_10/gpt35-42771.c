//FormAI DATASET v1.0 Category: Sorting ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

void swap(int*, int*);

void quick_sort(int[], int, int);
int partition(int[], int, int);

int main(){
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    quick_sort(arr,0,n-1);

    printf("Sorted array: ");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int arr[], int low, int high){
    if(low<high) //if there are more than one element
    {
        int p_index = partition(arr, low, high);
        quick_sort(arr, low, p_index-1);
        quick_sort(arr, p_index+1, high);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low-1);
    int j;

    for(j=low;j<=high;j++){
        if(arr[j]<pivot){
            i++; //increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return (i+1);
}