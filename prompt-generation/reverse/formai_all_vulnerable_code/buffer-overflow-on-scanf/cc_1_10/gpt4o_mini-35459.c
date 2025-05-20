//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

// Function Declarations
void initialize_array(int arr[], int size);
void print_array(const int arr[], int size);
void perform_arithmetic_operations(const int arr[], int size);
double calculate_mean(const int arr[], int size);
double calculate_variance(const int arr[], int size, double mean);
void sort_array(int arr[], int size);
void display_sorted_array(const int arr[], int size);
void find_mode(const int arr[], int size);
void calculate_median(int arr[], int size);

int main() {
    int array[MAX_SIZE];
    int n;

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid number of elements. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    initialize_array(array, n);
    
    printf("Original array: ");
    print_array(array, n);

    perform_arithmetic_operations(array, n);
    
    return 0;
}

void initialize_array(int arr[], int size) {
    printf("Enter %d integers for the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void print_array(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void perform_arithmetic_operations(const int arr[], int size) {
    double mean = calculate_mean(arr, size);
    printf("Mean of the array is: %.2f\n", mean);

    double variance = calculate_variance(arr, size, mean);
    printf("Variance of the array is: %.2f\n", variance);

    sort_array((int *)arr, size);
    
    display_sorted_array(arr, size);
    
    find_mode(arr, size);
    
    calculate_median((int *)arr, size);
}

double calculate_mean(const int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

double calculate_variance(const int arr[], int size, double mean) {
    double variance_sum = 0;
    for (int i = 0; i < size; i++) {
        variance_sum += pow(arr[i] - mean, 2);
    }
    return variance_sum / size;
}

void sort_array(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display_sorted_array(const int arr[], int size) {
    printf("Sorted array: ");
    print_array(arr, size);
}

void find_mode(const int arr[], int size) {
    int max_count = 0, mode = arr[0], count;
    for (int i = 0; i < size; i++) {
        count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            mode = arr[i];
        }
    }
    
    if (max_count > 1) {
        printf("Mode of the array is: %d\n", mode);
    } else {
        printf("No mode found for the array.\n");
    }
}

void calculate_median(int arr[], int size) {
    if (size % 2 == 0) {
        double median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
        printf("Median of the array is: %.2f\n", median);
    } else {
        printf("Median of the array is: %d\n", arr[size / 2]);
    }
}