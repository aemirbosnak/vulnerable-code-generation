//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADES 5

// Structure to hold student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int ages;
    double gpa;
} student_t;

// Function to get student information
void get_student_info(student_t *student) {
    printf("Enter your name: ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    printf("Enter your age: ");
    scanf("%d", &student->ages);
    printf("Enter your GPA (out of 10.0): ");
    scanf("%lf", &student->gpa);
}

// Function to print student information
void print_student_info(student_t student) {
    printf("Student Information:\n");
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.ages);
    printf("GPA: %lf\n", student.gpa);
}

int main() {
    // Create an array of student structures
    student_t students[5];

    // Initialize the array with default values
    for (int i = 0; i < 5; i++) {
        students[i].name[0] = '\0';
        students[i].ages = 0;
        students[i].gpa = 0.0;
    }

    // Get student information for the first four students
    for (int i = 0; i < 4; i++) {
        get_student_info(&students[i]);
    }

    // Calculate and print the average GPA
    double average_gpa = 0.0;
    for (int i = 0; i < 4; i++) {
        average_gpa += students[i].gpa;
    }
    average_gpa /= 4.0;
    printf("Average GPA: %lf\n", average_gpa);

    // Print the student information for the first four students
    for (int i = 0; i < 4; i++) {
        print_student_info(students[i]);
    }

    // Get student information for the last student
    get_student_info(&students[4]);

    // Print a message if the last student's GPA is above 3.5
    if (students[4].gpa > 3.5) {
        printf("Congratulations, you have a high GPA!\n");
    }

    return 0;
}