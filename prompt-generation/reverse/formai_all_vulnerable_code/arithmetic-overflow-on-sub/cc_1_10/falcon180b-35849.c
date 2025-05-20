//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    int id;
    char name[32];
    int score;
} student_t;

void quick_sort(student_t arr[], int left, int right) {
    int i = left, j = right;
    student_t tmp;
    student_t pivot = arr[(left + right) / 2];

    if (i < j) {
        while (i <= j) {
            while (arr[i].score < pivot.score)
                i++;
            while (arr[j].score > pivot.score)
                j--;
            if (i <= j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
        }
        quick_sort(arr, left, j);
        quick_sort(arr, i, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    student_t arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &arr[i].id, arr[i].name, &arr[i].score);
    }

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d %s %d\n", arr[i].id, arr[i].name, arr[i].score);
    }

    return 0;
}