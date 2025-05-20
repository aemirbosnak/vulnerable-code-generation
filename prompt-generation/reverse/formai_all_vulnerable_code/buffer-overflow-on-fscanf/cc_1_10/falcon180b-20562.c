//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 20
#define MAX_STUDENTS 100

struct question {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer[100];
    int correct_option;
};

struct student {
    char name[100];
    int score;
};

void read_questions(struct question questions[MAX_QUESTIONS]) {
    FILE* fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening questions file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %s %d\n", questions[count].question, questions[count].options[0], questions[count].options[1], &questions[count].correct_option)!= EOF) {
        count++;
    }

    fclose(fp);
}

void read_answers(struct student students[MAX_STUDENTS], struct question questions[MAX_QUESTIONS]) {
    FILE* fp = fopen("answers.txt", "r");
    if (fp == NULL) {
        printf("Error opening answers file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %d\n", students[count].name, &students[count].score)!= EOF) {
        count++;
    }

    fclose(fp);
}

int evaluate_answer(char answer[MAX_ANSWERS], struct question question) {
    int correct = 0;
    for (int i = 0; i < question.correct_option; i++) {
        if (strcmp(answer[i], question.answer) == 0) {
            correct = 1;
            break;
        }
    }

    return correct;
}

void print_question(struct question question) {
    printf("%s\n", question.question);

    for (int i = 0; i < question.correct_option; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

void print_results(struct student students[MAX_STUDENTS], struct question questions[MAX_QUESTIONS]) {
    printf("Results:\n");

    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (students[i].score > 0) {
            printf("%s: %d/%d\n", students[i].name, students[i].score, MAX_QUESTIONS);
        }
    }
}

int main() {
    struct question questions[MAX_QUESTIONS];
    read_questions(questions);

    struct student students[MAX_STUDENTS];
    read_answers(students, questions);

    int correct_answers = 0;

    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (students[i].score > 0) {
            for (int j = 0; j < MAX_QUESTIONS; j++) {
                char answer[MAX_ANSWERS][100];
                int count = 0;

                while (count < MAX_ANSWERS && fgets(answer[count], 100, stdin)!= NULL) {
                    answer[count][strcspn(answer[count], "\n")] = '\0';
                    count++;
                }

                if (evaluate_answer(answer, questions[j]) == 1) {
                    correct_answers++;
                }
            }
        }
    }

    print_results(students, questions);

    return 0;
}