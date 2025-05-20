//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_WORDS 50

typedef struct {
    char question[MAX_WORDS];
    char options[MAX_OPTIONS][MAX_WORDS];
    char answer;
} Question;

Question exam[MAX_QUESTIONS];
int num_questions = 0;

void load_questions(char filename[]) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_WORDS];
    int i = 0, j = 0;

    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_WORDS, fp) != NULL) {
        strcpy(exam[i].question, line);

        for (j = 0; j < MAX_OPTIONS; j++) {
            exam[i].options[j][0] = '\0';
            fgets(line, MAX_WORDS, fp);
            strcpy(exam[i].options[j], line);
            exam[i].options[j][strlen(exam[i].options[j]) - 1] = '\0';
            exam[i].options[j][strlen(exam[i].options[j]) - 2] = '\0';
        }

        exam[i].answer = line[strlen(line) - 1];
        line[strlen(line) - 1] = '\0';
        num_questions++;
        i++;
    }

    fclose(fp);
}

void print_question(int question_num) {
    printf("\nQuestion %d:\n%s\n", question_num + 1, exam[question_num].question);

    int i;
    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("\n%d. %s", i + 1, exam[question_num].options[i]);
    }
}

int main() {
    char filename[] = "questions.txt";
    load_questions(filename);

    int user_answer, correct_answer;
    int num_questions_answered = 0;

    for (int i = 0; i < num_questions; i++) {
        print_question(i);

        scanf("%d", &user_answer);

        if (user_answer > MAX_OPTIONS || user_answer < 1) {
            printf("Invalid option. Try again.\n");
            i--;
            continue;
        }

        correct_answer = exam[i].answer;

        if (user_answer == correct_answer) {
            printf("Correct! Nice job.\n");
        } else {
            printf("Incorrect. The correct answer is %c.\n", exam[i].answer);
        }

        num_questions_answered++;
    }

    printf("\nYou have answered %d out of %d questions correctly.", num_questions_answered, num_questions);

    return 0;
}