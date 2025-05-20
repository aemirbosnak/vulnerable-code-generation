//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
} Student;

void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Student arr[], int low, int high) {
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

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student* students = (Student*) malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &students[i].id);
        printf("Enter Name: ");
        scanf("%s", students[i].name);
    }

    printf("\nUnsorted Student List:\n");
    for (int i = 0; i < n; i++) {
        printf("\nID: %d, Name: %s", students[i].id, students[i].name);
    }

    srand(time(NULL));
    quickSort(students, 0, n - 1);

    printf("\nSorted Student List:\n");
    for (int i = 0; i < n; i++) {
        printf("\nID: %d, Name: %s", students[i].id, students[i].name);
    }

    free(students);
    return 0;
}