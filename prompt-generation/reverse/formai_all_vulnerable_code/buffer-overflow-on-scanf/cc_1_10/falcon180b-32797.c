//Falcon-180B DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX 100
#define NUM_THREADS 4

int arr[MAX];
int n;
int part;

struct thread_data {
    int start;
    int end;
};

void *runner(void *param) {
    struct thread_data *data = param;

    int i, j, temp;
    for (i = data->start; i < data->end; i++) {
        for (j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
}

void merge(int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void merge_sort(int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    merge_sort(left, mid);
    merge_sort(mid + 1, right);

    merge(left, mid, right);
}

int main() {
    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    pthread_t threads[NUM_THREADS];
    struct thread_data data[NUM_THREADS];

    int chunk = n / NUM_THREADS;
    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].start = i * chunk;
        data[i].end = (i == NUM_THREADS - 1)? n - 1 : (i + 1) * chunk - 1;
        pthread_create(&threads[i], NULL, runner, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}