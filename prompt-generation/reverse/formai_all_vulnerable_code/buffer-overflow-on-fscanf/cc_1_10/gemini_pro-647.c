//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 100
#define MAX_ANSWERS 10

typedef struct {
    char username[20];
    char password[20];
    int score;
} user;

typedef struct {
    char question[100];
    char answers[MAX_ANSWERS][100];
    int correct_answer;
} question;

user users[MAX_USERS];
question questions[MAX_QUESTIONS];
int num_users = 0;
int num_questions = 0;

void load_users() {
    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error loading users.\n");
        return;
    }

    while (fscanf(fp, "%s %s %d\n", users[num_users].username, users[num_users].password, &users[num_users].score) != EOF) {
        num_users++;
    }

    fclose(fp);
}

void load_questions() {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error loading questions.\n");
        return;
    }

    while (fscanf(fp, "%[^\n]%*c", questions[num_questions].question) != EOF) {
        for (int i = 0; i < MAX_ANSWERS; i++) {
            fscanf(fp, "%[^\n]%*c", questions[num_questions].answers[i]);
        }
        fscanf(fp, "%d\n", &questions[num_questions].correct_answer);
        num_questions++;
    }

    fclose(fp);
}

void start_exam() {
    int user_id;
    char username[20];
    char password[20];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            user_id = i;
            break;
        }
    }

    if (user_id == -1) {
        printf("Invalid username or password.\n");
        return;
    }

    int score = 0;
    int num_correct = 0;

    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%d. %s\n", j + 1, questions[i].answers[j]);
        }

        int answer;
        printf("Answer: ");
        scanf("%d", &answer);

        if (answer == questions[i].correct_answer) {
            score += 10;
            num_correct++;
        }
    }

    printf("Your score is %d.\n", score);
    printf("You answered %d questions correctly.\n", num_correct);

    users[user_id].score += score;

    FILE *fp = fopen("users.txt", "w");
    if (fp == NULL) {
        printf("Error saving users.\n");
        return;
    }

    for (int i = 0; i < num_users; i++) {
        fprintf(fp, "%s %s %d\n", users[i].username, users[i].password, users[i].score);
    }

    fclose(fp);
}

int main() {
    load_users();
    load_questions();

    start_exam();

    return 0;
}