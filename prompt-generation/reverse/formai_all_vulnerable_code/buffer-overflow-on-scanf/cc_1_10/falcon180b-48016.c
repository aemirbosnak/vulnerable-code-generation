//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_QUESTIONS 10

struct Question {
    char question[MAX_SIZE];
    char option1[MAX_SIZE];
    char option2[MAX_SIZE];
    char option3[MAX_SIZE];
    char option4[MAX_SIZE];
    char correctAnswer[MAX_SIZE];
};

struct Question questions[MAX_QUESTIONS];

int main() {
    int numQuestions;
    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);

    for (int i = 0; i < numQuestions; i++) {
        printf("Enter question %d:\n", i+1);
        scanf("%s", questions[i].question);

        printf("Enter option 1:\n");
        scanf("%s", questions[i].option1);

        printf("Enter option 2:\n");
        scanf("%s", questions[i].option2);

        printf("Enter option 3:\n");
        scanf("%s", questions[i].option3);

        printf("Enter option 4:\n");
        scanf("%s", questions[i].option4);

        printf("Enter correct answer:\n");
        scanf("%s", questions[i].correctAnswer);
    }

    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        printf("Question %d:\n%s\n", i+1, questions[i].question);
        printf("Option 1: %s\n", questions[i].option1);
        printf("Option 2: %s\n", questions[i].option2);
        printf("Option 3: %s\n", questions[i].option3);
        printf("Option 4: %s\n", questions[i].option4);

        char answer[MAX_SIZE];
        printf("Enter your answer: ");
        scanf("%s", answer);

        if (strcmp(answer, questions[i].correctAnswer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("Your score is %d out of %d.\n", score, numQuestions);

    return 0;
}