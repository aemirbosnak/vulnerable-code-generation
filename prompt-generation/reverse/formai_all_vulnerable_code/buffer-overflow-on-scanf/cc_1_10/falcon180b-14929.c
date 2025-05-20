//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 20
#define PASS_PERCENTAGE 50

struct question {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer[MAX_ANSWERS];
};

int main() {
    int num_questions, i, j, correct_answers = 0;
    char ch;
    struct question questions[MAX_QUESTIONS];

    printf("Welcome to the Online Examination System!\n");
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the questions and options:\n");
    for (i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i+1);
        scanf("%s", questions[i].question);

        printf("Enter the options (separated by ','): ");
        while (1) {
            scanf("%s", questions[i].options[j]);
            if (j >= MAX_OPTIONS - 1) {
                printf("Maximum number of options reached.\n");
                break;
            }
            ch = questions[i].options[j][strlen(questions[i].options[j]) - 1];
            if (ch!= ',') {
                printf("Invalid option format.\n");
                j--;
            } else {
                questions[i].options[j][strlen(questions[i].options[j]) - 1] = '\0';
                j++;
            }
        }

        printf("Enter the correct answer: ");
        scanf("%s", questions[i].answer);
    }

    printf("Enter your answers (separated by ','): ");
    scanf("%s", ch);
    while (ch!= '\0') {
        if (isdigit(ch)) {
            correct_answers++;
        }
        ch = getchar();
    }

    if (correct_answers >= num_questions * PASS_PERCENTAGE / 100) {
        printf("Congratulations! You have passed the examination.\n");
    } else {
        printf("Sorry, you have not passed the examination.\n");
    }

    return 0;
}