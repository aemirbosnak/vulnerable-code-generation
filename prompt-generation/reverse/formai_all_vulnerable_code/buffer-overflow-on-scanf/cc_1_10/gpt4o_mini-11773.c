//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 100
#define MAX_LENGTH 20
#define SWAP(a,b) { int temp = a; a = b; b = temp; }

void printArray(int arr[], int size);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void displayMenu();

int main() {
    int arr[MAX_NUMBERS];
    int n, choice;

    printf("Welcome to the Magical Sorting Hall!\n");
    printf("Enter the number of elements (max %d): ", MAX_NUMBERS);
    scanf("%d", &n);
    
    if (n < 1 || n > MAX_NUMBERS) {
        printf("Invalid number of elements. Exiting...\n");
        return 1;
    }

    printf("Input %d numbers separated by spaces: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    displayMenu();
    printf("Choose a sorting algorithm (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You chose Bubble Sort!\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("You chose Selection Sort!\n");
            selectionSort(arr, n);
            break;
        case 3:
            printf("You chose Insertion Sort!\n");
            insertionSort(arr, n);
            break;
        case 4:
            printf("You chose Merge Sort!\n");
            mergeSort(arr, 0, n - 1);
            break;
        case 5:
            printf("You chose Quick Sort!\n");
            quickSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice! Exiting...\n");
            return 1;
    }

    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                SWAP(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        SWAP(arr[min_idx], arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

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

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            SWAP(arr[i], arr[j]);
        }
    }
    SWAP(arr[i + 1], arr[high]);
    return (i + 1);
}

void displayMenu() {
    printf("\n*** Magical Sorting Menu ***\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("****************************\n");
}