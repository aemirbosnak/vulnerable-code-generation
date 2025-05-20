//Falcon-180B DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_KEYS 26

// Function prototypes
void init_array(char *arr, int size);
void print_array(char *arr, int size);
void swap_char(char *arr, int i, int j);
int partition(char *arr, int low, int high);
void quicksort(char *arr, int low, int high);
int main() {
    char arr[MAX_SIZE];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid array size!\n");
        return 1;
    }
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%c", &arr[i]);
    }
    init_array(arr, size);
    printf("Sorted array:\n");
    print_array(arr, size);
    return 0;
}

void init_array(char *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_KEYS + 'a';
    }
}

void print_array(char *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void swap_char(char *arr, int i, int j) {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(char *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap_char(arr, i, j);
        }
    }
    swap_char(arr, i + 1, high);
    return i + 1;
}

void quicksort(char *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}