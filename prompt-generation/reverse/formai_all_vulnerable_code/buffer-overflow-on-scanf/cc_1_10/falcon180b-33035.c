//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define BUCKET_SIZE 10

typedef struct {
    int data;
    int index;
} Element;

void createBuckets(Element *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i].index = -1;
    }
}

void insertElement(Element *arr, int n, int key) {
    int index = key / BUCKET_SIZE;
    if (arr[index].index == -1) {
        arr[index].index = index;
    }
    else {
        int tempIndex = arr[index].index;
        while (tempIndex!= -1) {
            tempIndex = arr[tempIndex].index;
        }
        arr[tempIndex].index = index;
    }
    arr[index].data = key;
}

void sort(Element *arr, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (arr[i].index!= -1) {
            int temp = arr[i].data;
            int tempIndex = arr[i].index;
            while (tempIndex!= -1) {
                int index = tempIndex;
                tempIndex = arr[tempIndex].index;
                arr[index].data = arr[tempIndex].data;
            }
            arr[tempIndex].data = temp;
        }
    }
}

void printArray(Element *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i].index!= -1) {
            printf("%d ", arr[i].data);
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    Element *arr = (Element *)malloc(n * sizeof(Element));
    createBuckets(arr, n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        insertElement(arr, n, arr[i].data);
    }
    sort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}