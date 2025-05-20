//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
} Student;

void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(Student arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, arr[i].name);
    }
}

int compareStudents(const void* a, const void* b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student* students = (Student*)calloc(n, sizeof(Student));

    for (int i = 0; i < n; i++) {
        printf("\nEnter student %d data:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);

        fflush(stdin); // To prevent issues with getline()
    }

    qsort(students, n, sizeof(Student), compareStudents);

    printf("\nSorted student list:\n");
    printArray(students, n);

    free(students);

    return 0;
}