//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS];

void createQuestions() {
    int i = 0;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        questions[i].marks = 0;
        printf("Enter question %d: ", i + 1);
        gets(questions[i].question);
        printf("Enter answer for question %d: ", i + 1);
        gets(questions[i].answer);
    }
}

void takeExam() {
    int i = 0;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: ", i + 1);
        printf("%s", questions[i].question);
        printf("\n");
        printf("Enter your answer: ");
        char answer[256];
        gets(answer);
        if (strcmp(answer, questions[i].answer) == 0) {
            questions[i].marks = questions[i].marks + 1;
            printf("Correct!\n");
        } else {
            printf("Incorrect. The answer is: %s", questions[i].answer);
        }
    }
}

int main() {
    createQuestions();
    takeExam();
    int totalMarks = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        totalMarks = totalMarks + questions[i].marks;
    }
    printf("Total marks: %d", totalMarks);
    return 0;
}