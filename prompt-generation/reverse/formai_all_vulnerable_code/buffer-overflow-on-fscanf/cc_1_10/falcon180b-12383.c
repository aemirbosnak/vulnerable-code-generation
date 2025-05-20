//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000000

typedef struct {
    int id;
    char name[20];
    float score;
} Student;

void bubbleSort(Student arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].score < arr[j + 1].score) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    Student arr[MAX_SIZE];
    int n;
    FILE* fp;
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    n = 0;
    while (fscanf(fp, "%d %s %f", &arr[n].id, arr[n].name, &arr[n].score)!= EOF) {
        n++;
    }
    fclose(fp);
    bubbleSort(arr, n);
    fp = fopen("sorted_students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %f\n", arr[i].id, arr[i].name, arr[i].score);
    }
    fclose(fp);
    printf("Students sorted successfully.\n");
    return 0;
}