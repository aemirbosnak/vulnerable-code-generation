//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADE_LENGTH 5
#define MIN_GRADE 0
#define MAX_GRADE 100

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int grade[MAX_GRADE_LENGTH];
} student_t;

// Function to print a welcome message
void welcome(void) {
    printf("Welcome to the student grading system! \n");
}

// Function to print a farewell message
void farewell(void) {
    printf("Goodbye! \n");
}

// Function to get student information
void get_student_info(student_t *student) {
    printf("Enter your name: ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    printf("Enter your grade: ");
    scanf("%d", &student->grade[0]);
}

// Function to calculate and print the average grade
void calculate_average(student_t *student) {
    int i;
    int sum = 0;
    for (i = 0; i < MAX_GRADE_LENGTH; i++) {
        sum += student->grade[i];
    }
    printf("Your average grade is: %d\n", sum / MAX_GRADE_LENGTH);
}

// Function to check if the input grade is valid
int is_grade_valid(int grade) {
    if (grade < MIN_GRADE || grade > MAX_GRADE) {
        return 0;
    }
    return 1;
}

int main() {
    student_t student;
    welcome();
    get_student_info(&student);
    calculate_average(&student);
    farewell();
    return 0;
}