//Falcon-180B DATASET v1.0 Category: Educational ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float gpa;
} Student;

void read_students(Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter the age of student %s: ", students[i].name);
        scanf("%d", &students[i].age);
        printf("Enter the GPA of student %s: ", students[i].name);
        scanf("%f", &students[i].gpa);
    }
}

void print_students(Student *students, int num_students) {
    printf("Name\tAge\tGPA\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s\t%d\t%.2f\n", students[i].name, students[i].age, students[i].gpa);
    }
}

void sort_students(Student *students, int num_students, int (*compare)(const void *, const void *)) {
    qsort(students, num_students, sizeof(Student), compare);
}

int compare_by_age(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    return s1->age - s2->age;
}

int compare_by_gpa(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    return s2->gpa - s1->gpa;
}

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    Student *students = malloc(num_students * sizeof(Student));

    if (students == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }

    read_students(students, num_students);

    printf("Before sorting:\n");
    print_students(students, num_students);

    printf("Sort by age:\n");
    sort_students(students, num_students, compare_by_age);
    print_students(students, num_students);

    printf("Sort by GPA:\n");
    sort_students(students, num_students, compare_by_gpa);
    print_students(students, num_students);

    free(students);
    return 0;
}