//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void generate_random_array(int arr[], int size);
void print_array(int arr[], int size);
void bubble_sort(int arr[], int size);
void selection_sort(int arr[], int size);
void insertion_sort(int arr[], int size);
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void menu();
void execute_sorting_option(int option);

int main() {
    int choice;

    do {
        menu();
        printf("Enter your choice (1-6) or 0 to exit: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6) {
            execute_sorting_option(choice);
        } else if (choice != 0) {
            printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 0);

    printf("Exiting the program. Goodbye!\n");
    return 0;
}

void menu() {
    printf("\nSorting Algorithm Menu:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Generate Random Array\n");
}

void generate_random_array(int arr[], int size) {
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
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
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

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
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
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void execute_sorting_option(int option) {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the number of elements to sort (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return;
    }

    generate_random_array(arr, size);
    printf("Generated Array: ");
    print_array(arr, size);

    switch (option) {
        case 1:
            bubble_sort(arr, size);
            printf("Bubble Sorted Array: ");
            break;
        case 2:
            selection_sort(arr, size);
            printf("Selection Sorted Array: ");
            break;
        case 3:
            insertion_sort(arr, size);
            printf("Insertion Sorted Array: ");
            break;
        case 4:
            merge_sort(arr, 0, size - 1);
            printf("Merge Sorted Array: ");
            break;
        case 5:
            quick_sort(arr, 0, size - 1);
            printf("Quick Sorted Array: ");
            break;
    }

    print_array(arr, size);
}