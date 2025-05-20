//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26

struct question {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer[MAX_ANSWERS];
};

void display_question(struct question *q) {
    printf("%s\n", q->question);
    for (int i = 0; i < strlen(q->options[0]); i++) {
        for (int j = 0; j < strlen(q->options[0]); j++) {
            printf("%c", 'A' + j);
        }
        printf("\n");
    }
}

int main() {
    FILE *file;
    struct question questions[MAX_QUESTIONS];
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    int count = 0;
    while (fscanf(file, "%s", questions[count].question)!= EOF) {
        for (int i = 0; i < MAX_OPTIONS; i++) {
            fscanf(file, "%s", questions[count].options[i]);
        }
        fscanf(file, "%s", questions[count].answer);
        count++;
    }

    fclose(file);

    int score = 0;
    int total_questions = count;

    for (int i = 0; i < total_questions; i++) {
        char answer[MAX_ANSWERS];
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        display_question(questions + i);
        printf("Enter your answer: ");
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("\nYour final score is: %d out of %d\n", score, total_questions);

    return 0;
}