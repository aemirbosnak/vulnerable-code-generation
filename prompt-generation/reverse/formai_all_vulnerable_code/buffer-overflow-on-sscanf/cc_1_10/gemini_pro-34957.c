//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    int correct_answer;
} Question;

Question questions[MAX_QUESTIONS];
int num_questions;

void load_questions() {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        perror("Error opening questions.txt");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        Question question;
        char *p = line;

        // Get the question
        sscanf(p, "%[^:]:", question.question);
        p += strlen(question.question) + 2;

        // Get the options
        for (int i = 0; i < MAX_OPTIONS; i++) {
            sscanf(p, "%[^|]|", question.options[i]);
            p += strlen(question.options[i]) + 1;
        }

        // Get the correct answer
        sscanf(p, "%d", &question.correct_answer);

        // Add the question to the array
        questions[num_questions++] = question;
    }

    fclose(fp);
}

void take_exam() {
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d) %s\n", j + 1, questions[i].options[j]);
        }

        int answer;
        scanf("%d", &answer);

        if (answer == questions[i].correct_answer) {
            score++;
        }
    }

    printf("Your score is %d/%d\n", score, num_questions);
}

int main() {
    load_questions();
    take_exam();
    return 0;
}