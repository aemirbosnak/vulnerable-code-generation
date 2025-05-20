//Falcon-180B DATASET v1.0 Category: Database querying ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

void read_students(Student students[], int n) {
    FILE *fp = fopen("students.txt", "r");
    int i = 0;

    while (i < n && fscanf(fp, "%s %d %f\n", students[i].name, &students[i].age, &students[i].gpa)!= EOF) {
        i++;
    }

    fclose(fp);
}

void sort_students_by_age(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].age > students[j].age) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void sort_students_by_gpa(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].gpa < students[j].gpa) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void print_students(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d %f\n", students[i].name, students[i].age, students[i].gpa);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int n = 0;

    read_students(students, MAX_STUDENTS);
    n = fscanf(stdin, "%d", &n);

    if (n > 0 && n <= MAX_STUDENTS) {
        sort_students_by_age(students, n);
        printf("Sorted by age:\n");
        print_students(students, n);

        sort_students_by_gpa(students, n);
        printf("\nSorted by GPA:\n");
        print_students(students, n);
    } else {
        printf("Invalid number of students.\n");
    }

    return 0;
}