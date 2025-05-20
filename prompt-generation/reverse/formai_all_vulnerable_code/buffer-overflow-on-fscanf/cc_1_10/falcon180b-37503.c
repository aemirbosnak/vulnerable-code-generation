//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_QUESTIONS 20
#define MAX_OPTIONS 4
#define MAX_ANSWERS 100
#define PASS_PERCENTAGE 60

typedef struct {
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    char answer[3];
} Question;

void loadQuestions(Question questions[]) {
    FILE *fp;
    fp = fopen("questions.txt", "r");

    int count = 0;
    while (fscanf(fp, "%s %s %s %s %s", questions[count].question, questions[count].option1, questions[count].option2, questions[count].option3, questions[count].option4)!= EOF) {
        count++;
    }

    fclose(fp);
}

int main() {
    Question questions[MAX_QUESTIONS];
    int score = 0;
    int i, j;

    loadQuestions(questions);

    printf("Welcome to the Online Examination System!\n\n");

    for (i = 0; i < MAX_QUESTIONS; i++) {
        if (questions[i].question[0]!= '\0') {
            printf("%d. %s\n", i + 1, questions[i].question);

            for (j = 0; j < MAX_OPTIONS; j++) {
                printf("%c. %s\n", 'A' + j, questions[i].option1);
            }

            char choice;
            scanf("%c", &choice);

            if (tolower(choice) == tolower(questions[i].answer[0])) {
                score++;
            }
        }
    }

    printf("\nYour score is: %d out of %d\n", score, MAX_QUESTIONS);

    if (score >= (MAX_QUESTIONS * PASS_PERCENTAGE) / 100) {
        printf("Congratulations! You have passed the exam.\n");
    } else {
        printf("Sorry, you have not passed the exam.\n");
    }

    return 0;
}