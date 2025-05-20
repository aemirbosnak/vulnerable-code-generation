//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *arr;
int n;

void createArr(int n){
    arr = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        arr[i] = rand()%100;
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int n){
    int bucketSize = n/10;
    int *bucket[10];
    for(int i=0;i<10;i++){
        bucket[i] = malloc(bucketSize*sizeof(int));
    }
    int j = 0;
    for(int i=0;i<n;i++){
        j++;
        if(j == 10){
            j = 0;
        }
        bucket[j] = realloc(bucket[j], (j+1)*sizeof(int));
        bucket[j][j] = arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i] = bucket[arr[i]/10][arr[i]%10];
    }
    for(int i=0;i<10;i++){
        free(bucket[i]);
    }
}

int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    arr = malloc(n*sizeof(int));
    createArr(n);
    printf("Before sorting:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    clock_t start = clock();
    bucketSort(n);
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("After sorting:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nTime taken for sorting: %lf seconds\n",time);
    free(arr);
    return 0;
}