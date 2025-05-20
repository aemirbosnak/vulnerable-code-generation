//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and manages their own business", 5},
    {"Which scientist invented the theory of relativity?", "Albert Einstein", 5},
    {"What is the capital of France?", "Paris", 5},
    {"Which animal is known for its ability to swim?", "Fish", 5},
    {"What is the sound of one hand clapping?", "Silence", 5},
    {"Which planet is the largest?", "Jupiter", 5},
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and manages their own business", 5},
    {"Which scientist invented the theory of relativity?", "Albert Einstein", 5},
    {"What is the capital of France?", "Paris", 5},
    {"Which animal is known for its ability to swim?", "Fish", 5}
};

int main() {
    int i, score = 0, totalQuestions = MAX_QUESTIONS;

    // Shuffle the questions
    srand(time(NULL));
    for (i = 0; i < totalQuestions; i++) {
        int randIndex = rand() % totalQuestions;
        Question temp = questions[i];
        questions[i] = questions[randIndex];
        questions[randIndex] = temp;
    }

    // Display the questions and get the user's answers
    for (i = 0; i < totalQuestions; i++) {
        printf("%s\n", questions[i].question);
        char answer[256];
        printf("Enter your answer: ");
        scanf("%s", answer);

        // Check if the user's answer is correct
        if (strcmp(answer, questions[i].answer) == 0) {
            score++;
        }
    }

    // Calculate the user's total score
    int totalMarks = score * questions[0].marks;

    // Display the results
    printf("Your total score is: %d/%d (%d%%)\n", score, totalQuestions, (totalMarks * 100) / totalQuestions);

    return 0;
}