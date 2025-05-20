//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[20];
} Student;

void swap(Student* a, Student* b) {
    Student temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Student arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
            if (arr[j].id > arr[j + 1].id) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Student students[MAX_SIZE];
    int i;

    for (i = 0; i < MAX_SIZE; i++) {
        students[i].id = rand() % 100 + 1;
        students[i].id = i + 1;
        strcpy(students[i].name, "");

        int len = rand() % 20 + 1;
        students[i].name[len] = '\0';

        for (int j = 0; j < len; j++) {
            students[i].name[j] = 'A' + (rand() % 26);
        }
    }

    bubbleSort(students, MAX_SIZE);

    printf("Sorted Students:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("Student %d: ID = %d, Name = %s\n", i + 1, students[i].id, students[i].name);
    }

    return 0;
}