//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 5
#define MAX_NUMBER 20

void ask_question(int question_number);
int generate_random_number(int max);
void print_feedback(int score);

int main() {
    int score = 0;
    char choice;

    printf("Welcome to the Math Quiz Game!\n");
    printf("You will be asked %d questions.\n\n", NUM_QUESTIONS);

    for (int i = 1; i <= NUM_QUESTIONS; i++) {
        ask_question(i);
        int user_answer;
        printf("Enter your answer: ");
        scanf("%d", &user_answer);
        score += (user_answer == 0) ? 0 : (user_answer == generate_random_number(MAX_NUMBER) + generate_random_number(MAX_NUMBER)) ? 1 : 0;
    }
    
    printf("\nYour total score is: %d out of %d\n", score, NUM_QUESTIONS);
    print_feedback(score);

    return 0;
}

void ask_question(int question_number) {
    int num1 = generate_random_number(MAX_NUMBER);
    int num2 = generate_random_number(MAX_NUMBER);

    printf("Question %d: What is %d + %d?\n", question_number, num1, num2);
}

int generate_random_number(int max) {
    return rand() % max;
}

void print_feedback(int score) {
    if (score == NUM_QUESTIONS) {
        printf("Excellent! You got all answers correct!\n");
    } else if (score >= NUM_QUESTIONS / 2) {
        printf("Good job! You scored %d. Keep practicing!\n", score);
    } else {
        printf("You scored %d. Don't give up! Try again!\n", score);
    }
}