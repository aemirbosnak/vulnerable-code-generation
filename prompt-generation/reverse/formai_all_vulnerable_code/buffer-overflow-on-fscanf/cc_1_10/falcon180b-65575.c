//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10000
#define MAX 100

void bucketSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int i, n;
    int arr[SIZE];
    FILE *fp;
    struct tm *t;
    time_t now;

    now = time(NULL);
    t = localtime(&now);
    fp = fopen("/dev/urandom", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(0);
    }

    n = rand() % SIZE;

    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);
    printf("Before sorting:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("After sorting:\n");
    printArray(arr, n);

    return 0;
}

void bucketSort(int arr[], int n) {
    int i, j, max, min, temp;
    int buckets[MAX];

    for (i = 0; i < n; i++) {
        max = arr[i];
        min = arr[i];
        for (j = i + 1; j < n; j++) {
            if (arr[j] > max) {
                max = arr[j];
            }
            if (arr[j] < min) {
                min = arr[j];
            }
        }
        buckets[max - min]++;
    }

    for (i = 1; i < n; i++) {
        buckets[i] += buckets[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        temp = arr[i];
        for (j = 0; j < n; j++) {
            if (temp >= j * (n - 1) / n && temp < (j + 1) * (n - 1) / n) {
                arr[buckets[j] - 1] = temp;
                buckets[j]--;
                break;
            }
        }
    }
}

void printArray(int arr[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}