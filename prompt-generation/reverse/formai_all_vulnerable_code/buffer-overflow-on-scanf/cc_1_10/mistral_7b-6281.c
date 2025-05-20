//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 10

typedef struct {
    char question[MAX_NAME_LENGTH];
    char options[MAX_OPTIONS][MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} Question;

Question questions[MAX_QUESTIONS];
int num_questions = 0;

void display_question() {
    int i;
    char choice;

    if (num_questions == 0) {
        printf("No questions available.\n");
        return;
    }

    printf("\nQuestion %d:\n", num_questions + 1);
    printf("%s\n", questions[num_questions - 1].question);

    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[num_questions - 1].options[i]);
    }

    printf("\nEnter your choice (1-5): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_OPTIONS) {
        printf("Invalid choice. Please try again.\n");
        display_question();
        return;
    }

    if (strcmp(questions[num_questions - 1].answer, questions[num_questions - 1].options[choice - 1]) != 0) {
        printf("Incorrect answer. Try again.\n");
        display_question();
        return;
    }

    printf("Correct answer! Moving on to the next question.\n");
    num_questions--;
}

void add_question() {
    int i;

    if (num_questions >= MAX_QUESTIONS) {
        printf("Maximum number of questions reached.\n");
        return;
    }

    printf("Enter the question: ");
    scanf("%s", questions[num_questions].question);

    printf("Enter the options (one per line):\n");
    for (i = 0; i < MAX_OPTIONS; i++) {
        scanf("%s", questions[num_questions].options[i]);
    }

    printf("Enter the answer: ");
    scanf("%s", questions[num_questions].answer);

    num_questions++;
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add question\n2. Start Exam\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_question();
                break;
            case 2:
                if (num_questions == 0) {
                    printf("No questions available.\n");
                    break;
                }
                display_question();
                break;
            case 3:
                printf("Exam system closed.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}