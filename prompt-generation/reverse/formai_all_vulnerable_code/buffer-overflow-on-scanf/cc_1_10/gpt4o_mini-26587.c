//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_QUESTIONS 5
#define MAX_OPTION_LENGTH 50

typedef struct {
    char question[256];
    char options[4][MAX_OPTION_LENGTH];
    int correct_option;
} Question;

typedef struct {
    char username[100];
    int score;
} User;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", {"1. Berlin", "2. Madrid", "3. Paris", "4. Rome"}, 2},
    {"How many continents are there?", {"1. Six", "2. Seven", "3. Eight", "4. Five"}, 1},
    {"What is 2 + 2?", {"1. 3", "2. 4", "3. 5", "4. 6"}, 1},
    {"Which planet is known as the Red Planet?", {"1. Earth", "2. Mars", "3. Jupiter", "4. Saturn"}, 1},
    {"What is the largest ocean on Earth?", {"1. Atlantic Ocean", "2. Indian Ocean", "3. Arctic Ocean", "4. Pacific Ocean"}, 3}
};

User users[MAX_USERS];
int user_count = 0;

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached! Cannot register more users.\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[user_count].username);
    users[user_count].score = 0;
    user_count++;
    printf("User %s registered successfully!\n", users[user_count - 1].username);
}

void take_exam(const char* username) {
    printf("%s, you are now taking the exam.\n", username);
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }

        printf("Choose the correct option (1-4): ");
        int answer;
        scanf("%d", &answer);
        if (answer - 1 == questions[i].correct_option) {
            printf("Correct!\n");
            for (int k = 0; k < user_count; k++) {
                if (strcmp(users[k].username, username) == 0) {
                    users[k].score++;
                }
            }
        } else {
            printf("Wrong answer! The correct answer was %d. %s\n", questions[i].correct_option + 1, questions[i].options[questions[i].correct_option]);
        }
    }
}

void display_results() {
    printf("\n--- Exam Results ---\n");
    for (int i = 0; i < user_count; i++) {
        printf("Username: %s, Score: %d out of %d\n", users[i].username, users[i].score, MAX_QUESTIONS);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Online Examination System ---\n");
        printf("1. Register User\n");
        printf("2. Take Exam\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2: {
                char username[100];
                printf("Enter your username to take the exam: ");
                scanf("%s", username);
                int found = 0;
                for (int i = 0; i < user_count; i++) {
                    if (strcmp(users[i].username, username) == 0) {
                        take_exam(username);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("User not found! Please register first.\n");
                }
                break;
            }
            case 3:
                display_results();
                break;
            case 4:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}