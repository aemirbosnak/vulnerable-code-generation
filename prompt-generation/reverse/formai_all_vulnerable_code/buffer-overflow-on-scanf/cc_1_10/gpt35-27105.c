//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_NUM_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LEN];  // student name
    int age;  // student age
    float gpa;  // student GPA
} Student;

int main() {
    // allocate memory for the student array
    Student* students = malloc(MAX_NUM_STUDENTS * sizeof(Student));
    if (students == NULL) {
        printf("Error: failed to allocate memory for students\n");
        return 1;
    }

    // read in the number of students
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // read in the student data
    printf("Enter the student data (name age gpa), one per line:\n");
    for (int i = 0; i < num_students; i++) {
        char name[MAX_NAME_LEN];
        int age;
        float gpa;
        scanf("%s %d %f", name, &age, &gpa);
        if (strlen(name) > MAX_NAME_LEN - 1) {
            printf("Error: student name is too long\n");
            return 1;
        }
        strncpy(students[i].name, name, MAX_NAME_LEN - 1);
        students[i].age = age;
        students[i].gpa = gpa;
    }

    // calculate the average GPA
    float avg_gpa = 0.0;
    for (int i = 0; i < num_students; i++) {
        avg_gpa += students[i].gpa;
    }
    avg_gpa /= num_students;

    // print out the student data
    printf("Students with GPA above the average (%.2f):\n", avg_gpa);
    for (int i = 0; i < num_students; i++) {
        if (students[i].gpa > avg_gpa) {
            printf("%s %d %.2f\n", students[i].name, students[i].age, students[i].gpa);
        }
    }

    // free the memory for the student array
    free(students);

    return 0;
}