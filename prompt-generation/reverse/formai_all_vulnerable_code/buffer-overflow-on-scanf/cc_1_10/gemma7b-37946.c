//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the maximum number of questions
#define MAX_QUESTIONS 20

// Define the maximum number of answers
#define MAX_ANSWERS 5

// Student structure
typedef struct Student {
    char name[20];
    int roll_no;
    float marks[MAX_QUESTIONS];
} Student;

// Question structure
typedef struct Question {
    char question[200];
    int marks;
    char answer[MAX_ANSWERS];
} Question;

// Function to read student data
void read_student_data(Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);

    printf("Enter student roll no: ");
    scanf("%d", &student->roll_no);

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter student marks for question %d: ", i + 1);
        scanf("%f", &student->marks[i]);
    }
}

// Function to read question data
void read_question_data(Question *question) {
    printf("Enter question: ");
    scanf("%s", question->question);

    printf("Enter marks for this question: ");
    scanf("%d", &question->marks);

    printf("Enter answer options: ");
    for (int i = 0; i < MAX_ANSWERS; i++) {
        scanf("%s", question->answer[i]);
    }
}

// Function to calculate student marks
float calculate_student_marks(Student *student) {
    float total_marks = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        total_marks += student->marks[i];
    }
    return total_marks;
}

// Function to generate student report
void generate_student_report(Student *student) {
    printf("Student Name: %s\n", student->name);
    printf("Roll No: %d\n", student->roll_no);
    printf("Marks: %.2f\n", calculate_student_marks(student));
}

int main() {
    Student students[MAX_STUDENTS];
    Question questions[MAX_QUESTIONS];

    // Read student data
    read_student_data(&students[0]);

    // Read question data
    read_question_data(&questions[0]);

    // Generate student report
    generate_student_report(&students[0]);

    return 0;
}