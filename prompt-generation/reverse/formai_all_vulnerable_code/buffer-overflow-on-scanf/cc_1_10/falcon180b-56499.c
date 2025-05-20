//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000
#define NUM_ALPHABETS 26

// Function to compare two strings
int compare(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = (len1 < len2)? len1 : len2;

    for (int i = 0; i < min_len; i++) {
        if (tolower(str1[i])!= tolower(str2[i])) {
            return 1;
        }
    }

    return 0;
}

// Function to perform linear search
int linear_search(char* arr[], int n, char* target) {
    for (int i = 0; i < n; i++) {
        if (compare(arr[i], target) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to perform binary search
int binary_search(char* arr[], int n, char* target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = compare(arr[mid], target);

        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    char arr[MAX_SIZE];
    int n, choice;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr + i * MAX_SIZE);
    }

    printf("Enter the search mode:\n1. Linear search\n2. Binary search\n");
    scanf("%d", &choice);

    char target[MAX_SIZE];
    printf("Enter the target string: ");
    scanf("%s", target);

    int result;

    switch (choice) {
        case 1:
            result = linear_search(arr, n, target);
            break;
        case 2:
            result = binary_search(arr, n, target);
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    if (result == -1) {
        printf("String not found!\n");
    } else {
        printf("String found at position %d!\n", result);
    }

    return 0;
}