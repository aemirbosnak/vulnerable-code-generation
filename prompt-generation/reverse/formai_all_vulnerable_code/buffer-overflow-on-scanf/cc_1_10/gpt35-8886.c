//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 10000

void merge(int* nums, int left, int mid, int right);
void merge_sort(int* nums, int left, int right);
void print_array(int* nums, int n);

int main() {
    int nums[MAX_NUMS];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX_NUMS) {
        printf("Maximum number of elements exceeded.");
        return 1;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Unsorted array: ");
    print_array(nums, n);

    merge_sort(nums, 0, n - 1);

    printf("Sorted array: ");
    print_array(nums, n);

    return 0;
}

void merge(int* nums, int left, int mid, int right) {
    int i, j, k;
    int n_left = mid - left + 1;
    int n_right = right - mid;

    int left_arr[n_left];
    int right_arr[n_right];

    for (i = 0; i < n_left; i++) {
        left_arr[i] = nums[left + i];
    }

    for (j = 0; j < n_right; j++) {
        right_arr[j] = nums[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n_left && j < n_right) {
        if (left_arr[i] <= right_arr[j]) {
            nums[k++] = left_arr[i++];
        } else {
            nums[k++] = right_arr[j++];
        }
    }

    while (i < n_left) {
        nums[k++] = left_arr[i++];
    }

    while (j < n_right) {
        nums[k++] = right_arr[j++];
    }
}

void merge_sort(int* nums, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        merge_sort(nums, left, mid);
        merge_sort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }
}

void print_array(int* nums, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");
}