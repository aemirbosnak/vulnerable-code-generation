//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STUDENTS 100

typedef struct Student {
    char name[50];
    int grade;
} Student;

void bubbleSortStudents(Student students[], int n) {
    int i, j, swapped;
    Student temp;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0 ||
                (strcmp(students[j].name, students[j + 1].name) == 0 && students[j].grade < students[j + 1].grade)) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
                swapped = 1;
            }
        }

        // If no two elements were swapped during the inner loop, then the array is already sorted
        if (!swapped)
            break;
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("\nEnter the student data:\n");

    for (i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        scanf("%s", students[i].name);
        scanf("%d", &students[i].grade);
    }

    bubbleSortStudents(students, n);

    printf("\nSorted student data:\n");

    for (i = 0; i < n; i++) {
        printf("Student %d:\nName: %s\nGrade: %d\n", i + 1, students[i].name, students[i].grade);
    }

    return 0;
}