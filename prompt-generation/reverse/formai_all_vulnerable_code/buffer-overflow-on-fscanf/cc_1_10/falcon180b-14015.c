//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26

// Question structure
typedef struct {
    char question[256];
    int numOptions;
    char options[MAX_OPTIONS][256];
    char answer[MAX_ANSWERS];
} Question;

// Function prototypes
void loadQuestions(Question questions[]);
int askQuestion(Question question);
int main() {
    Question questions[MAX_QUESTIONS];
    loadQuestions(questions);
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        score += askQuestion(questions[i]);
    }
    printf("Your final score is: %d\n", score);
    return 0;
}

void loadQuestions(Question questions[]) {
    FILE *fp;
    char filename[256] = "questions.txt";
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open questions file.\n");
        exit(1);
    }
    int numQuestions = 0;
    while (fscanf(fp, "%s", questions[numQuestions].question)!= EOF) {
        questions[numQuestions].numOptions = 0;
        char option[256];
        while (fscanf(fp, "%s", option)!= EOF) {
            strcpy(questions[numQuestions].options[questions[numQuestions].numOptions], option);
            questions[numQuestions].numOptions++;
        }
        fscanf(fp, "%s", questions[numQuestions].answer);
        numQuestions++;
    }
    fclose(fp);
}

int askQuestion(Question question) {
    int numOptions = question.numOptions;
    int correctAnswer = 0;
    int userAnswer = 0;
    printf("%s\n", question.question);
    for (int i = 0; i < numOptions; i++) {
        printf("%d. %s\n", i+1, question.options[i]);
    }
    scanf("%d", &userAnswer);
    if (userAnswer >= 1 && userAnswer <= numOptions) {
        if (strcmp(question.options[userAnswer-1], question.answer) == 0) {
            correctAnswer = 1;
        }
    }
    return correctAnswer;
}