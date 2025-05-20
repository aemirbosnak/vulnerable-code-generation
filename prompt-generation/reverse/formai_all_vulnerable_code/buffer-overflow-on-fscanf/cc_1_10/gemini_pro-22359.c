//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4

typedef struct {
    int question_id;
    char question_text[256];
    char options[MAX_OPTIONS][64];
    int correct_answer;
} Question;

Question questions[MAX_QUESTIONS];
int num_questions = 0;

void load_questions() {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening questions file.\n");
        exit(1);
    }

    while (!feof(fp)) {
        Question question;
        fscanf(fp, "%d %[^\n]\n", &question.question_id, question.question_text);
        for (int i = 0; i < MAX_OPTIONS; i++) {
            fscanf(fp, "%s", question.options[i]);
        }
        fscanf(fp, "%d", &question.correct_answer);
        questions[num_questions++] = question;
    }

    fclose(fp);
}

void take_test() {
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        Question question = questions[i];
        printf("%d. %s\n", question.question_id, question.question_text);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%c. %s\n", 'A' + j, question.options[j]);
        }
        int answer;
        scanf("%d", &answer);
        if (answer == question.correct_answer) {
            score++;
        }
    }

    printf("Your score is %d out of %d.\n", score, num_questions);
}

int main() {
    load_questions();
    take_test();
    return 0;
}