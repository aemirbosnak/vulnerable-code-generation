//LLAMA2-13B DATASET v1.0 Category: Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADE_VALUE 100

// Structure to hold student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int grade;
} student_t;

// Function to read student information from the user
void read_student_info(student_t *student) {
    printf("Enter your name: ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    student->name[strcspn(student->name, "\n")] = 0; // trim the newline character

    printf("Enter your grade: ");
    scanf("%d", &student->grade);
}

// Function to print the student information
void print_student_info(student_t student) {
    printf("Name: %s\nGrade: %d\n", student.name, student.grade);
}

int main() {
    student_t student;

    // Read student information from the user
    read_student_info(&student);

    // Print the student information
    print_student_info(student);

    // Get the student's grade average
    float grade_average = student.grade / 10.0;

    // Print the student's grade average
    printf("Grade Average: %f\n", grade_average);

    // Get the student's rank based on their grade average
    int rank = (int) (grade_average * 100 / MAX_GRADE_VALUE) + 1;

    // Print the student's rank
    printf("Rank: %d\n", rank);

    return 0;
}