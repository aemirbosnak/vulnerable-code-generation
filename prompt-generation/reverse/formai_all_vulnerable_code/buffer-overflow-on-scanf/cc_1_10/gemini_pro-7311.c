//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 10
#define MAX_CHOICES 4

// Define the structure of a question
typedef struct {
    char question[100];
    char choices[MAX_CHOICES][100];
    int correct_answer;
} Question;

// Define the structure of an examination
typedef struct {
    Question questions[MAX_QUESTIONS];
    int num_questions;
    int total_score;
} Examination;

// Generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Initialize the examination with random questions
void init_examination(Examination *exam) {
    // Set the number of questions
    exam->num_questions = rand_range(5, 10);

    // Generate random questions
    for (int i = 0; i < exam->num_questions; i++) {
        // Generate a random question
        sprintf(exam->questions[i].question, "Question %d:", i + 1);

        // Generate random choices
        for (int j = 0; j < MAX_CHOICES; j++) {
            sprintf(exam->questions[i].choices[j], "Choice %d:", j + 1);
        }

        // Set the correct answer
        exam->questions[i].correct_answer = rand_range(0, MAX_CHOICES - 1);
    }
}

// Print the examination
void print_examination(const Examination *exam) {
    // Print the header
    printf("Online Examination System\n");
    printf("-------------------------\n");

    // Print the questions
    for (int i = 0; i < exam->num_questions; i++) {
        printf("%s\n", exam->questions[i].question);

        // Print the choices
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("(%d) %s\n", j + 1, exam->questions[i].choices[j]);
        }
    }
}

// Get the user's answers
void get_answers(Examination *exam) {
    // Get the user's answers
    for (int i = 0; i < exam->num_questions; i++) {
        int answer;
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%d", &answer);

        // Check if the answer is correct
        if (answer == exam->questions[i].correct_answer) {
            exam->total_score++;
        }
    }
}

// Print the results
void print_results(const Examination *exam) {
    // Print the header
    printf("Examination Results\n");
    printf("--------------------\n");

    // Print the total score
    printf("Total score: %d/%d\n", exam->total_score, exam->num_questions);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create an examination
    Examination exam;

    // Initialize the examination with random questions
    init_examination(&exam);

    // Print the examination
    print_examination(&exam);

    // Get the user's answers
    get_answers(&exam);

    // Print the results
    print_results(&exam);

    return 0;
}