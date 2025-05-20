//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: standalone
// Online Examination System
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures
typedef struct {
    char question[100];
    char answer[100];
} Question;

typedef struct {
    char username[100];
    char password[100];
    int score;
} User;

// Functions
void generate_questions(Question *questions, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        sprintf(questions[i].question, "Question %d", i + 1);
        sprintf(questions[i].answer, "Answer %d", i + 1);
    }
}

void display_questions(Question *questions, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
    }
}

void check_answers(Question *questions, int num_questions, User *user) {
    int correct_answers = 0;
    for (int i = 0; i < num_questions; i++) {
        if (strcmp(questions[i].answer, user->password) == 0) {
            correct_answers++;
        }
    }
    user->score = correct_answers;
}

void display_results(User *user) {
    printf("Your score is %d\n", user->score);
}

int main() {
    // Initialize variables
    User user;
    Question questions[10];
    int num_questions = 10;

    // Generate questions
    generate_questions(questions, num_questions);

    // Display questions
    display_questions(questions, num_questions);

    // Ask for username and password
    printf("Enter your username: ");
    scanf("%s", user.username);
    printf("Enter your password: ");
    scanf("%s", user.password);

    // Check answers
    check_answers(questions, num_questions, &user);

    // Display results
    display_results(&user);

    return 0;
}