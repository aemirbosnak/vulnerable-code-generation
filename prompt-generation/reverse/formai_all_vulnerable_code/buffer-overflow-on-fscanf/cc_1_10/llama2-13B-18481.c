//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define some constants and variables
#define MAX_NAME_LENGTH 20
#define MAX_AGE 100
#define MIN_AGE 18
#define MAX_GPA 4.0
#define MIN_GPA 2.0
#define NUM_OF_STUDENTS 5

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    double gpa;
} student_t;

// Function to read student information from file
student_t read_student_info(FILE *file) {
    student_t student;

    // Read name
    fscanf(file, "%s", student.name);

    // Read age
    int age;
    fscanf(file, "%d", &age);
    student.age = age;

    // Read GPA
    double gpa;
    fscanf(file, "%lf", &gpa);
    student.gpa = gpa;

    return student;
}

// Function to write student information to file
void write_student_info(FILE *file, student_t student) {
    fprintf(file, "%s", student.name);
    fprintf(file, "%d", student.age);
    fprintf(file, "%lf", student.gpa);
}

// Function to print student information
void print_student_info(student_t student) {
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("GPA: %lf\n", student.gpa);
}

// Main function
int main() {
    // Open file in read mode
    FILE *file = fopen("students.txt", "r");

    // Check if file is open successfully
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read students from file
    student_t student1, student2, student3, student4, student5;
    student1 = read_student_info(file);
    student2 = read_student_info(file);
    student3 = read_student_info(file);
    student4 = read_student_info(file);
    student5 = read_student_info(file);

    // Print students
    print_student_info(student1);
    print_student_info(student2);
    print_student_info(student3);
    print_student_info(student4);
    print_student_info(student5);

    // Close file
    fclose(file);

    return 0;
}