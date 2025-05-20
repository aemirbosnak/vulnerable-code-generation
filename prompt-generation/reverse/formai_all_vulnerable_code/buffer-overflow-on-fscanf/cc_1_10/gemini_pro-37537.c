//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 10
#define MAX_CHOICES 5

// Define the structure of a question
typedef struct {
    char question[100];
    char choices[MAX_CHOICES][100];
    char correct_answer;
} Question;

// Define the structure of an exam
typedef struct {
    Question questions[MAX_QUESTIONS];
    int num_questions;
} Exam;

// Function to load the questions from a file
bool load_questions(Exam *exam, char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return false;
    }

    // Read the number of questions
    fscanf(fp, "%d", &exam->num_questions);

    // Read the questions and choices
    for (int i = 0; i < exam->num_questions; i++) {
        // Read the question
        fgets(exam->questions[i].question, 100, fp);

        // Read the choices
        for (int j = 0; j < MAX_CHOICES; j++) {
            fgets(exam->questions[i].choices[j], 100, fp);
        }

        // Read the correct answer
        fscanf(fp, "%c", &exam->questions[i].correct_answer);
    }

    // Close the file
    fclose(fp);

    return true;
}

// Function to print the exam
void print_exam(Exam *exam) {
    // Print the instructions
    printf("Instructions:\n");
    printf("Answer all questions to the best of your ability.\n");
    printf("Enter your answer as a letter (A, B, C, D, or E).\n");

    // Print the questions
    for (int i = 0; i < exam->num_questions; i++) {
        // Print the question
        printf("%d. %s\n", i + 1, exam->questions[i].question);

        // Print the choices
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%c. %s\n", 'A' + j, exam->questions[i].choices[j]);
        }

        // Print a newline
        printf("\n");
    }
}

// Function to grade the exam
int grade_exam(Exam *exam, char *answers) {
    int score = 0;

    // Check each answer
    for (int i = 0; i < exam->num_questions; i++) {
        // Check if the answer is correct
        if (answers[i] == exam->questions[i].correct_answer) {
            // Increment the score
            score++;
        }
    }

    // Return the score
    return score;
}

// Main function
int main() {
    // Create an exam
    Exam exam;

    // Load the questions from a file
    if (!load_questions(&exam, "questions.txt")) {
        printf("Error loading questions.\n");
        return 1;
    }

    // Print the exam
    print_exam(&exam);

    // Get the answers from the user
    char answers[MAX_QUESTIONS];
    printf("Enter your answers: ");
    scanf("%s", answers);

    // Grade the exam
    int score = grade_exam(&exam, answers);

    // Print the score
    printf("Your score is: %d\n", score);

    return 0;
}