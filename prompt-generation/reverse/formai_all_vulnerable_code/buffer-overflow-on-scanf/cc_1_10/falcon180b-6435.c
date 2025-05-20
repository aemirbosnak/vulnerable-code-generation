//Falcon-180B DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    char name[20];
    int age;
    float grade;
} Student;

void error_handler(const char* message) {
    printf("Error: %s\n", message);
    exit(1);
}

void add_student(Student* students, int* num_students) {
    if (*num_students >= MAX_SIZE) {
        error_handler("Cannot add more students. Maximum limit reached.");
    }

    printf("Enter student name: ");
    scanf("%s", students[*num_students].name);

    printf("Enter student age: ");
    scanf("%d", &students[*num_students].age);

    printf("Enter student grade: ");
    scanf("%f", &students[*num_students].grade);

    (*num_students)++;
}

void display_students(Student* students, int num_students) {
    printf("\nStudents:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s (%d years old) - Grade: %.2f\n", students[i].name, students[i].age, students[i].grade);
    }
}

int main() {
    srand(time(0));

    Student students[MAX_SIZE];
    int num_students = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        add_student(students, &num_students);
    }

    display_students(students, num_students);

    return 0;
}