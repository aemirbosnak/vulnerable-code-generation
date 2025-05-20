//LLAMA2-13B DATASET v1.0 Category: Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LENGTH 256
#define MAX_GRADE_COUNT 10

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    double gpa;
} student_t;

// Function to read student information from file
student_t read_student_info(FILE *file) {
    student_t s;
    char line[1024];

    // Read name, age, and gpa from file
    fscanf(file, "%s %d %lf", line, &s.age, &s.gpa);

    // Return student information
    return s;
}

// Function to print student information
void print_student(student_t s) {
    printf("Name: %s, Age: %d, GPA: %lf\n", s.name, s.age, s.gpa);
}

// Function to calculate and print the average GPA of a group of students
void print_group_gpa(student_t *students, int num_students) {
    double total_gpa = 0;
    int i;

    // Calculate the total GPA
    for (i = 0; i < num_students; i++) {
        total_gpa += students[i].gpa;
    }

    // Print the average GPA
    printf("Average GPA: %lf\n", total_gpa / num_students);
}

int main() {
    // Open the student information file
    FILE *file = fopen("students.txt", "r");

    // Read the number of students from the file
    int num_students;
    fscanf(file, "%d", &num_students);

    // Allocate memory for the students array
    student_t *students = (student_t *)malloc(num_students * sizeof(student_t));

    // Read the students information from the file
    for (int i = 0; i < num_students; i++) {
        students[i] = read_student_info(file);
    }

    // Calculate and print the average GPA of the group
    print_group_gpa(students, num_students);

    // Free the memory
    free(students);

    return 0;
}