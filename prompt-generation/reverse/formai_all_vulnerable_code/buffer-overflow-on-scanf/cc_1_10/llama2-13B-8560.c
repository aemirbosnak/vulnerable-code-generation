//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADE_VALUE 100

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int grade;
} student_t;

// Function to get student information
void get_student_info(student_t *student) {
    printf("What is your name? ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    printf("What is your grade? ");
    scanf("%d", &student->grade);
}

// Function to display student information
void display_student_info(student_t *student) {
    printf("Hello, %s! You have a grade of %d.\n", student->name, student->grade);
}

// Function to calculate and display the average grade
void calculate_average(student_t *students, int num_students) {
    int total_grade = 0;
    for (int i = 0; i < num_students; i++) {
        total_grade += students[i].grade;
    }
    float average = total_grade / num_students;
    printf("The average grade is %f.\n", average);
}

int main() {
    int num_students = 0;
    student_t students[10];

    // Get student information
    for (int i = 0; i < 10; i++) {
        get_student_info(&students[i]);
        num_students++;
    }

    // Display student information
    for (int i = 0; i < num_students; i++) {
        display_student_info(&students[i]);
    }

    // Calculate and display the average grade
    calculate_average(students, num_students);

    return 0;
}