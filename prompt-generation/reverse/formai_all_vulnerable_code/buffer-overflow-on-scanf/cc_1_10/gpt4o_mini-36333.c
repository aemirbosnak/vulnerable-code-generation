//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_USERS 50
#define NAME_LENGTH 50

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][256];
    int correct_option;  // Index of the correct option
} Question;

typedef struct {
    char name[NAME_LENGTH];
    int score;
} User;

Question questions[MAX_QUESTIONS];
User users[MAX_USERS];
int question_count = 0;
int user_count = 0;

void add_question() {
    if (question_count >= MAX_QUESTIONS) {
        printf("Question limit reached.\n");
        return;
    }
    
    printf("Enter the question: ");
    getchar();  // consume newline character from previous input
    fgets(questions[question_count].question, sizeof(questions[question_count].question), stdin);
    questions[question_count].question[strcspn(questions[question_count].question, "\n")] = 0;  // Remove newline
    
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(questions[question_count].options[i], sizeof(questions[question_count].options[i]), stdin);
        questions[question_count].options[i][strcspn(questions[question_count].options[i], "\n")] = 0;  // Remove newline
    }
    
    printf("Enter the correct option number (1-%d): ", MAX_OPTIONS);
    scanf("%d", &questions[question_count].correct_option);
    question_count++;
    printf("Question added successfully!\n");
}

void take_exam(User* user) {
    user->score = 0;
    
    for (int i = 0; i < question_count; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        
        int answer;
        printf("Your answer: ");
        scanf("%d", &answer);
        
        if (answer == questions[i].correct_option) {
            user->score++;
        }
    }
    
    printf("You've completed the exam, %s! Your score: %d/%d\n", user->name, user->score, question_count);
}

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }
    
    printf("Enter your name: ");
    getchar();  // consume newline character
    fgets(users[user_count].name, sizeof(users[user_count].name), stdin);
    users[user_count].name[strcspn(users[user_count].name, "\n")] = 0;  // Remove newline
    user_count++;
    printf("User %s registered successfully!\n", users[user_count - 1].name);
}

void display_menu() {
    printf("\nOnline Examination System\n");
    printf("1. Add Question\n");
    printf("2. Register User\n");
    printf("3. Take Exam\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;
    
    while (1) {
        display_menu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_question();
                break;
            case 2:
                register_user();
                break;
            case 3:
                if (user_count == 0) {
                    printf("No users registered yet.\n");
                } else {
                    printf("Choose a user (0 to %d): ", user_count - 1);
                    for (int i = 0; i < user_count; i++) {
                        printf("\n%d. %s", i, users[i].name);
                    }
                    int user_index;
                    scanf("%d", &user_index);
                    
                    if (user_index >= 0 && user_index < user_count) {
                        take_exam(&users[user_index]);
                    } else {
                        printf("Invalid user selection!\n");
                    }
                }
                break;
            case 4:
                printf("Exiting the Online Examination System. Thank you!\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    return 0;
}