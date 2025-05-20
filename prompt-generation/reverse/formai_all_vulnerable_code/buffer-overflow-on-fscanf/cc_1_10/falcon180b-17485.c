//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_ANSWERS 26
#define PASS_MARK 50

typedef struct {
    char question[100];
    char choices[MAX_CHOICES][50];
    char answer[MAX_ANSWERS];
} Question;

void loadQuestions(Question questions[MAX_QUESTIONS]) {
    FILE *fp;
    int i = 0;

    fp = fopen("questions.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", questions[i].question)!= EOF) {
        for (int j = 0; j < MAX_CHOICES; j++) {
            fscanf(fp, "%s", questions[i].choices[j]);
        }
        fscanf(fp, "%s", questions[i].answer);
        i++;
    }

    fclose(fp);
}

int main() {
    Question questions[MAX_QUESTIONS];
    int score = 0;
    char choice;

    loadQuestions(questions);

    printf("Welcome to the Online Examination System!\n\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %s\n", i+1, questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%c) %s\n", 'A'+j, questions[i].choices[j]);
        }
        printf("Enter your answer (A/B/C/D/E): ");
        scanf("%c", &choice);

        if (choice == questions[i].answer[0]) {
            score++;
        }
    }

    if (score >= PASS_MARK) {
        printf("Congratulations! You passed the exam with a score of %d out of %d.\n", score, MAX_QUESTIONS);
    } else {
        printf("Sorry, you failed the exam with a score of %d out of %d.\n", score, MAX_QUESTIONS);
    }

    return 0;
}