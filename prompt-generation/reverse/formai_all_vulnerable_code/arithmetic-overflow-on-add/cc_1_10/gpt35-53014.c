//FormAI DATASET v1.0 Category: Online Examination System ; Style: decentralized
// Code snippet for a decentralized C Online Examination System
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int menu();
void generate_quiz();
void play_quiz();

int main() {
    int choice;
    while(1) {
        choice = menu();
        switch(choice) {
            case 1:
                generate_quiz();
                break;
            case 2:
                play_quiz();
                break;
            case 3:
                printf("Thank you for using the Online Examination System.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}

int menu() {
    int choice;
    printf("===== ONLINE EXAMINATION SYSTEM =====\n");
    printf("1. Generate quiz\n");
    printf("2. Play quiz\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void generate_quiz() {
    // Generate a set of random questions and answers
    srand(time(NULL));
    int num_questions = rand() % 6 + 5; // Generate between 5-10 questions
    printf("Generated quiz:\n");
    printf("=================\n");
    for(int i=0; i<num_questions; i++) {
        int num1 = rand() % 100;
        int num2 = rand() % 100;
        char op;
        int answer;
        switch(rand() % 4) {
            case 0:
                op = '+';
                answer = num1 + num2;
                break;
            case 1:
                op = '-';
                answer = num1 - num2;
                break;
            case 2:
                op = '*';
                answer = num1 * num2;
                break;
            case 3:
                op = '/';
                answer = num1 / num2;
                break;
        }
        printf("%d. %d %c %d = ?\n", i+1, num1, op, num2);
        printf("Answer: %d\n", answer);
        printf("\n");
    }
}

void play_quiz() {
    // Allow the user to answer questions from a quiz
    int num_questions;
    printf("Enter the number of questions in the quiz: ");
    scanf("%d", &num_questions);
    printf("Quiz:\n");
    printf("====\n");
    int score = 0;
    for(int i=0; i<num_questions; i++) {
        int num1, num2, answer, user_answer;
        char op;
        printf("Question %d:\n", i+1);
        printf("==========\n");
        printf("Enter the first number: ");
        scanf("%d", &num1);
        printf("Enter the second number: ");
        scanf("%d", &num2);
        printf("Enter the operator (+, -, *, /): ");
        scanf(" %c", &op);
        printf("Enter your answer: ");
        scanf("%d", &user_answer);
        switch(op) {
            case '+':
                answer = num1 + num2;
                break;
            case '-':
                answer = num1 - num2;
                break;
            case '*':
                answer = num1 * num2;
                break;
            case '/':
                answer = num1 / num2;
                break;
        }
        if(user_answer == answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n\n", answer);
        }
    }
    printf("Your score is: %d out of %d.\n", score, num_questions);
}