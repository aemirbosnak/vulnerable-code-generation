//FormAI DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Q_LEN 256
#define MAX_A_LEN 64
#define MAX_Q_NUM 20

void load_questions(char fname[], char questions[][MAX_Q_LEN], char answers[][MAX_A_LEN], int* num_questions) {
    FILE* f = fopen(fname, "r");
    if (f == NULL) {
        printf("Error loading questions file!\n");
        exit(1);
    }
    char ch, q[MAX_Q_LEN], a[MAX_A_LEN];
    int i = 0, q_num = 0;
    while ((ch = getc(f)) != EOF) {
        if (ch == '\t') {
            q[i] = '\0';
            i = 0;
        } else if (ch == '\n') {
            a[i] = '\0';
            i = 0;
            strcpy(questions[q_num], q);
            strcpy(answers[q_num], a);
            q_num++;
        } else {
            if (i < MAX_Q_LEN && q_num < MAX_Q_NUM) {
                if (i == 0) {
                    memset(q, 0, MAX_Q_LEN);
                    memset(a, 0, MAX_A_LEN);
                }
                if (i < MAX_A_LEN) {
                    if (ch != '\r') {
                        if (i == 0) {
                            ch = (ch >= 'a' && ch <= 'z') ? (ch - ('a' - 'A')) : ch;
                        }
                        if (i > 0) {
                            ch = (ch >= 'A' && ch <= 'Z') ? (ch + ('a' - 'A')) : ch;
                        }
                        a[i] = ch;
                    }
                }
                q[i] = ch;
                i++;
            }
        }
    }
    fclose(f);
    *num_questions = q_num;
}

void shuffle_questions(char questions[][MAX_Q_LEN], char answers[][MAX_A_LEN], int num_questions) {
    srand(time(NULL));
    for (int i = 0; i < num_questions; i++) {
        int j = rand() % num_questions;
        if (i != j) {
            char tmp[MAX_Q_LEN];
            strcpy(tmp, questions[i]);
            strcpy(questions[i], questions[j]);
            strcpy(questions[j], tmp);
            strcpy(tmp, answers[i]);
            strcpy(answers[i], answers[j]);
            strcpy(answers[j], tmp);
        }
    }
}

int main() {
    char qfile[] = "quiz_questions.txt";
    char questions[MAX_Q_NUM][MAX_Q_LEN];
    char answers[MAX_Q_NUM][MAX_A_LEN];
    int num_questions = 0;
    load_questions(qfile, questions, answers, &num_questions);
    printf("Welcome to the Quiz Game!\n");
    printf("Press ENTER to start the game...");
    getchar();
    shuffle_questions(questions, answers, num_questions);
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion #%d: %s\n", i+1, questions[i]);
        printf("Your answer: ");
        char user_answer[MAX_A_LEN];
        fgets(user_answer, MAX_A_LEN, stdin);
        user_answer[strlen(user_answer)-1] = '\0';
        if (strcmp(user_answer, answers[i]) == 0) {
            printf("Correct! You get 1 point.\n");
            score++;
        } else {
            printf("Sorry, the correct answer is %s.\n", answers[i]);
        }
    }
    printf("\nCongratulations, you finished the game! Your final score is %d/%d.\n", score, num_questions);
    return 0;
}