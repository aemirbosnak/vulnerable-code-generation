//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Recursive function to calculate the Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Recursive function to calculate the sum of the digits of a number
int sumOfDigits(int n) {
    if (n < 10) {
        return n;
    } else {
        return n % 10 + sumOfDigits(n / 10);
    }
}

// Recursive function to reverse a string
char *reverseString(char *str) {
    if (*str == '\0') {
        return str;
    } else {
        char *reversed = reverseString(str + 1);
        *str = *(str + 1);
        *(str + 1) = *reversed;
        return reversed;
    }
}

// Recursive function to find the maximum element in an array
int maxElement(int *arr, int n) {
    if (n == 1) {
        return arr[0];
    } else {
        int max = maxElement(arr + 1, n - 1);
        return arr[0] > max ? arr[0] : max;
    }
}

// Recursive function to sort an array using the merge sort algorithm
void mergeSort(int *arr, int n) {
    if (n <= 1) {
        return;
    }
    int mid = n / 2;
    int *left = malloc(mid * sizeof(int));
    int *right = malloc((n - mid) * sizeof(int));
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < mid) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n - mid) {
        arr[k] = right[j];
        j++;
        k++;
    }
    free(left);
    free(right);
}

int main() {
    // Calculate the factorial of a number
    int n;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);
    printf("The factorial of %d is %d\n", n, factorial(n));

    // Calculate the Fibonacci sequence
    n;
    printf("Enter a number to calculate its Fibonacci sequence: ");
    scanf("%d", &n);
    printf("The Fibonacci sequence of %d is %d\n", n, fibonacci(n));

    // Calculate the sum of the digits of a number
    n;
    printf("Enter a number to calculate the sum of its digits: ");
    scanf("%d", &n);
    printf("The sum of the digits of %d is %d\n", n, sumOfDigits(n));

    // Reverse a string
    char str[100];
    printf("Enter a string to reverse: ");
    scanf("%s", str);
    printf("The reversed string is %s\n", reverseString(str));

    // Find the maximum element in an array
    int arr[100];
    n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The maximum element in the array is %d\n", maxElement(arr, n));

    // Sort an array using the merge sort algorithm
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, n);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}