//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26
#define PASS_PERCENTAGE 70

struct Question {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer[MAX_ANSWERS];
};

void loadQuestions(struct Question questions[]) {
    FILE *fp = fopen("questions.txt", "r");
    int i = 0;
    while (fscanf(fp, "%s %s %s", questions[i].question, questions[i].options[0], questions[i].options[1])!= EOF) {
        questions[i].answer[0] = tolower(questions[i].options[0][0]);
        strcat(questions[i].answer, ",");
        questions[i].answer[strlen(questions[i].answer) - 1] = '\0';
        i++;
    }
    fclose(fp);
}

int main() {
    system("clear");
    printf("Welcome to the Online Examination System\n");

    struct Question questions[MAX_QUESTIONS];
    loadQuestions(questions);

    int numQuestions = 0;
    for (int i = 0; i < MAX_QUESTIONS && questions[i].question[0]!= '\0'; i++) {
        numQuestions++;
    }

    int score = 0;
    char answer[MAX_ANSWERS];

    for (int i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS && questions[i].options[j][0]!= '\0'; j++) {
            printf("%c. %s\n", 'A' + j, questions[i].options[j]);
        }
        printf("Enter your answer: ");
        scanf("%s", answer);
        answer[strcspn(answer, ",")] = '\0';
        for (int j = 0; j < strlen(answer); j++) {
            answer[j] = tolower(answer[j]);
        }
        if (strcmp(answer, questions[i].answer) == 0) {
            score++;
        }
    }

    printf("\nYour score is %d out of %d\n", score, numQuestions);

    if ((float) score / numQuestions >= PASS_PERCENTAGE) {
        printf("Congratulations, you passed the exam!\n");
    } else {
        printf("Sorry, you failed the exam.\n");
    }

    return 0;
}