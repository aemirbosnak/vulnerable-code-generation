//FormAI DATASET v1.0 Category: Online Examination System ; Style: random
#include<stdio.h>
#include<stdlib.h>

void display_question(int q_num) {
    printf("\nQ%d: What is the capital of India?", q_num);
}

void display_option(int option_num, char option[]) {
    printf("\n%d) %s", option_num, option);
}

void display_question_options() {
    display_option(1, "Delhi");
    display_option(2, "Mumbai");
    display_option(3, "Kolkata");
    display_option(4, "Chennai");
}

int get_user_answer() {
    int user_answer;
    printf("\nEnter your answer (1-4): ");
    scanf("%d", &user_answer);
    return user_answer;
}

void check_answer(int q_num, int user_answer, int *score) {
    int correct_answer = 1; // Delhi
    if (user_answer == correct_answer) {
        printf("Q%d: Correct!\n", q_num);
        (*score)++; // increase the score when the user gives correct answer
    } else {
        printf("Q%d: Incorrect!\n", q_num);
    }
}

int main() {
    int num_questions = 3;
    int score = 0;
    printf("Welcome to the Online Examination System!\n");
    printf("You will be given %d questions, each with 4 multiple choice options.\n", num_questions);
    printf("Please select the option number (1-4) that you think is correct.\n");

    for (int i=1; i<=num_questions; i++) {
        display_question(i);
        display_question_options();
        int user_answer = get_user_answer();
        check_answer(i, user_answer, &score);
    }

    printf("\nYou scored %d out of %d.\n", score, num_questions);
    printf("Thank you for using the Online Examination System!\n");
    return 0;
}