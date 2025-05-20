//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
    char* question;
    char* option1;
    char* option2;
    char* option3;
    char* option4;
    char* correct_answer;
};

struct question questions[] = {
    {
        "What is the capital of India?",
        "New Delhi",
        "Mumbai",
        "Chennai",
        "Bangalore",
        "New Delhi"
    },
    {
        "What is the largest planet in our solar system?",
        "Jupiter",
        "Saturn",
        "Mars",
        "Venus",
        "Jupiter"
    },
    {
        "Who invented the telephone?",
        "Alexander Graham Bell",
        "Thomas Edison",
        "Benjamin Franklin",
        "Albert Einstein",
        "Alexander Graham Bell"
    },
    {
        "What is the highest mountain in the world?",
        "Mount Everest",
        "K2",
        "Kangchenjunga",
        "Lhotse",
        "Mount Everest"
    }
};

int main() {
    int num_questions = sizeof(questions) / sizeof(questions[0]);
    int choice, correct_answer, score = 0;
    char option1[100], option2[100], option3[100], option4[100];

    printf("Welcome to the online examination system!\n");
    printf("Enter the number of questions you want to answer:\n");
    scanf("%d", &num_questions);

    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n", i + 1);
        printf("%s\n\n", questions[i].question);
        printf("Choose your answer from the options below:\n\n");
        printf("%s\n", questions[i].option1);
        printf("%s\n", questions[i].option2);
        printf("%s\n", questions[i].option3);
        printf("%s\n", questions[i].option4);
        printf("Your answer:\n");
        scanf("%s", option1);
        scanf("%s", option2);
        scanf("%s", option3);
        scanf("%s", option4);
        if (strcmp(option1, questions[i].correct_answer) == 0) {
            score++;
        }
        if (strcmp(option2, questions[i].correct_answer) == 0) {
            score++;
        }
        if (strcmp(option3, questions[i].correct_answer) == 0) {
            score++;
        }
        if (strcmp(option4, questions[i].correct_answer) == 0) {
            score++;
        }
    }
    printf("Your score is: %d/%d\n", score, num_questions);
    return 0;
}