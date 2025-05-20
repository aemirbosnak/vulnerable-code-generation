//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer[MAX_ANSWERS];
} Question;

void shuffle(char arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void readQuestions(Question questions[], int n) {
    FILE *fp;
    char line[100];
    int i = 0;
    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)!= NULL) {
        strcpy(questions[i].question, line);
        i++;
    }
    fclose(fp);
}

void readOptions(Question questions[], int n) {
    FILE *fp;
    char line[100];
    int i, j;
    fp = fopen("options.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        j = 0;
        while (fgets(line, sizeof(line), fp)!= NULL) {
            strcpy(questions[i].options[j], line);
            j++;
        }
    }
    fclose(fp);
}

void readAnswers(Question questions[], int n) {
    FILE *fp;
    char line[MAX_ANSWERS];
    int i, j;
    fp = fopen("answers.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        j = 0;
        while (fgets(line, sizeof(line), fp)!= NULL) {
            strcpy(questions[i].answer + j, line);
            j++;
        }
    }
    fclose(fp);
}

void displayQuestion(Question question) {
    int i;
    printf("Question: %s\n", question.question);
    for (i = 0; i < strlen(question.answer); i++) {
        printf("%c", question.answer[i]);
    }
    printf("\n");
    for (i = 0; i < question.options[0][0]; i++) {
        printf("Option %d: %s\n", i + 1, question.options[i]);
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    int n, i, correct = 0;
    char filename[100];
    srand(time(NULL));
    printf("Enter the number of questions: ");
    scanf("%d", &n);
    sprintf(filename, "questions.txt");
    readQuestions(questions, n);
    sprintf(filename, "options.txt");
    readOptions(questions, n);
    sprintf(filename, "answers.txt");
    readAnswers(questions, n);
    for (i = 0; i < n; i++) {
        shuffle(questions[i].options, questions[i].options[0][0]);
    }
    for (i = 0; i < n; i++) {
        displayQuestion(questions[i]);
        printf("Enter your answer: ");
        scanf("%s", questions[i].answer);
        if (strcmp(questions[i].answer, questions[i].options[0]) == 0) {
            correct++;
        }
    }
    printf("You got %d out of %d correct.\n", correct, n);
    return 0;
}