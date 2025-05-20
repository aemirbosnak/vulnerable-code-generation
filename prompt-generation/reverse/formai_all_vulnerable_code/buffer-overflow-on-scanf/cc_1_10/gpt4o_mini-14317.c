//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: minimalist
#include <stdio.h>

#define MAX_SIZE 100

// Function declarations
void inputArray(int arr[], int size);
void displayArray(int arr[], int size);
int addElements(int arr[], int size);
int subtractElements(int arr[], int size);
int multiplyElements(int arr[], int size);
float divideElements(int arr[], int size);
void calculateResults(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size;

    // Input size of the array
    printf("Enter the number of elements (1 - %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Validate size
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size!\n");
        return 1;
    }

    // Input elements of the array
    inputArray(arr, size);
    
    // Display elements of the array
    printf("The elements of the array are:\n");
    displayArray(arr, size);
    
    // Calculate and display results
    calculateResults(arr, size);

    return 0;
}

void inputArray(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int addElements(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int subtractElements(int arr[], int size) {
    int result = arr[0];
    for (int i = 1; i < size; i++) {
        result -= arr[i];
    }
    return result;
}

int multiplyElements(int arr[], int size) {
    int product = 1;
    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }
    return product;
}

float divideElements(int arr[], int size) {
    if (size == 0 || arr[0] == 0) {
        printf("Division not possible!\n");
        return 0;
    }
    
    float result = (float)arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] == 0) {
            printf("Division by zero encountered!\n");
            return 0;
        }
        result /= arr[i];
    }
    return result;
}

void calculateResults(int arr[], int size) {
    int sum = addElements(arr, size);
    int difference = subtractElements(arr, size);
    int product = multiplyElements(arr, size);
    float quotient = divideElements(arr, size);

    printf("Sum of elements: %d\n", sum);
    printf("Difference of elements: %d\n", difference);
    printf("Product of elements: %d\n", product);
    
    if (quotient != 0) {
        printf("Quotient of elements: %.2f\n", quotient);
    }
}