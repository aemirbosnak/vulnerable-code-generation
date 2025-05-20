//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the maximum number of exams
#define MAX_EXAMS 20

// Define the student structure
typedef struct Student {
    char name[20];
    int roll_no;
    float marks[MAX_EXAMS];
} Student;

// Define the exam structure
typedef struct Exam {
    char subject_name[20];
    int marks_obtained;
} Exam;

// Function to read student data
void read_student_data(Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);

    printf("Enter student roll no: ");
    scanf("%d", &student->roll_no);

    for (int i = 0; i < MAX_EXAMS; i++) {
        printf("Enter marks for exam %d: ", i + 1);
        scanf("%f", &student->marks[i]);
    }
}

// Function to read exam data
void read_exam_data(Exam *exam) {
    printf("Enter exam subject name: ");
    scanf("%s", exam->subject_name);

    printf("Enter marks obtained: ");
    scanf("%d", &exam->marks_obtained);
}

// Function to calculate student average marks
float calculate_student_average(Student *student) {
    float total_marks = 0.0f;
    for (int i = 0; i < MAX_EXAMS; i++) {
        total_marks += student->marks[i];
    }
    return total_marks / MAX_EXAMS;
}

// Function to calculate exam average marks
float calculate_exam_average(Exam *exam) {
    return exam->marks_obtained;
}

// Main function
int main() {

    // Create an array of students
    Student students[MAX_STUDENTS];

    // Create an array of exams
    Exam exams[MAX_EXAMS];

    // Read student data
    read_student_data(&students[0]);

    // Read exam data
    read_exam_data(&exams[0]);

    // Calculate student average marks
    float student_average_marks = calculate_student_average(&students[0]);

    // Calculate exam average marks
    float exam_average_marks = calculate_exam_average(&exams[0]);

    // Print student average marks
    printf("Student average marks: %.2f", student_average_marks);

    // Print exam average marks
    printf("Exam average marks: %.2f", exam_average_marks);

    return 0;
}