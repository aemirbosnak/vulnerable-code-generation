//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTION 1000
#define MAX_OPTION 4
#define MAX_ANSWER 1000
#define MAX_USER 100

struct question {
    char question[MAX_QUESTION];
    char option[MAX_OPTION][MAX_OPTION];
    char answer[MAX_ANSWER];
};

struct user {
    char name[MAX_USER];
    int score;
};

void init_question(struct question *question) {
    strcpy(question->question, "What is the capital of France? ");
    strcpy(question->option[0], "Paris");
    strcpy(question->option[1], "London");
    strcpy(question->option[2], "Berlin");
    strcpy(question->option[3], "Madrid");
    strcpy(question->answer, "Paris");
}

void init_user(struct user *user) {
    strcpy(user->name, "John Doe");
    user->score = 0;
}

void display_question(struct question *question) {
    printf("Question: %s\n", question->question);
    for (int i = 0; i < MAX_OPTION; i++) {
        printf("Option %d: %s\n", i+1, question->option[i]);
    }
}

int get_answer(struct question *question, char *answer) {
    int correct = 0;
    for (int i = 0; i < MAX_OPTION; i++) {
        if (strcmp(question->option[i], answer) == 0) {
            correct = 1;
            break;
        }
    }
    return correct;
}

int main() {
    struct question question;
    struct user user;

    init_question(&question);
    init_user(&user);

    display_question(&question);

    char answer[MAX_ANSWER];
    printf("Enter your answer: ");
    scanf("%s", answer);

    int correct = get_answer(&question, answer);

    if (correct) {
        printf("Correct!\n");
        user.score++;
    } else {
        printf("Incorrect.\n");
    }

    printf("Your score is: %d\n", user.score);

    return 0;
}