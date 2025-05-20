//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LENGTH 25
#define MAX_GRADES 5

// Structure to hold student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    double gpa;
} student_t;

// Function to read student information from the user
void read_student_info(student_t *student) {
    printf("Enter your name: ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    printf("Enter your age: ");
    scanf("%d", &student->age);
    printf("Enter your GPA (out of 100): ");
    scanf("%lf", &student->gpa);
}

// Function to calculate the average GPA
double calculate_average(student_t *students, int num_students) {
    double total_gpa = 0;
    for (int i = 0; i < num_students; i++) {
        total_gpa += students[i].gpa;
    }
    return total_gpa / num_students;
}

// Function to print the student information
void print_student_info(student_t *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("%s (%d) - GPA: %lf\n", students[i].name, students[i].age, students[i].gpa);
    }
}

int main() {
    // Create an array to store the student information
    student_t students[MAX_GRADES];

    // Read the student information
    for (int i = 0; i < MAX_GRADES; i++) {
        read_student_info(&students[i]);
    }

    // Calculate the average GPA
    double average_gpa = calculate_average(students, MAX_GRADES);

    // Print the student information and the average GPA
    print_student_info(students, MAX_GRADES);
    printf("Average GPA: %lf\n", average_gpa);

    return 0;
}