//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int key;
    char name[20];
} Item;

void swap(Item *a, Item *b) {
    Item temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(Item arr[], int n) {
    int i, j, bucket, index;
    Item *bucketArray[MAX_SIZE];

    for (i = 0; i < MAX_SIZE; i++) {
        bucketArray[i] = (Item *)malloc(sizeof(Item));
    }

    for (i = 0; i < n; i++) {
        bucket = arr[i].key % MAX_SIZE;
        index = 0;

        while (bucketArray[bucket] != NULL && bucketArray[bucket]->key < arr[i].key) {
            index++;
            bucket++;
        }

        for (j = i; j > index; j--) {
            arr[j] = arr[j - 1];
        }

        arr[j] = arr[i];
        bucketArray[bucket] = &arr[j];
    }

    for (i = 0; i < MAX_SIZE; i++) {
        if (bucketArray[i] != NULL) {
            for (j = 0; j < n; j++) {
                if (bucketArray[i]->key == arr[j].key) {
                    strcpy(arr[j].name, bucketArray[i]->name);
                    break;
                }
            }
            free(bucketArray[i]);
            bucketArray[i] = NULL;
        }
    }
}

void printArray(Item arr[], int n) {
    int i;

    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d %s\n", arr[i].key, arr[i].name);
    }
}

int main() {
    Item arr[MAX_SIZE];
    int i, n, j;
    char names[MAX_SIZE][20];

    srand(time(NULL));

    printf("Unsorted Array:\n");
    n = 0;

    do {
        arr[n].key = rand() % 100;
        printf("%d ", arr[n].key);
        scanf("%s", names[n]);
        strcpy(arr[n].name, names[n]);
        n++;
    } while (n < MAX_SIZE - 1 || getchar() != '\n');

    bucketSort(arr, n);
    printArray(arr, n);

    return 0;
}