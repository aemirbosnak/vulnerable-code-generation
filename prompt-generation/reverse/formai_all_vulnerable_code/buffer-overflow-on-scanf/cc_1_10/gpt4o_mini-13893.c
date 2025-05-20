//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_intro() {
    printf("==================================\n");
    printf("       Welcome to Math Madness!   \n");
    printf("==================================\n");
    printf("Get ready to sharpen your math skills!\n");
    printf("Answer the questions as quickly as you can!\n");
    printf("Let's see how good you are! Good luck!\n\n");
}

int generate_question(int *num1, int *num2, char *op) {
    *num1 = rand() % 100; // Generating first random number
    *num2 = rand() % 100; // Generating second random number
    int operator = rand() % 4;

    switch (operator) {
        case 0: *op = '+'; return *num1 + *num2;
        case 1: *op = '-'; return *num1 - *num2;
        case 2: *op = '*'; return *num1 * *num2;
        case 3: 
            *op = '/'; 
            // Ensure we do not divide by zero
            if (*num2 == 0) *num2 = 1; // Set it to 1 to avoid division by zero
            return *num1 / *num2;
    }
    return 0; // Fallback case
}

int get_user_answer() {
    int answer;
    printf("Your answer: ");
    scanf("%d", &answer); // Taking input from the user
    return answer;
}

void check_answer(int correct, int user_answer, int question_num) {
    if (user_answer == correct) {
        printf("Correct! 🎉\n");
    } else {
        printf("Oops! The correct answer to question %d was: %d\n", question_num, correct);
    }
}

void play_game(int questions) {
    int score = 0;

    for (int i = 1; i <= questions; i++) {
        int num1, num2, correct_answer;
        char operator;
        correct_answer = generate_question(&num1, &num2, &operator);

        printf("Question %d: %d %c %d = ?\n", i, num1, operator, num2);
        int user_answer = get_user_answer();
        check_answer(correct_answer, user_answer, i);

        if (user_answer == correct_answer) {
            score++;
        }
        printf("\n");
    }
    printf("Game Over! Your score is: %d out of %d\n", score, questions);
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int total_questions;

    display_intro();
    printf("How many questions do you want to attempt? ");
    scanf("%d", &total_questions);

    // Start the game!
    play_game(total_questions);

    printf("Thank you for playing! Keep practicing those math skills! 📚\n");
    return 0;
}