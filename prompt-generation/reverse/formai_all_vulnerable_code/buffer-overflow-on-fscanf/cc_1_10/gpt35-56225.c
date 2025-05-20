//FormAI DATASET v1.0 Category: Online Examination System ; Style: grateful
#include <stdio.h>
#include <string.h>

// Question struct to store the questions and their options and answers
typedef struct Question {
    int id;
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int answer;
} Question;

// User struct to store user information and results
typedef struct User {
    char name[50];
    char email[50];
    int score;
} User;

// Function to display the menu options
void displayMenu() {
    printf("\n-------------- Online C Exam System --------------\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Take Test\n");
    printf("4. View Score\n");
    printf("5. Exit\n");
}

// Function to register a new user
void registerUser(User users[], int *count) {
    char name[50], email[50];
    printf("\nEnter your name: ");
    scanf("%s", name);
    printf("Enter your email address: ");
    scanf("%s", email);
    strcpy(users[*count].name, name);
    strcpy(users[*count].email, email);
    users[*count].score = 0;
    *count += 1;
    printf("\nRegistration Successful!\n");
}

// Function to check if user exists and if password is correct
int loginUser(User users[], int count, int *index) {
    char email[50];
    printf("\nEnter your email address: ");
    scanf("%s", email);
    for (int i = 0; i < count; i++) {
        if (strcmp(email, users[i].email) == 0) {
            *index = i;
            return 1;
        }
    }
    return 0;
}

// Function to load the questions from a file
void loadQuestions(Question questions[], int *count) {
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL) {
        printf("Error opening file!");
        return;
    }
    int id, answer;
    char question[100], option1[50], option2[50], option3[50], option4[50];
    while (fscanf(file, "%d %[^\n] %s %s %s %s %d", &id, question, option1, option2, option3, option4, &answer) != EOF) {
        questions[*count].id = id;
        strcpy(questions[*count].question, question);
        strcpy(questions[*count].option1, option1);
        strcpy(questions[*count].option2, option2);
        strcpy(questions[*count].option3, option3);
        strcpy(questions[*count].option4, option4);
        questions[*count].answer = answer;
        *count += 1;
    }
    fclose(file);
}

// Function to display the questions and get user answers
void takeTest(Question questions[], int count, User *user) {
    int choice, answer, score = 0;
    printf("\n-------------- C Exam Questions --------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", questions[i].id, questions[i].question);
        printf("   1. %s\n", questions[i].option1);
        printf("   2. %s\n", questions[i].option2);
        printf("   3. %s\n", questions[i].option3);
        printf("   4. %s\n", questions[i].option4);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        answer = choice;
        if (answer == questions[i].answer) {
            score += 1;
        }
    }
    user->score = score;
    printf("\nYour score is %d out of %d.\n", user->score, count);
}

// Function to display the user's score
void viewScore(User user) {
    printf("\n%s, your score is %d.\n", user.name, user.score);
}

int main() {
    User users[100];
    Question questions[20];
    int countUsers = 0, countQuestions = 0, index = -1, choice;
    loadQuestions(questions, &countQuestions);
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                registerUser(users, &countUsers);
                break;
            case 2:
                if (loginUser(users, countUsers, &index)) {
                    printf("\nLogin Successful!\n");
                } else {
                    printf("\nUser not found. Please register first.\n");
                }
                break;
            case 3:
                if (index != -1) {
                    takeTest(questions, countQuestions, &users[index]);
                } else {
                    printf("\nPlease login first.\n");
                }
                break;
            case 4:
                if (index != -1) {
                    viewScore(users[index]);
                } else {
                    printf("\nPlease login first.\n");
                }
                break;
            case 5:
                printf("\nExiting Online C Exam System...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while(choice != 5);

    return 0;
}