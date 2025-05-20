//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_ANSWERS 26

typedef struct {
    char question[100];
    char choices[MAX_CHOICES][50];
    char answer[MAX_ANSWERS];
} Question;

void loadQuestions(Question questions[]) {
    FILE *fp;
    char filename[50] = "questions.txt";
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error loading questions.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s\n%s\n%s\n", questions[i].question, questions[i].choices[0], questions[i].answer)!= EOF) {
        for (int j = 1; j < MAX_CHOICES; j++) {
            fscanf(fp, "%s\n", questions[i].choices[j]);
        }
        i++;
    }

    fclose(fp);
}

int main() {
    Question questions[MAX_QUESTIONS];
    loadQuestions(questions);

    int numQuestions;
    printf("Enter number of questions: ");
    scanf("%d", &numQuestions);

    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d:\n%s\n", i+1, questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%c. %s\n", j+1, questions[i].choices[j]);
        }
        char answer[MAX_ANSWERS];
        scanf("%s", answer);
        if (strcmp(answer, questions[i].answer) == 0) {
            score++;
        }
    }

    printf("\nYour final score is %d out of %d.\n", score, numQuestions);

    return 0;
}