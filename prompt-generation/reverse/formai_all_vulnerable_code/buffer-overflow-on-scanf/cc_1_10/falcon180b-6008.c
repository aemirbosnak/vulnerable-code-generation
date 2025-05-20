//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 10

typedef struct {
    int data;
    int index;
} Element;

void init_array(Element arr[], int n);
void print_array(Element arr[], int n);
void bucket_sort(Element arr[], int n);
void insertion_sort(Element arr[], int n);

int main() {
    Element arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    init_array(arr, n);
    printf("Original array:\n");
    print_array(arr, n);

    bucket_sort(arr, n);
    printf("\nSorted array:\n");
    print_array(arr, n);

    return 0;
}

void init_array(Element arr[], int n) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }
}

void print_array(Element arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

void bucket_sort(Element arr[], int n) {
    Element buckets[BUCKET_SIZE];

    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i].data / BUCKET_SIZE;
        buckets[bucket_index].index = i;
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        insertion_sort(buckets, i == 0? n : 0);
    }

    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < buckets[i].index; j++) {
            arr[index++] = arr[buckets[i].index - j - 1];
        }
    }
}

void insertion_sort(Element arr[], int n) {
    for (int i = 1; i < n; i++) {
        Element key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].data > key.data) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}