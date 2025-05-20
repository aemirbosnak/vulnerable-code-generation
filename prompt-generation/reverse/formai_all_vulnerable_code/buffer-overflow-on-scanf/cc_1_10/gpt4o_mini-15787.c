//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printInstructions() {
    printf("Welcome to the Math Challenge Game!\n");
    printf("You will be given arithmetic problems based on your chosen difficulty level.\n");
    printf("Correct answers will earn you points. Wrong answers will deduct points.\n");
    printf("Choose a level:\n");
    printf("1. Easy (1-10)\n");
    printf("2. Medium (1-50)\n");
    printf("3. Hard (1-100)\n");
    printf("Press any other key to quit.\n");
}

int generateProblem(int difficulty) {
    int a, b, answer, userAnswer, correctAnswers = 0;
    char operator;

    // Set bounds based on difficulty
    int low, high;
    if (difficulty == 1) {
        low = 1; high = 10;
    } else if (difficulty == 2) {
        low = 1; high = 50;
    } else if (difficulty == 3) {
        low = 1; high = 100;
    } else {
        return -1;
    }

    // Randomly select two numbers and an operator
    srand(time(0));
    a = rand() % (high - low + 1) + low;
    b = rand() % (high - low + 1) + low;
    operator = (rand() % 2) ? '+' : '-'; // Random operator: + or -

    // Calculate the correct answer
    if (operator == '+') {
        answer = a + b;
    } else {
        answer = a - b;
    }

    // Prompt the user and read their answer
    printf("What is %d %c %d? ", a, operator, b);
    scanf("%d", &userAnswer);

    // Check the user's answer
    if (userAnswer == answer) {
        printf("Correct!\n");
        return 1; // Correct answer
    } else {
        printf("Wrong! The correct answer is %d.\n", answer);
        return -1; // Wrong answer
    }
}

int main() {
    printInstructions();
    
    int difficulty;
    scanf("%d", &difficulty);
    
    int score = 0;
    int result;

    while (1) {
        result = generateProblem(difficulty);
        if (result == -1) {
            printf("Exiting the game. Your final score is: %d\n", score);
            break;
        } else {
            score += result;
            printf("Your current score is: %d\n", score);
        }
        
        printf("Do you want to continue? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            printf("Thank you for playing! Your final score is: %d\n", score);
            break;
        }
    }

    return 0;
}