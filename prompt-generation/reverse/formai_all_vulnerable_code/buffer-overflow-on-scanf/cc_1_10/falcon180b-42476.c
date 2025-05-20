//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_VALUE 100

void bucketSort(int array[], int size);

int main() {
    int array[MAX_SIZE];
    int size;

    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");

    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    bucketSort(array, size);

    printf("Sorted array:\n");

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

void bucketSort(int array[], int size) {
    int bucket[MAX_VALUE];
    int i, j;

    for (i = 0; i < size; i++) {
        int value = array[i];
        int index = value % MAX_VALUE;

        if (bucket[index] == -1) {
            bucket[index] = i;
        } else {
            int temp = i;
            i = bucket[index];
            while (bucket[index]!= -1) {
                index = (index + 1) % MAX_VALUE;
            }
            bucket[index] = temp;
        }
    }

    for (i = 0; i < MAX_VALUE; i++) {
        if (bucket[i]!= -1) {
            int index = (i * MAX_SIZE) / MAX_VALUE;

            while (bucket[i]!= -1) {
                int value = array[bucket[i]];
                array[bucket[i]] = -1;
                array[index] = value;
                index++;
                bucket[i] = (bucket[i] + 1) % MAX_SIZE;
            }
        }
    }
}