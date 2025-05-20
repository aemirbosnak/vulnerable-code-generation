//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

void read_students(Student students[], int n) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%s %d %f", students[i].name, &students[i].age, &students[i].grade);
    }

    fclose(fp);
}

void write_students(Student students[], int n) {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s %d %f\n", students[i].name, students[i].age, students[i].grade);
    }

    fclose(fp);
}

void sort_students(Student students[], int n, int (*compare)(const void *, const void *)) {
    qsort(students, n, sizeof(Student), compare);
}

int compare_age(const void *a, const void *b) {
    const Student *student_a = a;
    const Student *student_b = b;

    return student_a->age - student_b->age;
}

int compare_grade(const void *a, const void *b) {
    const Student *student_a = a;
    const Student *student_b = b;

    return student_a->grade - student_b->grade;
}

int main() {
    Student students[100];
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    read_students(students, n);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %f\n", students[i].name, students[i].age, students[i].grade);
    }

    sort_students(students, n, compare_age);
    printf("\nSorted by age:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %f\n", students[i].name, students[i].age, students[i].grade);
    }

    sort_students(students, n, compare_grade);
    printf("\nSorted by grade:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %f\n", students[i].name, students[i].age, students[i].grade);
    }

    write_students(students, n);

    return 0;
}