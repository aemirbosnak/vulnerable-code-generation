//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26
#define PASS_MARK 60

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer[MAX_ANSWERS];
} Question;

int main() {
    int num_questions, i, j, score = 0;
    char choice;
    Question questions[MAX_QUESTIONS];

    printf("Welcome to the Online Examination System!\n");
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    // Read questions from file
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open questions file.\n");
        exit(1);
    }

    for (i = 0; i < num_questions; i++) {
        fscanf(fp, "%s", questions[i].question);
        for (j = 0; j < MAX_OPTIONS; j++) {
            fscanf(fp, "%s", questions[i].options[j]);
        }
        fscanf(fp, "%s", questions[i].answer);
    }

    fclose(fp);

    // Start exam
    printf("\nExam started...\n");
    for (i = 0; i < num_questions; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);
        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%c. %s\n", (char)(65+j), questions[i].options[j]);
        }
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        if (choice >= 'A' && choice <= 'Z') {
            if (choice == questions[i].answer[0]) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect...\n");
            }
        } else {
            printf("Invalid choice...\n");
        }
    }

    // End exam
    printf("\nExam ended.\n");
    printf("Your score is: %d out of %d\n", score, num_questions);

    if (score >= (num_questions * PASS_MARK) / 100) {
        printf("Congratulations! You passed the exam.\n");
    } else {
        printf("Sorry, you did not pass the exam.\n");
    }

    return 0;
}