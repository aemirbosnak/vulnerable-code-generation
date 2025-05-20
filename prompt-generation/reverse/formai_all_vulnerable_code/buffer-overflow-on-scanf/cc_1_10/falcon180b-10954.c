//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_ANSWER_LEN 100

struct question {
    char question[MAX_ANSWER_LEN];
    char options[MAX_OPTIONS][MAX_ANSWER_LEN];
    int correct_option;
};

struct user_data {
    char name[MAX_ANSWER_LEN];
    int score;
};

void generate_question(struct question *q) {
    char *questions[] = {
        "What is the capital of France? ",
        "What is the largest organ in the human body? ",
        "What is the smallest country in the world? ",
        "What is the tallest mountain in the world? ",
        "What is the currency of Japan? ",
        "What is the largest desert in the world? ",
        "What is the largest ocean in the world? ",
        "What is the highest waterfall in the world? ",
        "What is the longest river in the world? ",
        "What is the largest island in the world?"
    };
    int i = rand() % 10;
    strcpy(q->question, questions[i]);
    int j;
    for (j = 0; j < MAX_OPTIONS; j++) {
        strcpy(q->options[j], "");
    }
    int correct_option = rand() % MAX_OPTIONS;
    strcpy(q->options[correct_option], questions[i]);
}

int main() {
    struct question q;
    struct user_data user;
    int i, j, correct_answers = 0;
    printf("Enter your name: ");
    scanf("%s", user.name);
    printf("Welcome, %s! \n", user.name);
    for (i = 0; i < MAX_QUESTIONS; i++) {
        generate_question(&q);
        printf("\n%s\n", q.question);
        int k = 0;
        for (j = 0; j < MAX_OPTIONS; j++) {
            if (q.options[j][0]!= '\0') {
                printf("%d. %s\n", j + 1, q.options[j]);
                k++;
            }
        }
        printf("\n");
        int user_ans;
        scanf("%d", &user_ans);
        if (user_ans == q.correct_option + 1) {
            correct_answers++;
        }
    }
    printf("Congratulations, %s! \n", user.name);
    printf("%d out of %d questions answered correctly. \n", correct_answers, MAX_QUESTIONS);
    return 0;
}