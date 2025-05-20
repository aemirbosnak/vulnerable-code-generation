//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int data_mining(int *data, int size) {
    int i, j, k, max = 0, count = 0;
    int *frequency = (int *) malloc(sizeof(int) * size);
    int *position = (int *) malloc(sizeof(int) * size);

    for (i = 0; i < size; i++) {
        frequency[data[i]]++;
    }

    for (i = 0; i < size; i++) {
        position[data[i]] = count;
        count += frequency[data[i]];
    }

    for (i = 0; i < size; i++) {
        if (frequency[data[i]] > max) {
            max = frequency[data[i]];
            k = data[i];
        }
    }

    printf("Mode: %d\n", k);

    free(frequency);
    free(position);

    return 0;
}

int main() {
    int i, n, data[100];

    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    data_mining(data, n);

    return 0;
}