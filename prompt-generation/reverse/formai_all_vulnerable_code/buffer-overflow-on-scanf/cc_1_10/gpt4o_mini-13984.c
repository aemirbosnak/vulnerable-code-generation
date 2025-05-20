//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold question details
typedef struct {
    int id;
    char question[256];
    char options[4][100];
    char answer;
} Question;

// Structure to hold student details
typedef struct {
    char name[50];
    char roll_no[10];
    int score;
} Student;

// Function prototypes
void displayInstructions();
void displayQuestions(Question *q, int totalQuestions);
void calculateScore(Student *student, Question *q, int totalQuestions);
void displayResult(Student *student);

int main() {
    int totalQuestions = 5;
    Question questions[5] = {
        {1, "What is the capital of France?", {"A) Berlin", "B) Paris", "C) Madrid", "D) Rome"}, 'B'},
        {2, "Which planet is known as the Red Planet?", {"A) Earth", "B) Mars", "C) Venus", "D) Jupiter"}, 'B'},
        {3, "What is the tallest mountain in the world?", {"A) K2", "B) Kangchenjunga", "C) Everest", "D) Lhotse"}, 'C'},
        {4, "Who wrote 'Hamlet'?", {"A) Mark Twain", "B) Charles Dickens", "C) William Shakespeare", "D) J.K. Rowling"}, 'C'},
        {5, "What is the speed of light?", {"A) 300,000 km/s", "B) 150,000 km/s", "C) 450,000 km/s", "D) 600,000 km/s"}, 'A'}
    };

    Student student;
    student.score = 0;

    printf("Welcome to the Retro Online Examination System!\n");
    printf("===============================================\n");
    printf("Please enter your name: ");
    fgets(student.name, sizeof(student.name), stdin);
    strtok(student.name, "\n"); // Remove newline character
    printf("Please enter your roll number: ");
    fgets(student.roll_no, sizeof(student.roll_no), stdin);
    strtok(student.roll_no, "\n"); // Remove newline character
    
    displayInstructions();
    displayQuestions(questions, totalQuestions);
    
    calculateScore(&student, questions, totalQuestions);
    displayResult(&student);

    return 0;
}

void displayInstructions() {
    printf("\nInstructions:\n");
    printf("1. Answer the following multiple choice questions by selecting A, B, C, or D.\n");
    printf("2. Each correct answer earns you 1 point.\n");
    printf("3. You will see your score at the end of the exam!\n\n");
}

void displayQuestions(Question *q, int totalQuestions) {
    char answer;
    printf("\nStarting the examination...\n");
    for (int i = 0; i < totalQuestions; i++) {
        printf("Q%d: %s\n", q[i].id, q[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", q[i].options[j]);
        }
        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &answer);
        
        // Convert to uppercase to simplify case sensitivity
        answer = toupper(answer);
        if (answer == q[i].answer) {
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer is %c)\n", q[i].answer);
        }
    }
}

void calculateScore(Student *student, Question *q, int totalQuestions) {
    char answer;
    for (int i = 0; i < totalQuestions; i++) {
        printf("Q%d: %s\n", q[i].id, q[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", q[i].options[j]);
        }
        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &answer);
        answer = toupper(answer);

        if (answer == q[i].answer) {
            student->score++;
        }
    }
}

void displayResult(Student *student) {
    printf("\nThank you for participating, %s (%s)!\n", student->name, student->roll_no);
    printf("Your score: %d/5\n", student->score);
    
    // Grading comment
    if (student->score == 5) {
        printf("Outstanding performance!\n");
    } else if (student->score >= 3) {
        printf("Well done!\n");
    } else {
        printf("Better luck next time!\n");
    }
}