//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Surprise! This C Online Examination System is a masterpiece!

// Constants for the questions
#define NUM_QUESTIONS 10
#define MAX_ANSWER_LENGTH 100

// Question structure
typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} Question;

// Function to generate a random number
int rand_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random question
Question generate_question() {
    Question question;
    int num1 = rand_int(1, 10);
    int num2 = rand_int(1, 10);
    sprintf(question.question, "What is %d + %d?", num1, num2);
    sprintf(question.answer, "%d", num1 + num2);
    return question;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the questions
    Question questions[NUM_QUESTIONS];
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        questions[i] = generate_question();
    }

    // Print the questions and get the answers
    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
        char answer[MAX_ANSWER_LENGTH];
        scanf("%s", answer);
        if (strcmp(answer, questions[i].answer) == 0) {
            score++;
        }
    }

    // Print the score
    printf("Your score is %d out of %d.\n", score, NUM_QUESTIONS);

    return 0;
}