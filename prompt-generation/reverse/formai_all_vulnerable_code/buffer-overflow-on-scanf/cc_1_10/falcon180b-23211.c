//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define RANGE 100

int arr[MAX];
int bucket[RANGE];
int n;

void generate_random_array(int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % RANGE;
    }
}

void print_array(int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int size) {
    for (int i = 0; i < RANGE; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        bucket[arr[i]]++;
    }
    int j = 0;
    for (int i = 0; i < RANGE; i++) {
        for (int k = 0; k < bucket[i]; k++) {
            arr[j++] = i;
        }
    }
}

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    generate_random_array(n);
    printf("Original array:\n");
    print_array(n);
    bucket_sort(n);
    printf("Sorted array:\n");
    print_array(n);
    return 0;
}