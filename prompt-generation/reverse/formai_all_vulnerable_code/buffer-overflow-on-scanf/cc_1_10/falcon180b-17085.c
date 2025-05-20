//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 4
#define MAX_ANSWERS 26
#define PASS_SCORE 60

typedef struct {
    char question[100];
    char choices[MAX_CHOICES][MAX_ANSWERS];
    char answer[MAX_ANSWERS];
} Question;

int main() {
    srand(time(NULL));

    Question questions[MAX_QUESTIONS];
    int numQuestions;
    int score = 0;

    printf("Welcome to the Romeo and Juliet Online Examination System!\n");
    printf("Please enter the number of questions you would like in the exam (1-100): ");
    scanf("%d", &numQuestions);

    for (int i = 0; i < numQuestions; i++) {
        printf("Enter question #%d:\n", i+1);
        scanf("%s", questions[i].question);

        printf("Enter the choices for question #%d (separated by commas):\n", i+1);
        scanf("%s", questions[i].choices[0]);
        for (int j = 1; j < MAX_CHOICES; j++) {
            scanf(",");
            scanf("%s", questions[i].choices[j]);
        }

        printf("Enter the correct answer for question #%d:\n", i+1);
        scanf("%s", questions[i].answer);
    }

    printf("\nStarting the exam...\n");

    for (int i = 0; i < numQuestions; i++) {
        printf("\nQuestion #%d:\n%s\n", i+1, questions[i].question);

        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%c. %s\n", 'A'+j, questions[i].choices[j]);
        }

        char choice;
        scanf(" %c", &choice);

        if (choice == questions[i].answer[0]) {
            printf("\nCorrect!\n");
            score++;
        } else {
            printf("\nIncorrect. The correct answer is: %s\n", questions[i].answer);
        }
    }

    printf("\nExam complete!\n");

    if (score >= PASS_SCORE) {
        printf("\nCongratulations! You passed the exam with a score of %d out of %d.\n", score, numQuestions);
    } else {
        printf("\nSorry, you did not pass the exam with a score of %d out of %d.\n", score, numQuestions);
    }

    return 0;
}