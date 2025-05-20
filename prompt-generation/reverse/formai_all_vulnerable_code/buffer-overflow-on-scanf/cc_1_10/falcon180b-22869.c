//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTION 100
#define MAX_ANSWER 100
#define MAX_USER 100
#define MAX_NAME_LEN 100

struct question {
    char q[MAX_QUESTION];
    char a[MAX_ANSWER];
    int score;
};

struct user {
    char name[MAX_NAME_LEN];
    int score;
};

int main() {
    int num_question;
    int num_user;
    int i, j;
    int correct_ans = 0;
    int total_ans = 0;
    int max_score = 0;
    int user_score[MAX_USER];
    char ans[MAX_USER][MAX_ANSWER];
    struct question questions[MAX_QUESTION];
    struct user users[MAX_USER];

    // read number of questions
    printf("Enter number of questions: ");
    scanf("%d", &num_question);

    // read questions
    for (i = 0; i < num_question; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].q);
        printf("Enter answer %d: ", i+1);
        scanf("%s", questions[i].a);
        questions[i].score = 1;
    }

    // read number of users
    printf("Enter number of users: ");
    scanf("%d", &num_user);

    // read user names
    for (i = 0; i < num_user; i++) {
        printf("Enter user name %d: ", i+1);
        scanf("%s", users[i].name);
        users[i].score = 0;
    }

    // start exam
    printf("Exam started...\n");
    for (i = 0; i < num_question; i++) {
        printf("Question %d: %s\n", i+1, questions[i].q);
        for (j = 0; j < num_user; j++) {
            printf("User %d, enter your answer: ", j+1);
            scanf("%s", ans[j]);
            if (strcmp(ans[j], questions[i].a) == 0) {
                correct_ans++;
                users[j].score++;
            }
        }
        total_ans += num_user;
        if (correct_ans > 0) {
            printf("Correct answer: %s\n", questions[i].a);
        } else {
            printf("Incorrect answer\n");
        }
    }

    // end exam
    printf("Exam ended...\n");
    for (i = 0; i < num_user; i++) {
        printf("User %d score: %d\n", i+1, users[i].score);
    }

    return 0;
}