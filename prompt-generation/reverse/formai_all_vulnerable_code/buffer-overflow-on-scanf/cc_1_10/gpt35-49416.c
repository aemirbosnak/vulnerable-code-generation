//FormAI DATASET v1.0 Category: Online Examination System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[1000];
    char options[4][100];
    int correct_option;
};

struct Exam {
    char name[25];
    struct Question questions[5];
};

int main() {
    struct Exam exam;
    int marks = 0;
    char answer[10];

    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    scanf("%s", exam.name);

    // Question 1
    strcpy(exam.questions[0].question, "What is the capital of India?");
    strcpy(exam.questions[0].options[0], "A. New Delhi");
    strcpy(exam.questions[0].options[1], "B. Mumbai");
    strcpy(exam.questions[0].options[2], "C. Kolkata");
    strcpy(exam.questions[0].options[3], "D. Chennai");
    exam.questions[0].correct_option = 0;

    // Question 2
    strcpy(exam.questions[1].question, "Which is the largest continent in the world?");
    strcpy(exam.questions[1].options[0], "A. Africa");
    strcpy(exam.questions[1].options[1], "B. Asia");
    strcpy(exam.questions[1].options[2], "C. Europe");
    strcpy(exam.questions[1].options[3], "D. North America");
    exam.questions[1].correct_option = 1;

    // Question 3
    strcpy(exam.questions[2].question, "What is the smallest continent in the world?");
    strcpy(exam.questions[2].options[0], "A. Africa");
    strcpy(exam.questions[2].options[1], "B. Antarctica");
    strcpy(exam.questions[2].options[2], "C. Europe");
    strcpy(exam.questions[2].options[3], "D. Australia");
    exam.questions[2].correct_option = 3;

    // Question 4
    strcpy(exam.questions[3].question, "What is the largest ocean in the world?");
    strcpy(exam.questions[3].options[0], "A. Indian Ocean");
    strcpy(exam.questions[3].options[1], "B. Atlantic Ocean");
    strcpy(exam.questions[3].options[2], "C. Arctic Ocean");
    strcpy(exam.questions[3].options[3], "D. Pacific Ocean");
    exam.questions[3].correct_option = 3;

    // Question 5
    strcpy(exam.questions[4].question, "What is the currency of Japan?");
    strcpy(exam.questions[4].options[0], "A. Yen");
    strcpy(exam.questions[4].options[1], "B. Dollar");
    strcpy(exam.questions[4].options[2], "C. Euro");
    strcpy(exam.questions[4].options[3], "D. Peso");
    exam.questions[4].correct_option = 0;

    printf("\n%s, please answer the following questions:\n", exam.name);

    for (int i = 0; i < 5; i++) {
        printf("\nQuestion %d:\n", i+1);
        printf("%s\n", exam.questions[i].question);
        printf("%s\n", exam.questions[i].options[0]);
        printf("%s\n", exam.questions[i].options[1]);
        printf("%s\n", exam.questions[i].options[2]);
        printf("%s\n", exam.questions[i].options[3]);
        printf("Your answer: ");
        scanf("%s", answer);
        if (answer[0] == exam.questions[i].correct_option + 'A') {
            marks += 1;
        }
    }

    printf("\n%s, your marks: %d/5\n", exam.name, marks);

    return 0;
}