//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and choices per question
#define MAX_QUESTIONS 100
#define MAX_CHOICES 5

// Define the structure of a question
typedef struct {
    char question[256];
    char choices[MAX_CHOICES][256];
    int correct_answer;
} Question;

// Define the structure of an exam
typedef struct {
    int num_questions;
    Question questions[MAX_QUESTIONS];
} Exam;

// Read an exam from a file
Exam read_exam(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    Exam exam;
    fscanf(file, "%d", &exam.num_questions);

    for (int i = 0; i < exam.num_questions; i++) {
        fscanf(file, "%s\n", exam.questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            fscanf(file, "%s\n", exam.questions[i].choices[j]);
        }
        fscanf(file, "%d", &exam.questions[i].correct_answer);
    }

    fclose(file);
    return exam;
}

// Print the exam to the console
void print_exam(Exam exam) {
    printf("Exam:\n");
    for (int i = 0; i < exam.num_questions; i++) {
        printf("Question %d:\n", i + 1);
        printf("  %s\n", exam.questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("  %d. %s\n", j + 1, exam.questions[i].choices[j]);
        }
    }
}

// Grade the exam
int grade_exam(Exam exam, int *answers) {
    int score = 0;
    for (int i = 0; i < exam.num_questions; i++) {
        if (answers[i] == exam.questions[i].correct_answer) {
            score++;
        }
    }
    return score;
}

// Main function
int main() {
    // Read the exam from a file
    Exam exam = read_exam("exam.txt");

    // Print the exam to the console
    print_exam(exam);

    // Get the answers from the user
    int answers[MAX_QUESTIONS];
    for (int i = 0; i < exam.num_questions; i++) {
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%d", &answers[i]);
    }

    // Grade the exam
    int score = grade_exam(exam, answers);

    // Print the score
    printf("Your score is %d out of %d\n", score, exam.num_questions);

    return 0;
}