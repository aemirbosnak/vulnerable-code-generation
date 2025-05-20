//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: automated
/*
 * Unique C Online Examination System Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store exam details
struct exam {
    char name[50];
    int questions;
    int marks;
    int time;
};

// Structure to store student details
struct student {
    char name[50];
    int roll_no;
    int marks;
};

// Function to get exam details
void get_exam_details(struct exam *exam) {
    printf("Enter the name of the exam: ");
    scanf("%s", exam->name);
    printf("Enter the number of questions: ");
    scanf("%d", &exam->questions);
    printf("Enter the marks for each question: ");
    scanf("%d", &exam->marks);
    printf("Enter the time limit for the exam: ");
    scanf("%d", &exam->time);
}

// Function to get student details
void get_student_details(struct student *student) {
    printf("Enter the name of the student: ");
    scanf("%s", student->name);
    printf("Enter the roll number of the student: ");
    scanf("%d", &student->roll_no);
}

// Function to calculate the marks of a student
int calculate_marks(int questions, int marks, int time) {
    int total_marks = questions * marks;
    int bonus_marks = (time / 60) * 5;
    return total_marks + bonus_marks;
}

// Function to display the exam results
void display_results(struct student student, struct exam exam) {
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.roll_no);
    printf("Total Marks: %d\n", calculate_marks(exam.questions, exam.marks, exam.time));
}

int main() {
    struct exam exam;
    get_exam_details(&exam);

    struct student student;
    get_student_details(&student);

    display_results(student, exam);

    return 0;
}