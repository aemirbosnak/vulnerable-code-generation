//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the maximum number of questions
#define MAX_QUESTIONS 20

// Define the maximum number of answers for each question
#define MAX_ANSWERS 5

// Define the student structure
typedef struct Student {
    char name[20];
    int roll_no;
    float marks[MAX_QUESTIONS];
} Student;

// Define the question structure
typedef struct Question {
    char question[200];
    int marks;
    char answers[MAX_ANSWERS];
} Question;

// Function to read student data
Student read_student(int i) {
    Student student;
    printf("Enter the name of student %d: ", i);
    scanf("%s", student.name);
    printf("Enter the roll number of student %d: ", i);
    scanf("%d", &student.roll_no);
    return student;
}

// Function to read question data
Question read_question(int i) {
    Question question;
    printf("Enter the question for question %d: ", i);
    scanf("%s", question.question);
    printf("Enter the marks for question %d: ", i);
    scanf("%d", &question.marks);
    printf("Enter the answers for question %d: ", i);
    scanf("%s", question.answers);
    return question;
}

// Function to calculate student marks
float calculate_marks(Student student, Question question) {
    int i;
    float total_marks = 0;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        total_marks += student.marks[i] * question.marks;
    }
    return total_marks;
}

// Function to print student marks
void print_marks(Student student) {
    int i;
    printf("Student name: %s\n", student.name);
    printf("Roll number: %d\n", student.roll_no);
    printf("Marks: \n");
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %f\n", i + 1, student.marks[i]);
    }
    printf("Total marks: %f\n", calculate_marks(student, read_question(0)));
}

int main() {
    Student students[MAX_STUDENTS];
    Question questions[MAX_QUESTIONS];

    // Read student data
    for (int i = 0; i < MAX_STUDENTS; i++) {
        students[i] = read_student(i + 1);
    }

    // Read question data
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        questions[i] = read_question(i + 1);
    }

    // Calculate student marks
    for (int i = 0; i < MAX_STUDENTS; i++) {
        print_marks(students[i]);
    }

    return 0;
}