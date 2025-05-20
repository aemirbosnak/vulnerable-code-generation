//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the maximum number of questions
#define MAX_QUESTIONS 20

// Define the maximum number of attempts for each question
#define MAX_ATTEMPTS 3

// Structure to store student data
typedef struct Student {
    char name[20];
    int roll_no;
    float marks[MAX_QUESTIONS];
} Student;

// Function to generate random numbers
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to read student data
void read_student_data(Student *student) {
    printf("Enter your name: ");
    scanf("%s", student->name);

    printf("Enter your roll number: ");
    scanf("%d", &student->roll_no);

    student->marks[0] = generate_random_number(0, 100);
    student->marks[1] = generate_random_number(0, 100);
    student->marks[2] = generate_random_number(0, 100);
}

// Function to calculate student marks
float calculate_student_marks(Student *student) {
    int i;
    float total_marks = 0;

    for (i = 0; i < MAX_QUESTIONS; i++) {
        total_marks += student->marks[i];
    }

    return total_marks / MAX_QUESTIONS;
}

// Function to display student marks
void display_student_marks(Student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->roll_no);
    printf("Marks:\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %f\n", i + 1, student->marks[i]);
    }

    printf("Total Marks: %f\n", calculate_student_marks(student));
}

int main() {
    // Create an array of students
    Student students[MAX_STUDENTS];

    // Read student data
    read_student_data(students);

    // Display student marks
    display_student_marks(students);

    return 0;
}