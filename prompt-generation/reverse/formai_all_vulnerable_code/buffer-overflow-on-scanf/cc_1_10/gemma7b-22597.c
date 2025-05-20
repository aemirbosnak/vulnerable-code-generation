//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char question[256];
    char answers[MAX_ANSWERS][256];
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"A. A person who sells things.", "B. A person who owns a business.", "C. A person who is good at math.", "D. A person who is good at writing"}, 2},
    {"Which planet is the largest?", {"A. Earth", "B. Mars", "C. Jupiter", "D. Saturn"}, 1},
    {"What is the capital of France?", {"A. Paris", "B. Rome", "C. Berlin", "D. Lyon"}, 1}
};

int main() {
    int i, score = 0, timeLeft = 60;
    char answer;

    // Seed the random number generator
    srand(time(NULL));

    // Shuffle the questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        int j = rand() % MAX_QUESTIONS;
        Question tmp = questions[i];
        questions[i] = questions[j];
        questions[j] = tmp;
    }

    // Start the timer
    clock_t startTime = clock();

    // Loop over the questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        // Print the question
        printf("%s\n", questions[i].question);

        // Get the answer
        printf("Enter your answer: ");
        scanf("%c", &answer);

        // Check if the answer is correct
        if (answer == questions[i].correctAnswer) {
            score++;
        }

        // Time left
        timeLeft--;
    }

    // Stop the timer
    clock_t endTime = clock();

    // Calculate the time spent
    int timeSpent = (endTime - startTime) / CLOCKS_PER_SEC;

    // Print the results
    printf("Your score: %d\n", score);
    printf("Time spent: %d seconds\n", timeSpent);

    return 0;
}