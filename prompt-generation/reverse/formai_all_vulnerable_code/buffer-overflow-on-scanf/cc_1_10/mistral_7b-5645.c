//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int roll_number;
    float gpa;
} Student;

int main() {
    Student students[MAX_STUDENTS];
    int num_students, i;

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    printf("\nStudent Data Entry:\n");

    for (i = 0; i < num_students; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].roll_number);
        printf("Enter GPA: ");
        scanf("%f", &students[i].gpa);
    }

    printf("\nStudent Data Display:\n");

    for (i = 0; i < num_students; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].roll_number);
        printf("GPA: %.2f\n", students[i].gpa);
    }

    float total_gpa = 0.0;

    for (i = 0; i < num_students; i++) {
        total_gpa += students[i].gpa;
    }

    float avg_gpa = total_gpa / num_students;

    printf("\nAverage GPA: %.2f", avg_gpa);

    return 0;
}