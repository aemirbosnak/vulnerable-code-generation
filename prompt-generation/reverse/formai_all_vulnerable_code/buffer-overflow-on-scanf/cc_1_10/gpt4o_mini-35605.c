//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define USERNAME_SIZE 20
#define PASSWORD_SIZE 20

typedef struct {
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
} User;

typedef struct {
    char question[100];
    char options[4][50];
    int answer;
} Question;

User users[MAX_USERS];
int userCount = 0;
Question questions[MAX_QUESTIONS];
int questionCount = 0;

// Function Prototypes
void registerUser();
void loginUser();
void takeExam();
void loadQuestions();
void displayQuestions();
void gradeExam(int score);

int main() {
    int choice;

    printf("Welcome to the Online Examination System! \n");
    while (1) {
        printf("\n1. Register\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting the system... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached! Cannot register more users.\n");
        return;
    }
    printf("Registering a new user! \n");
    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);
    users[userCount++] = newUser;
    printf("User registered successfully!\n");
}

void loginUser() {
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];

    printf("Logging in... \n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            printf("Login successful! Prepare for the exam.\n");
            takeExam();
            return;
        }
    }
    printf("Login failed! Incorrect username or password.\n");
}

void loadQuestions() {
    printf("Loading exam questions... \n");
    // Sample Questions
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "1. Berlin");
    strcpy(questions[0].options[1], "2. Madrid");
    strcpy(questions[0].options[2], "3. Paris");
    strcpy(questions[0].options[3], "4. Rome");
    questions[0].answer = 3;

    strcpy(questions[1].question, "What is 2 + 2?");
    strcpy(questions[1].options[0], "1. 3");
    strcpy(questions[1].options[1], "2. 4");
    strcpy(questions[1].options[2], "3. 5");
    strcpy(questions[1].options[3], "4. 6");
    questions[1].answer = 2;

    questionCount = 2; 
}

void takeExam() {
    int score = 0;
    loadQuestions();

    printf("Starting your examination... Tension is building up! \n");
    displayQuestions();

    for (int i = 0; i < questionCount; i++) {
        int choice;
        printf("Choose an answer for Question %d (1-4): ", i + 1);
        scanf("%d", &choice);

        if (choice == questions[i].answer) {
            score++;
            printf("Question %d: Correct! Well done!\n", i + 1);
        } else {
            printf("Question %d: Incorrect! The correct answer was %d.\n", i + 1, questions[i].answer);
        }
    }
    gradeExam(score);
}

void displayQuestions() {
    printf("Here are your questions: \n");
    for (int i = 0; i < questionCount; i++) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }
    }
}

void gradeExam(int score) {
    printf("Exam completed! Your score is: %d/%d\n", score, questionCount);
    int percentage = (score * 100) / questionCount;

    if (percentage >= 70) {
        printf("Congratulations! You passed!\n");
    } else {
        printf("Unfortunately, you did not pass. Better luck next time.\n");
    }
}