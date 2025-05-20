//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_CHAR 256
#define MAX_LINE 1024

typedef struct {
    char question[MAX_CHAR];
    char options[MAX_OPTIONS][MAX_CHAR];
    char answer;
} Question;

Question quiz[MAX_QUESTIONS];
int current_question = 0;
int score = 0;

void generate_quiz() {
    FILE *fp;
    char filename[MAX_CHAR];
    char line[MAX_LINE];

    printf("Enter filename of question file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)) {
        sscanf(line, "%s %s %s %s %s %s %s %s",
            quiz[current_question].question,
            quiz[current_question].options[0],
            quiz[current_question].options[1],
            quiz[current_question].options[2],
            quiz[current_question].options[3],
            quiz[current_question].options[4],
            &quiz[current_question].answer,
            NULL);

        for (int i = 0; i < 5; i++) {
            quiz[current_question].options[i][0] = toupper(quiz[current_question].options[i][0]);
            quiz[current_question].options[i][strlen(quiz[current_question].options[i]) - 1] = '\0';
        }

        current_question++;
    }

    fclose(fp);
}

void display_question() {
    int choice;

    printf("\n%d. %s\n", current_question + 1, quiz[current_question].question);

    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, quiz[current_question].options[i]);
    }

    printf("\nEnter your answer (1 to 5): ");
    scanf("%d", &choice);

    if (choice == quiz[current_question].answer + '0') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer was %c.\n", quiz[current_question].answer);
    }
}

void start_exam() {
    int num_questions;

    printf("Enter number of questions: ");
    scanf("%d", &num_questions);

    if (num_questions > MAX_QUESTIONS) {
        printf("Error: maximum number of questions is %d.\n", MAX_QUESTIONS);
        exit(1);
    }

    generate_quiz();

    for (int i = 0; i < num_questions; i++) {
        display_question();
    }

    printf("\nYour score is %d out of %d.\n", score, num_questions);
}

int main() {
    srand(time(NULL));

    printf("Welcome to the C Online Examination System!\n");
    start_exam();

    return 0;
}