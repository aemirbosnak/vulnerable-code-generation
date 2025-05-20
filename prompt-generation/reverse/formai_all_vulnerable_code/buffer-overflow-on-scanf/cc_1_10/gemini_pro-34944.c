//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char question[100];
    char options[4][50];
    int correct_option;
} Question;

void print_question(Question question) {
    printf("Question: %s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("Option %d: %s\n", i + 1, question.options[i]);
    }
}

int main() {
    Question questions[] = {
        {
            "What is the capital of India?",
            {"New Delhi", "Mumbai", "Chennai", "Kolkata"},
            1
        },
        {
            "Who is the Prime Minister of India?",
            {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"},
            1
        },
        {
            "What is the currency of India?",
            {"Rupee", "Dollar", "Euro", "Pound"},
            1
        },
        {
            "What is the national animal of India?",
            {"Tiger", "Lion", "Elephant", "Peacock"},
            1
        },
        {
            "What is the national bird of India?",
            {"Peacock", "Parrot", "Eagle", "Owl"},
            1
        }
    };

    int num_questions = sizeof(questions) / sizeof(questions[0]);

    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        print_question(questions[i]);
        int answer;
        scanf("%d", &answer);
        if (answer == questions[i].correct_option) {
            score++;
        }
    }

    printf("Your score is %d out of %d.\n", score, num_questions);

    return 0;
}