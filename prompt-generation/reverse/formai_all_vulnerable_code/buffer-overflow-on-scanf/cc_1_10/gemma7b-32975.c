//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", "Paris", 5},
    {"Who invented the telephone?", "Alexander Graham Bell", 4},
    {"Which planet is the largest?", "Jupiter", 6},
    {"What is the meaning of the word 'entrepreneur'?", "Someone who starts and manages a business", 3},
    {"Which scientist won the Nobel Prize in Physics in 2020?", "Roger Penrose", 4},
    {"Which animal is known for its long tail?", "Giraffe", 2},
    {"What is the symbol of the United States dollar?", "The eagle", 3},
    {"Which fruit is the most popular in the world?", "Apple", 4},
    {"What is the most common color of hair in the world?", "Black", 5},
    {"Which country is the largest exporter of oil?", "Saudi Arabia", 6}
};

int main() {
    system("clear");
    int score = 0;
    int currentQuestion = 0;

    printf("Welcome to the C Online Examination System!\n");

    while (currentQuestion < MAX_QUESTIONS) {
        printf("Question %d: %s\n", currentQuestion + 1, questions[currentQuestion].question);

        char answer[256];
        printf("Enter your answer: ");
        scanf("%s", answer);

        if (strcmp(answer, questions[currentQuestion].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The answer is: %s\n", questions[currentQuestion].answer);
        }

        currentQuestion++;
    }

    printf("Your total score is: %d\n", score);

    return 0;
}