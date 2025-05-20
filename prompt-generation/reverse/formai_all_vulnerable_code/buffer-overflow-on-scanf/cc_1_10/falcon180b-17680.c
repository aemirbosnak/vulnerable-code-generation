//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWER_LENGTH 100
#define MAX_USERNAME_LENGTH 30
#define MAX_PASSWORD_LENGTH 30
#define MIN_PASSWORD_LENGTH 8
#define MIN_USERNAME_LENGTH 4

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int score;
} User;

typedef struct {
    char question[MAX_QUESTIONS][MAX_ANSWER_LENGTH];
    char answer[MAX_QUESTIONS][MAX_ANSWER_LENGTH];
    int correct_answers[MAX_QUESTIONS];
} Exam;

void generate_exam(Exam* exam) {
    int i;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        srand(time(NULL));
        int question_length = rand() % 10 + 1;
        char question[question_length];
        snprintf(question, question_length, "Question %d: ", i + 1);
        strcat(question, "What is the answer?");
        strcpy(exam->question[i], question);
        exam->correct_answers[i] = rand() % 4;
        strcpy(exam->answer[i], "Answer A");
        strcat(exam->answer[i], " ");
        switch (exam->correct_answers[i]) {
            case 0:
                strcat(exam->answer[i], "Answer A");
                break;
            case 1:
                strcat(exam->answer[i], "Answer B");
                break;
            case 2:
                strcat(exam->answer[i], "Answer C");
                break;
            case 3:
                strcat(exam->answer[i], "Answer D");
                break;
        }
    }
}

void register_user(User* user) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a username (between %d and %d characters): ", MIN_USERNAME_LENGTH, MAX_USERNAME_LENGTH);
    scanf("%s", username);
    printf("Enter a password (between %d and %d characters): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%s", password);
    strcpy(user->username, username);
    strcpy(user->password, password);
    user->score = 0;
}

int login(User* user, char* username, char* password) {
    if (strcmp(user->username, username) == 0 && strcmp(user->password, password) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void take_exam(Exam* exam, User* user) {
    int i;
    int correct_answers = 0;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", exam->question[i]);
        printf("A: %s\n", exam->answer[i]);
        char answer[MAX_ANSWER_LENGTH];
        scanf("%s", answer);
        if (strcmp(answer, exam->answer[i]) == 0) {
            correct_answers++;
        }
    }
    user->score += correct_answers;
}

int main() {
    Exam exam;
    User user;
    register_user(&user);
    generate_exam(&exam);
    take_exam(&exam, &user);
    printf("Your score is: %d\n", user.score);
    return 0;
}