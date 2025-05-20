//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAX_SIZE 50

typedef struct {
    int id;
    char name[MAX_SIZE];
} Record;

void swap(Record *a, Record *b) {
    Record temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Record arr[], int low, int high) {
    int pivot = arr[high].id;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].id < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Record arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of records: ");
    scanf("%d", &n);

    Record *records = (Record *)malloc(n * sizeof(Record));

    for (int i = 0; i < n; i++) {
        records[i].id = rand() % 100 + 1;
        records[i].name[0] = '\0';
        int len = 0;

        printf("Enter name for record %d: ", i + 1);
        char name[MAX_SIZE];
        fgets(name, MAX_SIZE, stdin);
        name[strcspn(name, "\n")] = '\0';

        strcpy(records[i].name, name);
        len = strlen(records[i].name);
        if (len > MAX_SIZE - 1) {
            printf("Error: Name too long. Name truncated.\n");
            records[i].name[MAX_SIZE - 1] = '\0';
        }
    }

    quickSort(records, 0, n - 1);

    printf("\nSorted records:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Name: %s\n", records[i].id, records[i].name);
    }

    free(records);
    return 0;
}