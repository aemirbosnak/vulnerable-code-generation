//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define some constants and variables
#define MAX_NAME_LENGTH 20
#define MAX_AGE 100
#define MIN_AGE 18
#define MAX_GRADES 10

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int grade;
} student_t;

// Function to read student information from a file
student_t read_student_info(FILE *file) {
    student_t student;

    // Read name
    fscanf(file, "%s", student.name);

    // Read age
    fscanf(file, "%d", &student.age);

    // Read grade
    fscanf(file, "%d", &student.grade);

    return student;
}

// Function to write student information to a file
void write_student_info(student_t student, FILE *file) {
    fprintf(file, "%s", student.name);
    fprintf(file, "%d", student.age);
    fprintf(file, "%d", student.grade);
}

// Function to print student information
void print_student_info(student_t student) {
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Grade: %d\n", student.grade);
}

int main() {
    // Open the student information file in read and write mode
    FILE *file = fopen("student_info.txt", "r+");

    // Check if the file is valid
    if (file == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    // Read the student information from the file
    student_t student;
    student = read_student_info(file);

    // Print the student information
    print_student_info(student);

    // Update the student information
    student.age = 25;
    student.grade = 9;

    // Write the updated student information to the file
    write_student_info(student, file);

    // Close the file
    fclose(file);

    return 0;
}