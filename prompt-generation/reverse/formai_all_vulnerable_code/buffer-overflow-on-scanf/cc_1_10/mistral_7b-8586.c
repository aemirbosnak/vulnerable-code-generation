//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_QUESTIONS 10
#define MAX_QUESTION_LENGTH 100
#define MAX_OPTIONS 4
#define MAX_OPTION_LENGTH 20

typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char options[MAX_OPTIONS][MAX_OPTION_LENGTH];
    char answer;
} Question;

Question periodic_table_questions[NUM_QUESTIONS] = {
    {
        "Which element has the atomic number 1?",
        {"Hydrogen", "Helium", "Lithium", "Boron"},
        'H'
    },
    {
        "Which noble gas is colorless and odorless?",
        {"Neon", "Argon", "Krypton", "Xenon"},
        'N'
    },
    // Add more questions here...
};

void print_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < MAX_OPTIONS; ++i) {
        printf("%s) %s\n", i + 1, question.options[i]);
    }
    printf("Enter your answer (1-%d): ", MAX_OPTIONS);
}

int main() {
    srand(time(NULL));

    int score = 0;
    int total_questions = 0;

    while (total_questions < NUM_QUESTIONS) {
        Question question = periodic_table_questions[rand() % NUM_QUESTIONS];

        print_question(question);
        char user_answer;
        scanf(" %c", &user_answer);

        if (user_answer >= '1' && user_answer <= MAX_OPTIONS + '0' - 1) {
            int correct_answer = user_answer - '0';
            if (question.answer == question.options[correct_answer - 1][0]) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %c.\n", question.answer);
            }
        } else {
            printf("Invalid input. Please try again.\n");
        }

        total_questions++;
    }

    printf("\nYour final score is %d out of %d.\n", score, NUM_QUESTIONS);

    return 0;
}