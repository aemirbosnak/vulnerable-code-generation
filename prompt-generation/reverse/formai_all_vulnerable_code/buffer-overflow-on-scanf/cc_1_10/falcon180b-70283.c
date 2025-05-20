//Falcon-180B DATASET v1.0 Category: Sorting ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1000

int arr[MAX];
int n;

void merge(int arr[], int mid, int left, int right) {
    int i, j, k;
    int temp[MAX];

    i = left;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void merge_sort(int arr[], int left, int right) {
    int mid;

    if (left >= right) {
        return;
    }

    mid = left + (right - left) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, mid, left, right);
}

void *thread_sort(void *args) {
    int i, j;
    int start, end;

    for (i = 0; i < n / 2; i++) {
        start = i * (n / 2);
        end = start + (n / 2) - 1;
        merge_sort(arr, start, end);
    }
}

int main() {
    int i;
    pthread_t thread_id[n];

    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n / 2; i++) {
        pthread_create(&thread_id[i], NULL, thread_sort, (void *)&arr[i * (n / 2)]);
    }

    for (i = 0; i < n / 2; i++) {
        pthread_join(thread_id[i], NULL);
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}