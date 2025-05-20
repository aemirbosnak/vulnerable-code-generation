//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to read student information from file
student_t read_student_info(FILE *file) {
    student_t student;

    // Read name
    fscanf(file, "%s", student.name);

    // Read age
    int age;
    fscanf(file, "%d", &age);
    student.age = age;

    // Read grade
    int grade;
    fscanf(file, "%d", &grade);
    student.grade = grade;

    return student;
}

// Function to write student information to file
void write_student_info(FILE *file, student_t student) {
    fprintf(file, "%s", student.name);
    fprintf(file, "%d", student.age);
    fprintf(file, "%d", student.grade);
}

int main() {
    // Open file in read/write mode
    FILE *file = fopen("students.txt", "r+");

    // Check if file open successfully
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Read student information from file
    student_t student = read_student_info(file);

    // Print student information
    printf("Name: %s\nAge: %d\nGrade: %d\n", student.name, student.age, student.grade);

    // Modify student information
    student.age += 5;
    student.grade++;

    // Write modified student information to file
    write_student_info(file, student);

    // Close file
    fclose(file);

    return 0;
}