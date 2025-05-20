//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct student {
    char name[50];
    int age;
    float marks;
} student;

void print_student(student s) {
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Marks: %.2f\n", s.marks);
}

int compare_students(const void *a, const void *b) {
    student *sa = (student *)a;
    student *sb = (student *)b;

    return strcmp(sa->name, sb->name);
}

int main() {
    student students[MAX_SIZE];
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter student %d details:\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    qsort(students, n, sizeof(student), compare_students);

    printf("\nSorted students:\n");
    for (int i = 0; i < n; i++) {
        print_student(students[i]);
        printf("\n");
    }

    return 0;
}