//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 100

typedef struct {
    int id;
    char name[SIZE];
    char course[SIZE];
    int score;
} student;

void swap(student *a, student *b) {
    student temp = *a;
    *a = *b;
    *b = temp;
}

int compare(student a, student b) {
    if (a.score > b.score)
        return 1;
    else if (a.score == b.score)
        return 0;
    else
        return -1;
}

void sort(student arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (compare(arr[j], arr[j + 1]) < 0)
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main() {
    int n, i, j;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    student arr[n];

    for (i = 0; i < n; i++) {
        printf("Enter the ID, name, course and score of student %d:\n", i + 1);
        scanf("%d%s%s%d", &arr[i].id, arr[i].name, arr[i].course, &arr[i].score);
    }

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d\nName: %s\nCourse: %s\nScore: %d\n", arr[i].id, arr[i].name, arr[i].course, arr[i].score);
    }

    sort(arr, n);

    printf("\nAfter sorting:\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d\nName: %s\nCourse: %s\nScore: %d\n", arr[i].id, arr[i].name, arr[i].course, arr[i].score);
    }

    return 0;
}