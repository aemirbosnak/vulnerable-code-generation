//FormAI DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 4

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][50];
    int answer;
} Question;

int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    Question questions[MAX_QUESTIONS] = {
        {
            .question = "What is the capital of India?",
            .options = {"Mumbai", "Delhi", "Kolkata", "Chennai"},
            .answer = 1
        },
        {
            .question = "What is the largest planet in our solar system?",
            .options = {"Venus", "Jupiter", "Mars", "Earth"},
            .answer = 1
        },
        {
            .question = "Which is the tallest mammal in the world?",
            .options = {"Giraffe", "Elephant", "Camel", "Horse"},
            .answer = 0
        },
        {
            .question = "What is the currency of Japan?",
            .options = {"Yen", "Dollar", "Euro", "Pound"},
            .answer = 0
        },
        {
            .question = "What is the highest mountain in the world?",
            .options = {"Everest", "K2", "Kilimanjaro", "Makalu"},
            .answer = 0
        }
    };

    srand(time(NULL));
    int total_score = 0;

    printf("Welcome to the C Online Examination System\n");
    for (int i = 0; i < MAX_QUESTIONS; ++i) {
        int question_index = generate_random_number(0, MAX_QUESTIONS - 1);
        Question question = questions[question_index];

        printf("\nQuestion %d: %s\n", i + 1, question.question);
        printf("Options:\n");
        for (int j = 0; j < MAX_OPTIONS; ++j) {
            printf("%c) %s\n", 'a' + j, question.options[j]);
        }

        char user_input;
        printf("Enter your answer (a/b/c/d): ");
        scanf("%c", &user_input);
        getchar();

        if (user_input - 'a' == question.answer) {
            printf("Correct Answer!\n");
            total_score++;
        } else {
            printf("Wrong Answer!\n");
        }
    }

    printf("\n\nTotal Score: %d/%d\n", total_score, MAX_QUESTIONS);
    return 0;
}