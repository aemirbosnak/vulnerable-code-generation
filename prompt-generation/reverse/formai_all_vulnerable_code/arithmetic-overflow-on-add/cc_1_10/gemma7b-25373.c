//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the maximum number of exams
#define MAX_EXAMS 20

// Define the maximum number of marks
#define MAX_MARKS 100

// Create a structure to store student data
typedef struct student {
    char name[50];
    int roll_no;
    float marks[MAX_EXAMS];
} student;

// Create a structure to store exam data
typedef struct exam {
    char title[50];
    int marks[MAX_STUDENTS];
} exam;

// Function to compare two strings
int compare_strings(char *str1, char *str2) {
    return strcmp(str1, str2);
}

// Function to calculate the average marks of a student
float calculate_average_marks(student *student) {
    int total_marks = 0;
    for (int i = 0; i < MAX_EXAMS; i++) {
        total_marks += student->marks[i];
    }
    return (float)total_marks / MAX_EXAMS;
}

// Function to print the student details
void print_student_details(student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll No: %d\n", student->roll_no);
    printf("Average Marks: %.2f\n", calculate_average_marks(student));
}

int main() {
    // Create an array of students
    student students[MAX_STUDENTS];

    // Create an array of exams
    exam exams[MAX_EXAMS];

    // Populate the student and exam data
    // (This code will vary depending on the specific requirements of the system)

    // Print the student details
    for (int i = 0; i < MAX_STUDENTS; i++) {
        print_student_details(&students[i]);
    }

    return 0;
}