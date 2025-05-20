//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS    100
#define MAX_QUESTIONS 10
#define MAX_OPTIONS   4
#define FILENAME      "users.txt"

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][100];
    int answer; // Index of the correct option
} Question;

typedef struct {
    char username[50];
    char password[50];
    int score;
} User;

Question questions[MAX_QUESTIONS];
User users[MAX_USERS];
int user_count = 0, question_count = 0;

void load_questions() {
    // Sample questions. In a real system, these could be loaded from a file.
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "Berlin");
    strcpy(questions[0].options[1], "Madrid");
    strcpy(questions[0].options[2], "Paris");
    strcpy(questions[0].options[3], "Rome");
    questions[0].answer = 2;

    strcpy(questions[1].question, "What is 2 + 2?");
    strcpy(questions[1].options[0], "3");
    strcpy(questions[1].options[1], "4");
    strcpy(questions[1].options[2], "5");
    strcpy(questions[1].options[3], "6");
    questions[1].answer = 1;

    question_count = 2; // Update the count based on loaded questions
}

void register_user() {
    User new_user;
    printf("Enter username: ");
    scanf("%s", new_user.username);
    printf("Enter password: ");
    scanf("%s", new_user.password);
    new_user.score = 0;

    // Check if user already exists
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, new_user.username) == 0) {
            printf("Username already exists! Try a different one.\n");
            return;
        }
    }

    // Save the user
    users[user_count++] = new_user;
    FILE *file = fopen(FILENAME, "a");
    fprintf(file, "%s %s %d\n", new_user.username, new_user.password, new_user.score);
    fclose(file);
    printf("Registration successful!\n");
}

void login() {
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful! Welcome, %s.\n", username);
            return;
        }
    }
    printf("Invalid username or password!\n");
}

void take_exam() {
    int score = 0;
    printf("\nStarting exam...\n");

    for (int i = 0; i < question_count; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        int answer;
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);

        if (answer - 1 == questions[i].answer) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer was %s.\n", questions[i].options[questions[i].answer]);
        }
    }
    printf("Your score: %d/%d\n", score, question_count);
}

void load_users() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No user data found. Please register.\n");
        return;
    }

    while (fscanf(file, "%s %s %d", users[user_count].username, users[user_count].password, &users[user_count].score) != EOF) {
        user_count++;
    }
    fclose(file);
}

int main() {
    load_users();
    load_questions();
    int choice;

    do {
        printf("\n1. Register\n2. Login\n3. Take Exam\n4. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                login();
                break;
            case 3:
                take_exam();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}