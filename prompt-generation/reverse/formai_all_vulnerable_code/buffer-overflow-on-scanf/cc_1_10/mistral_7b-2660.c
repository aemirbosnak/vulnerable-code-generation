//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_NAME_LEN 50
#define MAX_ANSWERS 1

typedef struct Question {
    char question[100];
    char options[MAX_OPTIONS][50];
    char answer[MAX_ANSWERS][MAX_OPTIONS][50];
} Question;

Question exam[MAX_QUESTIONS];
int num_questions = 0;
int current_question = 0;

void print_question() {
    printf("\n%s\n", exam[current_question].question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("\n%d. %s", i+1, exam[current_question].options[i]);
    }
}

int get_answer() {
    int choice;
    scanf("%d", &choice);

    while (choice < 1 || choice > MAX_OPTIONS) {
        printf("Invalid choice! Please enter a valid choice.\n");
        scanf("%d", &choice);
    }

    return choice - 1;
}

void next_question() {
    current_question++;

    if (current_question >= num_questions) {
        printf("\nExam completed! Results will be displayed soon.\n");
        exit(0);
    }
}

int main() {
    char filename[MAX_NAME_LEN];

    printf("Enter the name of the exam file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fscanf(fp, "%[^:]:%[^\n]\n", exam[num_questions].question, exam[num_questions].options[0]) != EOF) {
        num_questions++;

        for (int i = 1; i < MAX_OPTIONS; i++) {
            fscanf(fp, "%[^\n]\n", exam[num_questions].options[i]);
        }

        for (int i = 0; i < MAX_ANSWERS; i++) {
            fscanf(fp, "%s", exam[num_questions].answer[i]);
        }
    }

    fclose(fp);

    print_question();
    int answer = get_answer();

    strcpy(exam[current_question].answer[current_question % MAX_ANSWERS], "");
    strcpy(exam[current_question].answer[current_question % MAX_ANSWERS], exam[current_question].options[answer]);

    next_question();

    return 0;
}