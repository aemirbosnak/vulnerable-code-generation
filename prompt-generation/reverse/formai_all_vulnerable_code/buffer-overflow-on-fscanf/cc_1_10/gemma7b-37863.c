//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

struct Question {
    char question[256];
    char answer[256];
    int marks;
    int difficulty;
};

void readQuestions(struct Question questions[]) {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        return;
    }

    int i = 0;
    while (fscanf(fp, "%[^\n]%*c", questions[i].question) != EOF) {
        fscanf(fp, "%[^\n]%*c", questions[i].answer);
        fscanf(fp, "%d ", &questions[i].marks);
        fscanf(fp, "%d ", &questions[i].difficulty);
        i++;
    }

    fclose(fp);
}

int main() {
    struct Question questions[MAX_QUESTIONS];
    readQuestions(questions);

    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
        printf("Enter your answer: ");
        char answer[256];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            score += questions[i].marks;
        }
    }

    printf("Your total score is: %d", score);

    return 0;
}