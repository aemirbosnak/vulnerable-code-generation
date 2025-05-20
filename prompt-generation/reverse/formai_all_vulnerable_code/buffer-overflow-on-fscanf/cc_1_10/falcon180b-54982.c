//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

typedef struct {
    int num;
    char name[20];
} person;

void merge(person* arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;

    person temp[right - left + 1];

    while (i <= mid && j <= right) {
        if (arr[i].num <= arr[j].num) {
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

void mergeSort(person* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void readFile(person* arr, int size) {
    FILE* file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    int i = 0;

    while (fscanf(file, "%d %s", &arr[i].num, arr[i].name)!= EOF) {
        i++;
    }

    fclose(file);
}

void writeFile(person* arr, int size) {
    FILE* file = fopen("data.txt", "w");

    if (file == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d %s\n", arr[i].num, arr[i].name);
    }

    fclose(file);
}

int main() {
    person arr[SIZE];

    readFile(arr, SIZE);

    mergeSort(arr, 0, SIZE - 1);

    writeFile(arr, SIZE);

    return 0;
}