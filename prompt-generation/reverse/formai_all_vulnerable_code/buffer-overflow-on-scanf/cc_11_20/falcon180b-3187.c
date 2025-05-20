//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_questions, i, j, correct_answers = 0, total_questions;
    int user_answer, correct_answer;
    char ch;
    FILE *fp;
    struct question {
        char question[100];
        char option1[100];
        char option2[100];
        char option3[100];
        char option4[100];
        char correct_answer[3];
    } questions[100];

    printf("Welcome to the Online Examination System!\n");
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the questions and options:\n");

    for (i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i+1);
        printf("Enter the question: ");
        scanf("%s", questions[i].question);

        printf("Enter option 1: ");
        scanf("%s", questions[i].option1);

        printf("Enter option 2: ");
        scanf("%s", questions[i].option2);

        printf("Enter option 3: ");
        scanf("%s", questions[i].option3);

        printf("Enter option 4: ");
        scanf("%s", questions[i].option4);

        printf("Enter the correct answer (A/B/C/D): ");
        scanf("%s", questions[i].correct_answer);
    }

    fp = fopen("questions.txt", "w");

    for (i = 0; i < num_questions; i++) {
        fprintf(fp, "Question %d:\n%s\n", i+1, questions[i].question);

        for (j = 0; j < 4; j++) {
            fprintf(fp, "%c. %s\n", 'A'+j, questions[i].option1);
        }

        fprintf(fp, "Correct Answer: %s\n\n", questions[i].correct_answer);
    }

    fclose(fp);

    printf("Questions saved to questions.txt\n");

    fp = fopen("questions.txt", "r");

    total_questions = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            total_questions++;
        }
    }

    rewind(fp);

    printf("Total questions: %d\n", total_questions);

    for (i = 0; i < total_questions; i++) {
        fscanf(fp, "%s", questions[i].question);

        for (j = 0; j < 4; j++) {
            fscanf(fp, "%s", questions[i].option1);
        }

        fscanf(fp, "%s", questions[i].correct_answer);
    }

    fclose(fp);

    printf("Examination starts...\n");

    for (i = 0; i < num_questions; i++) {
        printf("Question %d:\n%s\n", i+1, questions[i].question);

        for (j = 0; j < 4; j++) {
            printf("%c. %s\n", 'A'+j, questions[i].option1);
        }

        printf("Enter your answer (A/B/C/D): ");
        scanf("%s", user_answer);

        if (strcmp(user_answer, questions[i].correct_answer) == 0) {
            correct_answers++;
        }
    }

    printf("Examination ends...\n");

    printf("You got %d out of %d questions correct.\n", correct_answers, num_questions);

    return 0;
}