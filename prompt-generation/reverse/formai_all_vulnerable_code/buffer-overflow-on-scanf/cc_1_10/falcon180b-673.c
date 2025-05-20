//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 1000

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer[100];
} question_t;

void read_questions(question_t questions[]) {
    FILE *fp;
    char line[1000];
    int i = 0;

    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open questions file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= MAX_QUESTIONS) {
            printf("Error: too many questions.\n");
            exit(1);
        }
        strcpy(questions[i].question, line);
        questions[i].answer[0] = '\0';
        int j = 0;
        while (fgets(line, sizeof(line), fp)!= NULL && j < MAX_OPTIONS) {
            strcpy(questions[i].options[j], line);
            j++;
        }
        i++;
    }

    fclose(fp);
}

int main() {
    question_t questions[MAX_QUESTIONS];
    char username[100];
    int score = 0;
    int i = 0;

    printf("Enter your name: ");
    scanf("%s", username);

    read_questions(questions);

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("\n%s\n", questions[i].question);
        int j = 0;
        while (j < MAX_OPTIONS && questions[i].options[j][0]!= '\0') {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
            j++;
        }
        char answer[100];
        scanf("%s", answer);
        tolower(answer);
        tolower(questions[i].answer);
        if (strcmp(answer, questions[i].answer) == 0) {
            score++;
        }
    }

    printf("\n%s, your final score is %d out of %d.\n", username, score, MAX_QUESTIONS);

    return 0;
}