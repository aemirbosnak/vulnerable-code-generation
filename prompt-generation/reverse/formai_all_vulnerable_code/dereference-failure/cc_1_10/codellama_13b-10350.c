//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
// Don Knuth style C Examination System
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int num_questions;
int num_students;
int *answers;

// Function declarations
void initialize();
void generate_questions();
void display_questions();
void take_answers();
void evaluate_answers();
void display_results();

int main() {
    initialize();
    generate_questions();
    display_questions();
    take_answers();
    evaluate_answers();
    display_results();
    return 0;
}

void initialize() {
    // Initialize global variables
    num_questions = 10;
    num_students = 20;
    answers = (int *)malloc(num_questions * num_students * sizeof(int));
}

void generate_questions() {
    // Generate questions
    srand(time(NULL));
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: ", i + 1);
        for (int j = 0; j < num_students; j++) {
            answers[i * num_students + j] = rand() % 4 + 1;
        }
    }
}

void display_questions() {
    // Display questions
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: ", i + 1);
        for (int j = 0; j < num_students; j++) {
            printf("%d ", answers[i * num_students + j]);
        }
        printf("\n");
    }
}

void take_answers() {
    // Take answers from students
    for (int i = 0; i < num_questions; i++) {
        printf("Enter answers for question %d: ", i + 1);
        for (int j = 0; j < num_students; j++) {
            scanf("%d", &answers[i * num_students + j]);
        }
    }
}

void evaluate_answers() {
    // Evaluate answers
    for (int i = 0; i < num_questions; i++) {
        int correct_answers = 0;
        for (int j = 0; j < num_students; j++) {
            if (answers[i * num_students + j] == answers[i]) {
                correct_answers++;
            }
        }
        printf("Question %d: %d out of %d correct\n", i + 1, correct_answers, num_students);
    }
}

void display_results() {
    // Display results
    printf("Exam Results:\n");
    for (int i = 0; i < num_students; i++) {
        int correct_answers = 0;
        for (int j = 0; j < num_questions; j++) {
            if (answers[j * num_students + i] == answers[j]) {
                correct_answers++;
            }
        }
        printf("Student %d: %d out of %d correct\n", i + 1, correct_answers, num_questions);
    }
}