//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void generate_random_numbers(int arr[], int size);
void print_array(int arr[], int size);
void bubble_sort(int arr[], int size);
void selection_sort(int arr[], int size);
void insertion_sort(int arr[], int size);
void merge(int arr[], int left, int mid, int right);
void merge_sort(int arr[], int left, int right);
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the number of elements to sort (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size! Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    generate_random_numbers(arr, size);
    printf("Generated Array:\n");
    print_array(arr, size);

    // Bubble Sort
    printf("\nSorting using Bubble Sort:\n");
    bubble_sort(arr, size);
    print_array(arr, size);
    
    // Regenerate random numbers for new sort
    generate_random_numbers(arr, size);
    printf("\nGenerated Array for Selection Sort:\n");
    print_array(arr, size);
    
    // Selection Sort
    printf("\nSorting using Selection Sort:\n");
    selection_sort(arr, size);
    print_array(arr, size);

    // Regenerate random numbers for new sort
    generate_random_numbers(arr, size);
    printf("\nGenerated Array for Insertion Sort:\n");
    print_array(arr, size);
    
    // Insertion Sort
    printf("\nSorting using Insertion Sort:\n");
    insertion_sort(arr, size);
    print_array(arr, size);

    // Regenerate random numbers for new sort
    generate_random_numbers(arr, size);
    printf("\nGenerated Array for Merge Sort:\n");
    print_array(arr, size);
    
    // Merge Sort
    printf("\nSorting using Merge Sort:\n");
    merge_sort(arr, 0, size - 1);
    print_array(arr, size);

    // Regenerate random numbers for new sort
    generate_random_numbers(arr, size);
    printf("\nGenerated Array for Quick Sort:\n");
    print_array(arr, size);

    // Quick Sort
    printf("\nSorting using Quick Sort:\n");
    quick_sort(arr, 0, size - 1);
    print_array(arr, size);

    return 0;
}

void generate_random_numbers(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0 and 999
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}