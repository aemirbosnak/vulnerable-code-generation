//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the maximum number of questions
#define MAX_QUESTIONS 20

// Student structure
typedef struct Student {
    char name[50];
    int rollNo;
    float marks[MAX_QUESTIONS];
    struct Student* next;
} Student;

// Question structure
typedef struct Question {
    char question[255];
    int marks;
    struct Question* next;
} Question;

// Function to insert a student at the end
void insertStudent(Student** head) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    printf("Enter student name: ");
    scanf("%s", newStudent->name);
    printf("Enter student roll number: ");
    scanf("%d", &newStudent->rollNo);

    if (*head == NULL) {
        *head = newStudent;
    } else {
        (*head)->next = newStudent;
    }
    *head = newStudent;
}

// Function to insert a question at the end
void insertQuestion(Question** head) {
    Question* newQuestion = (Question*)malloc(sizeof(Question));
    printf("Enter question: ");
    scanf("%s", newQuestion->question);
    printf("Enter marks for the question: ");
    scanf("%d", &newQuestion->marks);

    if (*head == NULL) {
        *head = newQuestion;
    } else {
        (*head)->next = newQuestion;
    }
    *head = newQuestion;
}

// Function to calculate the total marks of a student
float calculateTotalMarks(Student* student) {
    float totalMarks = 0.0f;
    Question* question = student->marks;

    while (question) {
        totalMarks += question->marks;
        question = question->next;
    }

    return totalMarks;
}

// Function to display the student marks
void displayStudentMarks(Student* student) {
    printf("Student Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNo);
    printf("Total Marks: %.2f\n", calculateTotalMarks(student));

    Question* question = student->marks;

    printf("Questions:\n");
    while (question) {
        printf("Question: %s\n", question->question);
        printf("Marks: %d\n", question->marks);
        question = question->next;
    }
}

int main() {
    Student* headStudent = NULL;
    Question* headQuestion = NULL;

    // Insert some students
    insertStudent(&headStudent);
    insertStudent(&headStudent);
    insertStudent(&headStudent);

    // Insert some questions
    insertQuestion(&headQuestion);
    insertQuestion(&headQuestion);
    insertQuestion(&headQuestion);

    // Display student marks
    displayStudentMarks(headStudent);

    return 0;
}