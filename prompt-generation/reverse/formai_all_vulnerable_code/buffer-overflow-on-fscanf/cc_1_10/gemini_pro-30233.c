//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_QUESTION_LENGTH 256
#define MAX_ANSWER_LENGTH 256

// Data structures
typedef struct Question {
    char question[MAX_QUESTION_LENGTH];
    char answers[MAX_ANSWERS][MAX_ANSWER_LENGTH];
    int correctAnswer;
} Question;

typedef struct Exam {
    char name[MAX_QUESTION_LENGTH];
    int numQuestions;
    Question questions[MAX_QUESTIONS];
} Exam;

// Function prototypes
void loadExam(Exam *exam);
void takeExam(Exam *exam);
int gradeExam(Exam *exam);

// Main function
int main() {
    // Create an exam
    Exam exam;

    // Load the exam from a file
    loadExam(&exam);

    // Take the exam
    takeExam(&exam);

    // Grade the exam
    int score = gradeExam(&exam);

    // Print the score
    printf("Your score is %d\n", score);

    return 0;
}

// Function to load an exam from a file
void loadExam(Exam *exam) {
    // Open the exam file
    FILE *file = fopen("exam.txt", "r");
    if (file == NULL) {
        printf("Error opening exam file\n");
        exit(1);
    }

    // Read the exam name
    fscanf(file, "%s", exam->name);

    // Read the number of questions
    fscanf(file, "%d", &exam->numQuestions);

    // Read each question
    for (int i = 0; i < exam->numQuestions; i++) {
        // Read the question text
        fscanf(file, "%s", exam->questions[i].question);

        // Read the answers
        for (int j = 0; j < MAX_ANSWERS; j++) {
            fscanf(file, "%s", exam->questions[i].answers[j]);
        }

        // Read the correct answer
        fscanf(file, "%d", &exam->questions[i].correctAnswer);
    }

    // Close the exam file
    fclose(file);
}

// Function to take an exam
void takeExam(Exam *exam) {
    // Loop through each question
    for (int i = 0; i < exam->numQuestions; i++) {
        // Print the question
        printf("%s\n", exam->questions[i].question);

        // Print the answers
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%d. %s\n", j + 1, exam->questions[i].answers[j]);
        }

        // Get the user's answer
        int answer;
        scanf("%d", &answer);

        // Check if the answer is correct
        if (answer == exam->questions[i].correctAnswer) {
            // Increment the score
            exam->questions[i].correctAnswer++;
        }
    }
}

// Function to grade an exam
int gradeExam(Exam *exam) {
    // Calculate the score
    int score = 0;
    for (int i = 0; i < exam->numQuestions; i++) {
        if (exam->questions[i].correctAnswer) {
            score++;
        }
    }

    // Return the score
    return score;
}