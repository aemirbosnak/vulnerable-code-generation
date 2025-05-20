//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26
#define PASS_PERCENTAGE 60

struct Question {
    char question[100];
    char options[MAX_OPTIONS][50];
    char answer[MAX_ANSWERS];
};

void display_question(struct Question question) {
    printf("\n%s\n", question.question);
    int i;
    for (i = 0; i < MAX_OPTIONS; i++) {
        if (question.options[i][0]!= '\0') {
            printf("%c. %s\n", 'A' + i, question.options[i]);
        }
    }
}

int check_answer(char answer[], char correct_answer[]) {
    int i, j;
    for (i = 0; i < strlen(answer); i++) {
        if (answer[i]!= correct_answer[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    FILE *fp;
    char filename[50];
    printf("Enter the name of the question file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    struct Question questions[MAX_QUESTIONS];
    int num_questions = 0;
    while (fscanf(fp, "%s", questions[num_questions].question)!= EOF) {
        int i;
        for (i = 0; i < MAX_OPTIONS; i++) {
            fscanf(fp, "%s", questions[num_questions].options[i]);
            if (questions[num_questions].options[i][0] == '\0') {
                break;
            }
        }
        fscanf(fp, "%s", questions[num_questions].answer);
        num_questions++;
    }
    fclose(fp);
    int score = 0;
    int i;
    for (i = 0; i < num_questions; i++) {
        display_question(questions[i]);
        char answer[MAX_ANSWERS];
        scanf("%s", answer);
        if (check_answer(answer, questions[i].answer)) {
            score++;
        }
    }
    printf("\nYour score is %d out of %d.\n", score, num_questions);
    if (score >= (num_questions * PASS_PERCENTAGE) / 100) {
        printf("Congratulations! You passed the exam.\n");
    } else {
        printf("Sorry, you failed the exam.\n");
    }
    return 0;
}