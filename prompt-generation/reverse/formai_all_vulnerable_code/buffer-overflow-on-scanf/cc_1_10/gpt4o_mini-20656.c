//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 10
#define MAX_QUESTIONS 5
#define MAX_ANSWER_LENGTH 100
#define MAX_USERNAME 20
#define MAX_PASSWORD 20
#define MAX_LOG_LENGTH 256

typedef struct {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
} User;

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char options[4][MAX_ANSWER_LENGTH];
    int correct_option_index;
} Question;

User users[MAX_USERS];
Question questions[MAX_QUESTIONS];

FILE *logFile;

void log_event(const char *event) {
    if (logFile == NULL) {
        logFile = fopen("exam_log.txt", "a");
        if (logFile == NULL) {
            fprintf(stderr, "Could not open log file!\n");
            exit(1);
        }
    }
    time_t now = time(NULL);
    fprintf(logFile, "[%s] %s\n", ctime(&now), event);
    fflush(logFile);
}

void setup_users() {
    for (int i = 0; i < MAX_USERS; i++) {
        snprintf(users[i].username, MAX_USERNAME, "user%d", i + 1);
        snprintf(users[i].password, MAX_PASSWORD, "pass%d", i + 1);
    }
}

void setup_questions() {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        snprintf(questions[i].question, MAX_ANSWER_LENGTH, "Question %d: What is %d + %d?", i + 1, i + 1, i + 2);
        snprintf(questions[i].options[0], MAX_ANSWER_LENGTH, "%d", (i + 1) + (i + 2));
        snprintf(questions[i].options[1], MAX_ANSWER_LENGTH, "%d", (i + 1) + (i + 2) + 1);
        snprintf(questions[i].options[2], MAX_ANSWER_LENGTH, "%d", (i + 1) + (i + 2) - 1);
        snprintf(questions[i].options[3], MAX_ANSWER_LENGTH, "Invalid Option");
        questions[i].correct_option_index = 0; // Correct answer is at index 0
    }
}

int authenticate_user(const char *username, const char *password) {
    log_event("Beginning authentication process.");
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            log_event("Authentication successful.");
            return 1;
        }
    }
    log_event("Authentication failed.");
    return 0;
}

void conduct_exam() {
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d: %s\n", j + 1, questions[i].options[j]);
        }
        int user_answer;
        printf("Your answer (1-4): ");
        if (scanf("%d", &user_answer) != 1 || user_answer < 1 || user_answer > 4) {
            printf("Invalid answer. Terminating examination.\n");
            log_event("Examination terminated due to invalid answer.");
            return;
        }
        if (user_answer - 1 == questions[i].correct_option_index) {
            score++;
        }
        log_event("User answered question.");
    }
    printf("Your final score: %d/%d\n", score, MAX_QUESTIONS);
    log_event("Examination completed.");
}

int main() {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];

    setup_users();
    setup_questions();

    printf("Welcome to the Online Examination System. Enter your credentials.\n");
    
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    
    if (authenticate_user(username, password)) {
        conduct_exam();
    } else {
        printf("Authentication failed! Exiting...\n");
    }

    if (logFile != NULL) {
        fclose(logFile);
    }
    return 0;
}