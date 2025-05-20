//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int id;
    char name[20];
    float score;
} Record;

void quick_sort(Record arr[], int left, int right) {
    int i = left, j = right;
    Record pivot = arr[(left + right) / 2];
    Record temp;

    while (i <= j) {
        while (arr[i].score > pivot.score)
            i++;
        while (arr[j].score < pivot.score)
            j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quick_sort(arr, left, j);
    if (i < right)
        quick_sort(arr, i, right);
}

int main() {
    Record arr[MAX_SIZE];
    int n;
    FILE *fp;

    fp = fopen("records.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    n = 0;
    while (fscanf(fp, "%d %s %f", &arr[n].id, arr[n].name, &arr[n].score)!= EOF) {
        n++;
    }
    fclose(fp);

    quick_sort(arr, 0, n - 1);

    fp = fopen("sorted_records.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %.2f\n", arr[i].id, arr[i].name, arr[i].score);
    }

    fclose(fp);
    return 0;
}