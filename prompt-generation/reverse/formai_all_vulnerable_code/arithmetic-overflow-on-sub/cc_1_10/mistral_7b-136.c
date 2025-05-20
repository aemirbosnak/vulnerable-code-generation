//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int left;
    int right;
    int mid;
    int *arr;
} merge_sort_args;

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

void merge_sort_helper(merge_sort_args *args) {
    if (args->right - args->left < 2) {
        return;
    }

    merge_sort_args left_args, right_args;

    left_args.left = args->left;
    left_args.right = args->mid;
    left_args.mid = args->mid;
    left_args.arr = args->arr;

    right_args.left = args->mid + 1;
    right_args.right = args->right;
    right_args.mid = args->mid;
    right_args.arr = args->arr;

    merge_sort_helper(&left_args);
    merge_sort_helper(&right_args);
    merge(args->arr, args->left, args->mid, args->right);
}

void merge_sort(int arr[], int left, int right) {
    merge_sort_args args;
    args.left = left;
    args.right = right;
    args.mid = (left + right) / 2;
    args.arr = arr;

    merge_sort_helper(&args);
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);
    print_array(arr, n);

    return 0;
}