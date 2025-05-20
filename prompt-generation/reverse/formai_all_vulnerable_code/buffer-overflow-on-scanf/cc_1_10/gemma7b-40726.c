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
    {"What is the meaning of the word 'entrepreneur'?", {"a. Business owner", "b. Employee", "c. Manager", "d. Salesperson"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Isaac Newton", "b. Albert Einstein", "c. Charles Darwin", "d. Galileo Galilei"}, 2},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 3},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 4},
    {"Which animal is known for its long tail?", {"a. Elephant", "b. Giraffe", "c. Snake", "d. Cat"}, 5},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. A hum", "c. A click", "d. A squeak"}, 6},
    {"Which fruit is the most popular in the world?", {"a. Apple", "b. Orange", "c. Banana", "d. Strawberry"}, 7},
    {"What is the meaning of the word 'entrepreneur'?", {"a. Business owner", "b. Employee", "c. Manager", "d. Salesperson"}, 8},
    {"Which scientist invented the theory of relativity?", {"a. Isaac Newton", "b. Albert Einstein", "c. Charles Darwin", "d. Galileo Galilei"}, 9},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 10}
};

int main() {
    int i, score = 0, currentQuestion = 0;

    system("cls");

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);

        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("  %s\n", questions[i].answers[j]);
        }

        printf("Enter your answer: ");
        char answer[256];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answers[questions[i].correctAnswer]) == 0) {
            score++;
        }

        currentQuestion++;
    }

    printf("Your score: %d", score);

    return 0;
}