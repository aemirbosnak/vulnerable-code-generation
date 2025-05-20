//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[255];
    char answer[255];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of life?", "To be happy", 10},
    {"Who invented the computer?", "Charles Babbage", 10},
    {"What is the capital of France?", "Paris", 10},
    {"What is the sound of one hand clapping?", "Silence", 5},
    {"What is the meaning of the word 'entrepreneur'?", "Someone who starts their own business", 8},
    {"What is the most common color in the world?", "Red", 8},
    {"What is the sound of a goose?", "Honking", 5},
    {"What is the meaning of the word 'mathematics'", "The study of numbers", 8},
    {"What is the capital of Australia?", "Canberra", 10},
    {"What is the most valuable gemstone in the world?", "Diamond", 10}
};

int main() {
    system("clear");
    int score = 0;
    int currentQuestion = 0;

    // Print the questions
    printf("Welcome to the C Online Examination System!\n\n");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
    }

    // Get the user's answer
    printf("Enter your answer for the first question: ");
    char answer[255];
    scanf("%s", answer);

    // Check if the answer is correct
    if (strcmp(answer, questions[currentQuestion].answer) == 0) {
        score++;
        printf("Correct! You have earned %d marks.\n", questions[currentQuestion].marks);
    } else {
        printf("Incorrect. The answer is: %s. You have earned %d marks.\n", questions[currentQuestion].answer, questions[currentQuestion].marks);
    }

    // Repeat for the remaining questions
    for (int i = 1; i < MAX_QUESTIONS; i++) {
        currentQuestion++;
        printf("Enter your answer for question %d: ", currentQuestion);
        scanf("%s", answer);

        if (strcmp(answer, questions[currentQuestion].answer) == 0) {
            score++;
            printf("Correct! You have earned %d marks.\n", questions[currentQuestion].marks);
        } else {
            printf("Incorrect. The answer is: %s. You have earned %d marks.\n", questions[currentQuestion].answer, questions[currentQuestion].marks);
        }
    }

    // Print the final score
    printf("Your total score is: %d\n", score);

    return 0;
}