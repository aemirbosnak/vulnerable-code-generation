//FormAI DATASET v1.0 Category: Recursive ; Style: innovative
#include <stdio.h>

int recursiveFactorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * recursiveFactorial(n-1);
    }
}

int recursiveFibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
    }
}

int palindromeChecker(char string[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex) {
        return 1;
    } else {
        if (string[leftIndex] == string[rightIndex]) {
            return palindromeChecker(string, leftIndex+1, rightIndex-1);
        } else {
            return 0;
        }
    }
}

void recursiveBinarySearch(int arr[], int leftIndex, int rightIndex, int searchValue) {
    if (leftIndex <= rightIndex) {
        int mid = (leftIndex + rightIndex) / 2;
        if (arr[mid] == searchValue) {
            printf("%d is found at index %d.", searchValue, mid);
        } else if (arr[mid] < searchValue) {
            recursiveBinarySearch(arr, mid+1, rightIndex, searchValue);
        } else {
            recursiveBinarySearch(arr, leftIndex, mid-1, searchValue);
        }
    } else {
        printf("%d is not found in the array.", searchValue);
    }
}

int main() {
    printf("Enter a positive integer n to calculate its factorial: ");
    int n;
    scanf("%d", &n);
    int result = recursiveFactorial(n);
    printf("%d! = %d\n", n, result);

    printf("Enter a positive integer n to calculate the nth Fibonacci number: ");
    scanf("%d", &n);
    result = recursiveFibonacci(n);
    printf("The %dth Fibonacci number is %d\n", n, result);

    char string[100];
    printf("Enter a string to check if it's a palindrome: ");
    scanf("%s", string);
    int isPalindrome = palindromeChecker(string, 0, strlen(string)-1);
    if (isPalindrome) {
        printf("%s is a palindrome.\n", string);
    } else {
        printf("%s is not a palindrome.\n", string);
    }

    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Enter a value to search in the array {1, 3, 5, 7, 9}: ");
    scanf("%d", &n);
    recursiveBinarySearch(arr, 0, size-1, n);
    
    return 0;
}