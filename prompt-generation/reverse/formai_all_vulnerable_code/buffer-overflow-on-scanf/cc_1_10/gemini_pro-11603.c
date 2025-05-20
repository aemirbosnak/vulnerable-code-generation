//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[50];
    int roll_number;
    int marks[5];
    float average;
} student;

void get_student_details(student *s) {
    printf("Enter student name: ");
    scanf("%s", s->name);
    printf("Enter roll number: ");
    scanf("%d", &s->roll_number);
    for (int i = 0; i < 5; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &s->marks[i]);
    }
}

void calculate_average(student *s) {
    s->average = 0;
    for (int i = 0; i < 5; i++) {
        s->average += s->marks[i];
    }
    s->average /= 5;
}

void print_student_details(student *s) {
    printf("Student name: %s\n", s->name);
    printf("Roll number: %d\n", s->roll_number);
    printf("Marks: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", s->marks[i]);
    }
    printf("\n");
    printf("Average: %.2f\n", s->average);
}

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    student students[num_students];
    for (int i = 0; i < num_students; i++) {
        get_student_details(&students[i]);
        calculate_average(&students[i]);
    }
    for (int i = 0; i < num_students; i++) {
        print_student_details(&students[i]);
    }
    return 0;
}