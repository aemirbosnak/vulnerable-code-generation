//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char question[256];
    char answers[MAX_ANSWERS][256];
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages a business", "b. A person who is good at math", "c. A person who is creative", "d. A person who is successful"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 2},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 3},
    {"What is the most common color of the human hair?", {"a. Black", "b. Brown", "c. Red", "d. Blonde"}, 4},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 5},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. A hum", "c. A click", "d. A beep"}, 6},
    {"Which fruit is the most popular in the world?", {"a. Apple", "b. Orange", "c. Banana", "d. Mango"}, 7},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages a business", "b. A person who is good at math", "c. A person who is creative", "d. A person who is successful"}, 8},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 9},
    {"What is the most common color of the human hair?", {"a. Black", "b. Brown", "c. Red", "d. Blonde"}, 10}
};

int main() {
    int i, score = 0, correctAnswer;
    char answer;

    // Display the questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);

        // Display the answers
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%s\n", questions[i].answers[j]);
        }

        // Get the user's answer
        printf("Enter your answer: ");
        scanf(" %c", &answer);

        // Check if the answer is correct
        correctAnswer = questions[i].correctAnswer == (answer - 'a') ? 1 : 0;

        // Increment the score if the answer is correct
        if (correctAnswer) {
            score++;
        }
    }

    // Display the results
    printf("Your score: %d/%d\n", score, MAX_QUESTIONS);

    return 0;
}