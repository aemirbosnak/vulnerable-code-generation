//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define USERNAME_LEN 20
#define PASSWORD_LEN 20
#define QUIZ_FILENAME "quiz.txt"
#define USER_FILENAME "users.txt"

typedef struct {
    char question[256];
    char options[4][100];
    int answer;
} Question;

typedef struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    int score;
} User;

User users[MAX_USERS];
Question questions[MAX_QUESTIONS];
int user_count = 0;
int question_count = 0;

void load_questions() {
    FILE *file = fopen(QUIZ_FILENAME, "r");
    if (file == NULL) {
        perror("Failed to open the quiz file");
        exit(EXIT_FAILURE);
    }
    while (fgets(questions[question_count].question, sizeof(questions[question_count].question), file)) {
        for (int i = 0; i < 4; i++) {
            fgets(questions[question_count].options[i], sizeof(questions[question_count].options[i]), file);
        }
        fscanf(file, "%d\n", &questions[question_count].answer);
        question_count++;
    }
    fclose(file);
}

void load_users() {
    FILE *file = fopen(USER_FILENAME, "r");
    if (file == NULL) {
        perror("Failed to open the user file");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file, "%s %s %d\n", users[user_count].username, users[user_count].password, &users[user_count].score) != EOF) {
        user_count++;
    }
    fclose(file);
}

void save_user_data() {
    FILE *file = fopen(USER_FILENAME, "w");
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%s %s %d\n", users[i].username, users[i].password, users[i].score);
    }
    fclose(file);
}

int register_user() {
    char username[USERNAME_LEN], password[PASSWORD_LEN];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists. Please try a different one.\n");
            return -1;
        }
    }

    strcpy(users[user_count].username, username);
    strcpy(users[user_count].password, password);
    users[user_count].score = 0;
    user_count++;
    save_user_data();
    printf("Registration successful!\n");
    return 0;
}

int login_user(int *current_user_index) {
    char username[USERNAME_LEN], password[PASSWORD_LEN];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            *current_user_index = i;
            return 1;
        }
    }
    printf("Invalid username or password.\n");
    return 0;
}

void take_quiz(int user_index) {
    int user_score = 0;
    for (int i = 0; i < question_count; i++) {
        printf("\nQuestion %d: %s", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s", j + 1, questions[i].options[j]);
        }
        int answer;
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        if (answer == questions[i].answer) {
            user_score++;
        }
    }
    users[user_index].score += user_score;
    save_user_data();
    printf("You scored %d out of %d.\n", user_score, question_count);
}

void display_menu() {
    printf("\nOnline Examination System\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    load_users();
    load_questions();

    int choice, current_user_index;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                if (login_user(&current_user_index)) {
                    printf("Login successful!\n");
                    take_quiz(current_user_index);
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}