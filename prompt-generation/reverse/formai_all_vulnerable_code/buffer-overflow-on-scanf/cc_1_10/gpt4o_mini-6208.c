//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define BUFFER_SIZE 256

typedef struct {
    char question[BUFFER_SIZE];
    char options[4][BUFFER_SIZE];
    int answer; // The index of the correct answer (0-3)
} Question;

typedef struct {
    char name[BUFFER_SIZE];
    char email[BUFFER_SIZE];
    int score;
} User;

User users[MAX_USERS];
Question questions[MAX_QUESTIONS];
int user_count = 0;
int question_count = 0;

void add_user() {
    if(user_count >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }
    
    printf("\nEnter Name: ");
    scanf(" %[^\n]", users[user_count].name); // Read string with spaces
    printf("Enter Email: ");
    scanf(" %[^\n]", users[user_count].email);
    users[user_count].score = 0; // Initialize score
    user_count++;
    printf("User registered successfully!\n");
}

void add_question() {
    if(question_count >= MAX_QUESTIONS) {
        printf("Question limit reached!\n");
        return;
    }
    
    printf("\nEnter question: ");
    scanf(" %[^\n]", questions[question_count].question);
    
    for(int i = 0; i < 4; i++) {
        printf("Enter option %d: ", i + 1);
        scanf(" %[^\n]", questions[question_count].options[i]);
    }
    
    printf("Enter the index of the correct answer (1-4): ");
    scanf("%d", &questions[question_count].answer);
    questions[question_count].answer--; // Adjust to zero-index
    question_count++;
    printf("Question added successfully!\n");
}

void display_questions() {
    for(int i = 0; i < question_count; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        for(int j = 0; j < 4; j++) {
            printf("   %d) %s\n", j + 1, questions[i].options[j]);
        }
    }
}

int take_exam() {
    int score = 0;
    for(int i = 0; i < question_count; i++) {
        int answer;
        printf("\nQuestion %d\n", i + 1);
        printf("%s\n", questions[i].question);
        for(int j = 0; j < 4; j++) {
            printf("   %d) %s\n", j + 1, questions[i].options[j]);
        }
        
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        if(answer - 1 == questions[i].answer) {
            score++;
        }
    }
    return score;
}

void view_results(User user) {
    printf("\nName: %s\n", user.name);
    printf("Email: %s\n", user.email);
    printf("Score: %d/%d\n", user.score, question_count);
}

void start_exam() {
    char email[BUFFER_SIZE];
    printf("\nEnter your email to take the exam: ");
    scanf(" %[^\n]", email);
    
    for(int i = 0; i < user_count; i++) {
        if(strcmp(users[i].email, email) == 0) {
            users[i].score = take_exam();
            printf("Exam completed!\n");
            view_results(users[i]);
            return;
        }
    }
    printf("User not found!\n");
}

int main() {
    int choice;
    while(1) {
        printf("\nOnline Examination System\n");
        printf("1. Register\n");
        printf("2. Add Question\n");
        printf("3. Start Exam\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_user();
                break;
            case 2:
                add_question();
                break;
            case 3:
                if (question_count == 0) {
                    printf("No questions available! Please add questions first.\n");
                } else {
                    start_exam();
                }
                break;
            case 4:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!\n");
        }
    }
    return 0;
}