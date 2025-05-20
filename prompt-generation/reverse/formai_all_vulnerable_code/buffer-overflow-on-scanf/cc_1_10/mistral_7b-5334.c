//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_WORDS 50

typedef struct {
    char question[MAX_WORDS];
    int answer;
    char options[MAX_OPTIONS][MAX_WORDS];
} Question;

void readQuestions(Question questions[], int numQuestions) {
    for (int i = 0; i < numQuestions; i++) {
        printf("Enter question %d: ", i + 1);
        fgets(questions[i].question, MAX_WORDS, stdin);
        questions[i].question[strcspn(questions[i].question, "\n")] = '\0';

        printf("Enter option A for question %d: ", i + 1);
        fgets(questions[i].options[0], MAX_WORDS, stdin);
        questions[i].options[0][strcspn(questions[i].options[0], "\n")] = '\0';

        printf("Enter option B for question %d: ", i + 1);
        fgets(questions[i].options[1], MAX_WORDS, stdin);
        questions[i].options[1][strcspn(questions[i].options[1], "\n")] = '\0';

        printf("Enter option C for question %d: ", i + 1);
        fgets(questions[i].options[2], MAX_WORDS, stdin);
        questions[i].options[2][strcspn(questions[i].options[2], "\n")] = '\0';

        printf("Enter option D for question %d: ", i + 1);
        fgets(questions[i].options[3], MAX_WORDS, stdin);
        questions[i].options[3][strcspn(questions[i].options[3], "\n")] = '\0';

        printf("Enter answer for question %d: ", i + 1);
        scanf("%d", &questions[i].answer);

        printf("\n");
    }
}

void displayQuestion(Question question) {
    printf("\n%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%c) %s\n", 'A' + i, question.options[i]);
    }
}

int main() {
    int numQuestions;
    Question questions[MAX_QUESTIONS];

    printf("Enter number of questions: ");
    scanf("%d", &numQuestions);

    readQuestions(questions, numQuestions);

    int userAnswer, score = 0;

    for (int i = 0; i < numQuestions; i++) {
        displayQuestion(questions[i]);
        scanf("%d", &userAnswer);

        if (userAnswer == questions[i].answer) {
            score++;
        }
    }

    printf("\nYour score is %d out of %d.\n", score, numQuestions);

    return 0;
}