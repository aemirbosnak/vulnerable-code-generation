//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define MAX_OPTIONS 5
#define MAX_LENGTH 100

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    int correct_option; // index of the correct option (0-based)
} Question;

typedef struct {
    char name[MAX_LENGTH];
    int id;
    int score;
} User;

Question questions[MAX_QUESTIONS];
User users[MAX_USERS];
int num_questions = 0;
int num_users = 0;

void add_question() {
    if (num_questions >= MAX_QUESTIONS) {
        printf("Question limit reached. Cannot add more questions.\n");
        return;
    }
    printf("Enter the question: ");
    getchar(); // to consume newline character
    fgets(questions[num_questions].question, MAX_LENGTH, stdin);
    questions[num_questions].question[strcspn(questions[num_questions].question, "\n")] = 0; // remove newline

    printf("Enter the number of options: ");
    int num_options;
    scanf("%d", &num_options);
    if (num_options < 2 || num_options > MAX_OPTIONS) {
        printf("Number of options should be between 2 and %d.\n", MAX_OPTIONS);
        return;
    }

    for (int i = 0; i < num_options; i++) {
        printf("Enter option %d: ", i + 1);
        getchar(); // to consume newline character
        fgets(questions[num_questions].options[i], MAX_LENGTH, stdin);
        questions[num_questions].options[i][strcspn(questions[num_questions].options[i], "\n")] = 0; // remove newline
    }

    printf("Enter the correct option number (1-%d): ", num_options);
    scanf("%d", &questions[num_questions].correct_option);
    questions[num_questions].correct_option--; // convert to 0-based index

    num_questions++;
    printf("Question added successfully!\n\n");
}

void register_user() {
    if (num_users >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }
    printf("Enter your name: ");
    getchar(); // to consume newline character
    fgets(users[num_users].name, MAX_LENGTH, stdin);
    users[num_users].name[strcspn(users[num_users].name, "\n")] = 0; // remove newline
    users[num_users].id = num_users + 1; // simple user ID
    users[num_users].score = 0;

    num_users++;
    printf("User registered successfully! Your ID is %d.\n\n", users[num_users - 1].id);
}

void take_exam() {
    int user_id;
    printf("Enter your user ID: ");
    scanf("%d", &user_id);
    if (user_id < 1 || user_id > num_users) {
        printf("Invalid user ID.\n");
        return;
    }

    User *current_user = &users[user_id - 1];
    current_user->score = 0;

    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS && questions[i].options[j][0]; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }

        int answer;
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);
        answer--; // convert to 0-based index

        if (answer == questions[i].correct_option) {
            printf("Correct!\n\n");
            current_user->score++;
        } else {
            printf("Incorrect! The correct answer was option %d.\n\n", questions[i].correct_option + 1);
        }
    }

    printf("Exam finished! Your score: %d out of %d.\n", current_user->score, num_questions);
}

void display_users() {
    printf("Registered Users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("ID: %d, Name: %s, Score: %d\n", users[i].id, users[i].name, users[i].score);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("=== Online Examination System ===\n");
        printf("1. Add Question\n");
        printf("2. Register User\n");
        printf("3. Take Exam\n");
        printf("4. Display Users\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_question();
                break;
            case 2:
                register_user();
                break;
            case 3:
                take_exam();
                break;
            case 4:
                display_users();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    return 0;
}