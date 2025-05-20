//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 100
#define MAX_USERNAME_LENGTH 100

typedef struct {
    char question[MAX_QUESTIONS];
    char options[MAX_QUESTIONS][MAX_OPTIONS][MAX_ANSWER_LENGTH];
    char answer[MAX_QUESTIONS];
} Question;

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    int score;
} User;

void read_questions(Question *questions) {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: questions.txt not found.\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(fp, "%s", questions[i].question)!= EOF) {
        int j = 0;
        while (j < MAX_OPTIONS && fscanf(fp, "%s", questions[i].options[j])!= EOF) {
            j++;
        }
        fscanf(fp, "%s", questions[i].answer);
        i++;
    }
    fclose(fp);
}

void print_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

int evaluate_answer(Question question, char *user_answer) {
    for (int i = 0; i < MAX_OPTIONS; i++) {
        if (strcmp(user_answer, question.options[i]) == 0) {
            return i + 1;
        }
    }
    return 0;
}

void take_exam(User *user, Question questions[]) {
    printf("Welcome, %s!\n", user->username);
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        print_question(questions[i]);
        char answer[MAX_ANSWER_LENGTH];
        fgets(answer, MAX_ANSWER_LENGTH, stdin);
        int correct_answer = evaluate_answer(questions[i], answer);
        if (correct_answer > 0) {
            user->score++;
        }
    }
    printf("Your score is %d out of %d.\n", user->score, MAX_QUESTIONS);
}

int main() {
    Question questions[MAX_QUESTIONS];
    read_questions(questions);
    User user;
    strcpy(user.username, "John Doe");
    take_exam(&user, questions);
    return 0;
}