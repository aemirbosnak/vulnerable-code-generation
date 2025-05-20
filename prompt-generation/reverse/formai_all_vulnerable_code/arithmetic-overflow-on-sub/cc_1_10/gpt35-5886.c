//FormAI DATASET v1.0 Category: Sorting ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

//Function to swap elements
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to perform sorting
void sort(int arr[], int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(){
    int n,i,sortType;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d elements: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Choose the sorting type:\n");
    printf("1. Ascending order\n2. Descending order\n");
    scanf("%d",&sortType);

    switch(sortType){
        case 1: //Ascending order
            sort(arr,n);
            printf("Sorted array in ascending order:\n");
            for(i=0;i<n;i++){
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;

        case 2: //Descending order
            sort(arr,n);
            printf("Sorted array in descending order:\n");
            for(i=n-1;i>=0;i--){
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}