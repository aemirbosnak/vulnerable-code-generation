//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 1000

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionsort(int arr[], int n){
    int i,j;
    for(i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bucketsort(int arr[], int n){
    int i,j,k;
    int* bucket[SIZE];
    for(i=0;i<SIZE;i++)
        bucket[i] = NULL;
    for(i=0;i<n;i++){
        int index = arr[i]%SIZE;
        if(bucket[index] == NULL)
            bucket[index] = malloc(sizeof(int));
        int* temp = bucket[index];
        while(*temp!= -1){
            temp = temp+1;
        }
        *temp = arr[i];
    }
    for(i=0;i<SIZE;i++){
        if(bucket[i]!= NULL){
            for(j=0;j<n;j++){
                if(arr[j]%SIZE == i){
                    int key = arr[j];
                    int k = 0;
                    while(bucket[i][k]!= -1 && bucket[i][k] < key){
                        k++;
                    }
                    for(int l = k; l > 0; l--) {
                        bucket[i][l] = bucket[i][l-1];
                    }
                    bucket[i][k] = key;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        int index = arr[i]%SIZE;
        if(bucket[index]!= NULL){
            int* temp = bucket[index];
            while(*temp!= -1){
                if(*temp == arr[i]){
                    arr[i] = -1;
                    break;
                }
                temp++;
            }
        }
    }
}

void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    srand(time(0));
    for(int i=0;i<n;i++){
        int j = rand()%n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    printf("Randomized array:\n");
    printarray(arr,n);
    bucketsort(arr,n);
    printf("Sorted array:\n");
    printarray(arr,n);
    return 0;
}