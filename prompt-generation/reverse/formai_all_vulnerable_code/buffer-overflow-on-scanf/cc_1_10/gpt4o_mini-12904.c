//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

// Function to generate a random integer within a range.
int random_integer(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to ask a math question of the given type.
void ask_question(int question_number) {
    // Select two random numbers between 1 and 10
    int num1 = random_integer(1, 10);
    int num2 = random_integer(1, 10);
    int operation = random_integer(1, 4); // 1: Addition, 2: Subtraction, 3: Multiplication, 4: Division
    
    int correct_answer;
    char operator;

    // Determine the operation and calculate the correct answer
    switch (operation) {
        case 1: // Addition
            correct_answer = num1 + num2;
            operator = '+';
            break;
        case 2: // Subtraction
            correct_answer = num1 - num2;
            operator = '-';
            break;
        case 3: // Multiplication
            correct_answer = num1 * num2;
            operator = '*';
            break;
        case 4: // Division
            // To avoid division by zero, ensure num2 is not zero
            num2 = num2 == 0 ? 1 : num2;
            correct_answer = num1 / num2;
            operator = '/';
            break;
        default:
            printf("Invalid operation selected.\n");
            return;
    }

    // Ask the user the question
    printf("Question %d: %d %c %d = ?\n", question_number + 1, num1, operator, num2);

    // Get the user's answer
    int user_answer;
    printf("Your answer: ");
    scanf("%d", &user_answer);

    // Check if the answer is correct
    if (user_answer == correct_answer) {
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer was %d.\n", correct_answer);
    }
}

// Main function to run the quiz game
int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Math Quiz Game!\n");
    printf("You will be asked %d questions. Try to answer them correctly!\n", MAX_QUESTIONS);

    int score = 0;

    // Loop to ask multiple questions
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        ask_question(i);
        printf("\n");
    }

    printf("Thank you for playing! Your total score is: %d out of %d\n", score, MAX_QUESTIONS);

    // Suggestion to replay the quiz
    printf("Would you like to play again? (y/n): ");
    char play_again;
    scanf(" %c", &play_again); // Note the space before %c to consume newline

    if (play_again == 'y' || play_again == 'Y') {
        main(); // Re-enter the game
    } else {
        printf("Goodbye!\n");
    }

    return 0;
}