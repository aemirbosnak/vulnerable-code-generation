//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question
{
    char *question;
    char **answers;
    int answerIndex;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. A businessman", "b. A dreamer", "c. A leader", "d. A visionary"}, 2},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 0},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Brussels"}, 0},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 1},
    {"What is the most common color of hair in the world?", {"a. Black", "b. Brown", "c. Blonde", "d. Red"}, 2},
    {"Which animal is the largest predator on Earth?", {"a. Lion", "b. Tiger", "c. Great White Shark", "d. Polar Bear"}, 0},
    {"What is the most expensive fruit in the world?", {"a. Black Truffle", "b. Diamond Fruit", "c. Sapodilla", "d. Golden Fig"}, 0},
    {"Which mathematician invented calculus?", {"a. Archimedes", "b. Pythagoras", "c. Isaac Newton", "d. Gottfried Wilhelm Leibniz"}, 0},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A businessman", "b. A dreamer", "c. A leader", "d. A visionary"}, 2},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 0}
};

int main()
{
    int i = 0;
    int score = 0;

    // Generate a random question
    int randQuestion = rand() % MAX_QUESTIONS;

    // Display the question
    printf("%s\n", questions[randQuestion].question);

    // Get the user's answer
    char answer[MAX_ANSWERS];
    printf("Enter your answer: ");
    scanf("%s", answer);

    // Check if the user's answer is correct
    if (strcmp(answer, questions[randQuestion].answers[questions[randQuestion].answerIndex]) == 0)
    {
        // Increment the user's score
        score++;
    }

    // Display the user's score
    printf("Your score: %d\n", score);

    return 0;
}