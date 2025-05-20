//FormAI DATASET v1.0 Category: Online Examination System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining constants for exam details
#define NUM_QUESTIONS 10
#define MAX_QUESTIONS_PER_EXAM 5
#define PASSING_GRADE 60

// User-defined type for Exam Question
typedef struct ExamQuestion {
    int id;
    char question[100];
    char options[4][50];
    int answer;
} ExamQuestion;

// User-defined type for Exam
typedef struct Exam {
    int id;
    char name[50];
    ExamQuestion questions[MAX_QUESTIONS_PER_EXAM];
} Exam;

// User-defined type for Student
typedef struct Student {
    int id;
    char name[50];
    int grade;
} Student;

// Function prototypes
void displayExam(Exam exam);
int gradeExam(Exam exam, int *studentAnswers);
void displayResult(Student student);

int main() {
    // Declare and initialize variables
    int numExams = 2;
    Exam exams[numExams];

    // Exam 1
    exams[0].id = 1;
    strcpy(exams[0].name, "C Programming Exam");
    ExamQuestion q1 = {1, "What is the data type of the following variable declaration: float x;", {"a. Integer", "b. Float", "c. Char", "d. Double"}, 2};
    ExamQuestion q2 = {2, "What is the output of the following code: printf(\"%%d\\n\", 5/2);", {"a. 2", "b. 2.5", "c. 3", "d. None of the above"}, 3};
    ExamQuestion q3 = {3, "Which keyword is used to exit a loop in C programming?", {"a. exit", "b. return", "c. goto", "d. break"}, 4};
    ExamQuestion q4 = {4, "What is the return type of the main() function?", {"a. int", "b. void", "c. char", "d. float"}, 1};
    ExamQuestion q5 = {5, "Which operator is used to access the value stored in a pointer variable?", {"a. &", "b. *", "c. %", "d. #"}, 2};
    exams[0].questions[0] = q1;
    exams[0].questions[1] = q2;
    exams[0].questions[2] = q3;
    exams[0].questions[3] = q4;
    exams[0].questions[4] = q5;

    // Exam 2
    exams[1].id = 2;
    strcpy(exams[1].name, "Data Structures Exam");
    ExamQuestion q6 = {1, "What is the time complexity of binary search?", {"a. O(log n)", "b. O(n)", "c. O(n^2)", "d. O(1)"}, 1};
    ExamQuestion q7 = {2, "Which data structure is used for implementing recursion?", {"a. Queue", "b. Array", "c. Stack", "d. Linked List"}, 3};
    ExamQuestion q8 = {3, "Which sorting algorithm is best for large-sized arrays?", {"a. Selection Sort", "b. Bubble Sort", "c. Insertion Sort", "d. Merge Sort"}, 4};
    ExamQuestion q9 = {4, "What is the maximum number of nodes at level 'k' in a binary tree?", {"a. pow(2, k-1)", "b. pow(2, k)", "c. pow(2, k+1)-1", "d. pow(2, 2k-1)"}, 1};
    ExamQuestion q10 = {5, "Which data structure is used for implementing BFS and DFS algorithms?", {"a. Stack", "b. Linked List", "c. Queue", "d. Tree"}, 3};
    exams[1].questions[0] = q6;
    exams[1].questions[1] = q7;
    exams[1].questions[2] = q8;
    exams[1].questions[3] = q9;
    exams[1].questions[4] = q10;

    // Display exam details and take input from student
    int examChoice;
    printf("Choose the Exam:\n");
    for (int i = 0; i < numExams; i++) {
        printf("%d: %s\n", exams[i].id, exams[i].name);
    }
    scanf("%d", &examChoice);
    Exam selectedExam = exams[examChoice-1];
    int studentAnswers[MAX_QUESTIONS_PER_EXAM];
    for (int i = 0; i < MAX_QUESTIONS_PER_EXAM; i++) {
        displayExam(selectedExam);
        printf("\nChoose the correct answer (1-4) for Question %d: ", i+1);
        scanf("%d", &studentAnswers[i]);
    }

    // Grade exam and display result
    int grade = gradeExam(selectedExam, studentAnswers);
    Student student;
    student.grade = grade;
    printf("\nEnter your Name: ");
    scanf("%s", student.name);
    printf("Enter your Student ID: ");
    scanf("%d", &student.id);
    displayResult(student);

    return 0;
}

// Function to display exam details
void displayExam(Exam exam) {
    printf("\n%s\n", exam.name);
    for (int i = 0; i < MAX_QUESTIONS_PER_EXAM; i++) {
        printf("%d. %s\n", exam.questions[i].id, exam.questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\t", exam.questions[i].options[j]);
        }
        printf("\n");
    }
}

// Function to grade the exam
int gradeExam(Exam exam, int *studentAnswers) {
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS_PER_EXAM; i++) {
        if (studentAnswers[i] == exam.questions[i].answer) {
            score += 10;
        }
    }
    return score;
}

// Function to display student's result
void displayResult(Student student) {
    printf("\nStudent Name: %s\n", student.name);
    printf("Student ID: %d\n", student.id);
    printf("Grade: %d\n", student.grade);
    if (student.grade >= PASSING_GRADE) {
        printf("Congratulations, you have passed the exam!\n");
    } else {
        printf("Sorry, you have failed the exam. Please try again.\n");
    }
}