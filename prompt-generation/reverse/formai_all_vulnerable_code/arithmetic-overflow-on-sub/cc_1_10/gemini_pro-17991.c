//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Fibonacci sequence using recursion
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// Factorial using recursion
int fact(int n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

// Power using recursion
int pow(int x, int n) {
    if (n == 0)
        return 1;
    return x * pow(x, n - 1);
}

// Greatest Common Divisor using recursion
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Least Common Multiple using recursion
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// Binary search using recursion
int binary_search(int arr[], int l, int r, int x) {
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (arr[mid] == x)
        return mid;
    if (arr[mid] < x)
        return binary_search(arr, mid + 1, r, x);
    return binary_search(arr, l, mid - 1, x);
}

// Merge sort using recursion
void merge_sort(int arr[], int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    int temp[r - l + 1];
    while (i <= mid && j <= r) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (i = l, k = 0; i <= r; i++, k++)
        arr[i] = temp[k];
}

// Quick sort using recursion
void quick_sort(int arr[], int l, int r) {
    if (l >= r)
        return;
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    quick_sort(arr, l, i);
    quick_sort(arr, i + 2, r);
}

// Selection sort using recursion
void selection_sort(int arr[], int n) {
    if (n <= 1)
        return;
    int min = arr[0];
    int min_idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            min_idx = i;
        }
    }
    int temp = arr[0];
    arr[0] = arr[min_idx];
    arr[min_idx] = temp;
    selection_sort(arr + 1, n - 1);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Fibonacci of %d is %d\n", n, fib(n));
    printf("Factorial of %d is %d\n", n, fact(n));
    printf("Power of 2 to the power of %d is %d\n", n, pow(2, n));
    printf("GCD of 12 and 18 is %d\n", gcd(12, 18));
    printf("LCM of 12 and 18 is %d\n", lcm(12, 18));
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int x = 7;
    int result = binary_search(arr, 0, 7, x);
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", result);
    int arr2[] = {1, 3, 5, 7, 9, 11, 13, 15};
    merge_sort(arr2, 0, 7);
    printf("Sorted array: ");
    for (int i = 0; i < 8; i++)
        printf("%d ", arr2[i]);
    printf("\n");
    int arr3[] = {1, 3, 5, 7, 9, 11, 13, 15};
    quick_sort(arr3, 0, 7);
    printf("Sorted array: ");
    for (int i = 0; i < 8; i++)
        printf("%d ", arr3[i]);
    printf("\n");
    int arr4[] = {1, 3, 5, 7, 9, 11, 13, 15};
    selection_sort(arr4, 8);
    printf("Sorted array: ");
    for (int i = 0; i < 8; i++)
        printf("%d ", arr4[i]);
    printf("\n");
    return 0;
}