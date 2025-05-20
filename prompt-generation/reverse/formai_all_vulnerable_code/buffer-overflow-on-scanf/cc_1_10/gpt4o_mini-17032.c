//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4
#define MAX_LEN 100

typedef struct {
    char question[MAX_LEN];
    char options[MAX_OPTIONS][MAX_LEN];
    int answer; // index for the correct option
} Question;

typedef struct {
    char username[MAX_LEN];
    int score;
} User;

User users[MAX_USERS];
Question questions[MAX_QUESTIONS];
int user_count = 0;
int question_count = 0;

void add_question() {
    if (question_count >= MAX_QUESTIONS) {
        printf("Maximum question limit reached.\n");
        return;
    }
    Question q;
    printf("Enter the question: ");
    getchar(); // to consume newline character
    fgets(q.question, MAX_LEN, stdin);
    q.question[strcspn(q.question, "\n")] = 0; // remove trailing newline
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(q.options[i], MAX_LEN, stdin);
        q.options[i][strcspn(q.options[i], "\n")] = 0; // strip newline
    }
    printf("Enter the correct option (1-%d): ", MAX_OPTIONS);
    scanf("%d", &q.answer);
    questions[question_count++] = q;
    printf("Question added successfully!\n");
}

void view_questions() {
    for (int i = 0; i < question_count; i++) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf(" %d. %s\n", j + 1, questions[i].options[j]);
        }
        printf("Correct Option: %d\n", questions[i].answer);
    }
}

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("Maximum user limit reached.\n");
        return;
    }
    printf("Enter username: ");
    getchar(); // to consume newline
    fgets(users[user_count].username, MAX_LEN, stdin);
    users[user_count].username[strcspn(users[user_count].username, "\n")] = 0; // strip newline
    users[user_count].score = 0;
    user_count++;
    printf("User registered successfully!\n");
}

void take_exam() {
    char username[MAX_LEN];
    printf("Enter your username: ");
    getchar(); // to consume newline
    fgets(username, MAX_LEN, stdin);
    username[strcspn(username, "\n")] = 0; // strip newline

    User *current_user = NULL;
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            current_user = &users[i];
            break;
        }
    }
    
    if (!current_user) {
        printf("User not found. Please register first.\n");
        return;
    }

    for (int i = 0; i < question_count; i++) {
        int user_answer;
        printf("Q%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf(" %d. %s\n", j + 1, questions[i].options[j]);
        }
        printf("Your answer (1 - %d): ", MAX_OPTIONS);
        scanf("%d", &user_answer);
        if (user_answer == questions[i].answer) {
            current_user->score++;
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer was option %d.\n", questions[i].answer);
        }
    }
    printf("Exam completed! Your score: %d out of %d\n", current_user->score, question_count);
}

void display_scores() {
    if (user_count == 0) {
        printf("No users registered yet.\n");
        return;
    }
    printf("Scores:\n");
    for (int i = 0; i < user_count; i++) {
        printf("%s: %d\n", users[i].username, users[i].score);
    }
}

void display_menu() {
    printf("\nOnline Examination System\n");
    printf("1. Add Question\n");
    printf("2. View Questions\n");
    printf("3. Register User\n");
    printf("4. Take Exam\n");
    printf("5. Display Scores\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_question();
                break;
            case 2:
                view_questions();
                break;
            case 3:
                register_user();
                break;
            case 4:
                take_exam();
                break;
            case 5:
                display_scores();
                break;
            case 6:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}