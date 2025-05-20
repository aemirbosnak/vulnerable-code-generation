//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 20

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS];

void readQuestions() {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        return;
    }

    int i = 0;
    while (fscanf(fp, "%s %s %d", questions[i].question, questions[i].answer, &questions[i].marks) != EOF) {
        i++;
    }

    fclose(fp);
}

int main() {
    readQuestions();

    printf("Welcome to the Online Examination System!\n");
    printf("Please select a question below:\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
    }

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice > MAX_QUESTIONS || choice <= 0) {
        printf("Invalid choice.\n");
    } else {
        printf("Your answer: %s\n", questions[choice - 1].answer);
        printf("Marks: %d\n", questions[choice - 1].marks);
    }

    return 0;
}