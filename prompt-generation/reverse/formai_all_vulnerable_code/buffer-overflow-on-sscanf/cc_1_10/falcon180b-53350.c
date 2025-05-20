//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct question {
    char question[100];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    char answer[3];
} Question;

Question questions[10];
int num_questions;

void read_questions() {
    FILE *fp;
    char line[200];
    int i = 0;

    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening questions file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%s %s %s %s %s",
               questions[i].question,
               questions[i].option1,
               questions[i].option2,
               questions[i].option3,
               questions[i].option4);
        questions[i].answer[0] = line[strcspn(line, " ")] - 1;
        i++;
    }

    fclose(fp);
    num_questions = i;
}

void display_question(int index) {
    printf("%s\n", questions[index].question);
    printf("A. %s\n", questions[index].option1);
    printf("B. %s\n", questions[index].option2);
    printf("C. %s\n", questions[index].option3);
    printf("D. %s\n", questions[index].option4);
}

int main() {
    int i, j, score = 0;

    read_questions();

    for (i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i + 1);
        display_question(i);
        printf("Enter your answer (A/B/C/D): ");
        scanf("%c", &questions[i].answer[1]);

        if (questions[i].answer[1] == questions[i].answer[0]) {
            score++;
        }
    }

    printf("Your final score is %d out of %d.\n", score, num_questions);

    return 0;
}