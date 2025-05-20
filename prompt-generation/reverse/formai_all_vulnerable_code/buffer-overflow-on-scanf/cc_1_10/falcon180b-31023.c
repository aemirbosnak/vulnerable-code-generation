//Falcon-180B DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    double gpa;
} Student;

void read_students(Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", students[i].name);
        printf("Enter the age of student %s: ", students[i].name);
        scanf("%d", &students[i].age);
        printf("Enter the GPA of student %s: ", students[i].name);
        scanf("%lf", &students[i].gpa);
    }
}

void print_students(Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2lf\n\n", students[i].gpa);
    }
}

void sort_students(Student* students, int num_students) {
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (students[i].gpa < students[j].gpa) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    Student* students = (Student*) malloc(num_students * sizeof(Student));
    read_students(students, num_students);
    sort_students(students, num_students);
    print_students(students, num_students);

    free(students);
    return 0;
}