//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int i, j, n;
    int* arr;
    double* times;
    FILE* fp;
    char filename[50];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory error!");
        exit(1);
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    times = (double*) malloc(MAX_SIZE * sizeof(double));
    if (times == NULL) {
        printf("Memory error!");
        exit(1);
    }

    for (i = 0; i < MAX_SIZE; i++) {
        times[i] = 0.0;
    }

    for (j = 0; j < n; j++) {
        sprintf(filename, "bucket_%d.txt", arr[j]);
        fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("File error!");
            exit(1);
        }

        for (i = 0; i < n; i++) {
            if (arr[i] == arr[j]) {
                fprintf(fp, "%d ", i);
            }
        }

        fclose(fp);
    }

    for (j = 0; j < n; j++) {
        sprintf(filename, "bucket_%d.txt", arr[j]);
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("File error!");
            exit(1);
        }

        while (fscanf(fp, "%d", &i)!= EOF) {
            times[arr[i]] += 1.0;
        }

        fclose(fp);
    }

    printf("Bucket sort completed in %.6f seconds.\n", times[arr[0]]);

    free(arr);
    free(times);

    return 0;
}