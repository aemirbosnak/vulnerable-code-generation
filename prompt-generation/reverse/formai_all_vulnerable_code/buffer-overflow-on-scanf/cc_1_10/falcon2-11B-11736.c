//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_SCORE 100

struct Question {
    char* question;
    int answer;
    int score;
};

struct Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", 1, 10},
    {"What is the capital of Spain?", 2, 10},
    {"What is the capital of Germany?", 3, 10},
    {"What is the capital of Italy?", 4, 10},
    {"What is the capital of Japan?", 5, 10},
    {"What is the capital of Russia?", 6, 10},
    {"What is the capital of Australia?", 7, 10},
    {"What is the capital of India?", 8, 10},
    {"What is the capital of China?", 9, 10},
    {"What is the capital of Brazil?", 10, 10}
};

int main() {
    struct Question* currentQuestion = questions;
    int score = 0;

    printf("Welcome to Online Examination System\n");
    printf("Total Questions: %d\n", MAX_QUESTIONS);

    while (score < MAX_SCORE && currentQuestion->question) {
        printf("Question: %s\n", currentQuestion->question);
        printf("Answer: ");
        scanf("%d", &currentQuestion->answer);
        printf("Is this correct? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y') {
            currentQuestion->score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect!\n");
        }

        printf("Score: %d\n", currentQuestion->score);

        currentQuestion++;
    }

    if (score >= MAX_SCORE) {
        printf("Congratulations! You have completed the exam.\n");
    } else {
        printf("Sorry, you have not completed the exam.\n");
    }

    return 0;
}