//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATER_SOURCES 100

typedef struct {
    char name[20];
    float purity;
    int capacity;
} WaterSource;

void swap(WaterSource *a, WaterSource *b) {
    WaterSource temp = *a;
    *a = *b;
    *b = temp;
}

int partition(WaterSource arr[], int low, int high) {
    int pivot = high;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].purity > arr[pivot].purity || (arr[j].purity == arr[pivot].purity && arr[j].capacity > arr[pivot].capacity)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[pivot]);
    return (i + 1);
}

void quickSort(WaterSource arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of known water sources: ");
    scanf("%d", &n);

    WaterSource waterSources[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the name, purity, and capacity of water source %d: ", i + 1);
        scanf("%s", waterSources[i].name);
        scanf("%f", &waterSources[i].purity);
        scanf("%d", &waterSources[i].capacity);
    }

    quickSort(waterSources, 0, n - 1);

    printf("\nThe water source with the highest purity and maximum capacity is: ");
    printf("%s. Its purity is %.2f and its capacity is %d.\n", waterSources[0].name, waterSources[0].purity, waterSources[0].capacity);

    return 0;
}