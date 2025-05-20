//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[50];
} Student;

void swap(Student *a, Student *b) {
    Student temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Student arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    Student students[MAX_SIZE];
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("\nEnter the details of students:\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        fflush(stdin);
        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        strtok(students[i].name, "\n");

        bubbleSort(students, n);
    }

    printf("\nSorted Students:\n");
    for (i = 0; i < n; i++) {
        printf("\nID: %d\nName: %s", students[i].id, students[i].name);
    }

    return 0;
}