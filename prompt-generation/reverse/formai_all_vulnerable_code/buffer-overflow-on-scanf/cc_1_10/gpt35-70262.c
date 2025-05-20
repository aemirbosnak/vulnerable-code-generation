//FormAI DATASET v1.0 Category: Data mining ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct student {
    char name[50];
    int grade;
};

int main() {

    int num_students;
    struct student *students;

    // Input number of students
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Allocate memory for students
    students = (struct student*) malloc(num_students * sizeof(struct student));

    // Input student information
    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d:\n", i+1);
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter grade: ");
        scanf("%d", &students[i].grade);
    }

    // Determine average grade
    int total_grade = 0;
    for (int i = 0; i < num_students; i++) {
        total_grade += students[i].grade;
    }
    float avg_grade = (float) total_grade / num_students;

    // Determine students above average grade
    printf("\nStudents above average grade:\n");
    for (int i = 0; i < num_students; i++) {
        if (students[i].grade > avg_grade) {
            printf("%s\n", students[i].name);
        }
    }

    // Deallocate memory
    free(students);

    return 0;
}