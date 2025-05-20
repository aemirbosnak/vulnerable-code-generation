//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void create_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % SIZE;
    }
}

void display_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int num_buckets = max_val / SIZE + 1;
    int *buckets[num_buckets];

    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = malloc(sizeof(int) * n);
    }

    for (int i = 0; i < n; i++) {
        int bucket_idx = arr[i] / SIZE;
        int *bucket = buckets[bucket_idx];
        int j = 0;
        while (j < i && arr[j] == arr[i]) {
            j++;
        }
        if (j == i) {
            bucket[j] = arr[i];
        } else {
            for (int k = j; k < i; k++) {
                arr[k] = arr[k + 1];
            }
            arr[i] = arr[j];
        }
    }

    for (int i = 0; i < num_buckets; i++) {
        int j = 0;
        while (j < n && buckets[i][j] == -1) {
            j++;
        }
        for (int k = j; k < n; k++) {
            arr[k] = buckets[i][k];
        }
    }

    for (int i = 0; i < num_buckets; i++) {
        free(buckets[i]);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    create_array(arr, n);

    display_array(arr, n);

    bucket_sort(arr, n);

    display_array(arr, n);

    return 0;
}