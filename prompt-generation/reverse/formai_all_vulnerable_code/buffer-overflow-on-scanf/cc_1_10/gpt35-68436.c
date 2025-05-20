//FormAI DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generates unique random numbers for the math exercise
void generate_numbers(int *a, int *b) {
    srand(time(NULL));
    // Generate numbers between 1 and 10
    *a = rand() % 10 + 1;
    *b = rand() % 10 + 1;
    // Make sure a is greater than or equal to b 
    if (*a < *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

// Displays the math exercise and gets user input for the answer
int get_user_input(int a, int b, char operator) {
    int answer;
    printf("What is %d %c %d? ", a, operator, b);
    scanf("%d", &answer);
    return answer;
}

// Checks if the user's answer is correct and displays the result
void check_answer(int a, int b, char operator, int user_answer) {
    int correct_answer;
    // Calculate the correct answer based on the operator
    switch (operator) {
        case '+':
            correct_answer = a + b;
            break;
        case '-':
            correct_answer = a - b;
            break;
        case '*':
            correct_answer = a * b;
            break;
        case '/':
            correct_answer = a / b;
            break;
    }
    // Check if the user's answer is correct and display the result
    if (user_answer == correct_answer) {
        printf("Correct! %d %c %d = %d\n", a, operator, b, correct_answer);
    } else {
        printf("Wrong! %d %c %d = %d, not %d\n", a, operator, b, correct_answer, user_answer);
    }
}

int main() {
    int a, b;
    char operator;
    int user_answer;
    // Display the instructions
    printf("Welcome to the Math Exercise Program!\n");
    printf("You will be given a math exercise consisting of two numbers and an operator.\n");
    printf("Enter the correct answer to score points.\n");
    printf("You can quit the program by entering a negative number as your answer.\n\n");
    // Loop through the exercises until the user enters a negative answer
    do {
        generate_numbers(&a, &b);
        // Randomly select an operator
        switch (rand() % 4) {
            case 0:
                operator = '+';
                break;
            case 1:
                operator = '-';
                break;
            case 2:
                operator = '*';
                break;
            case 3:
                operator = '/';
                break;
        }
        user_answer = get_user_input(a, b, operator);
        if (user_answer >= 0) {
            check_answer(a, b, operator, user_answer);
            printf("\n");
        }
    } while (user_answer >= 0);
    printf("Thanks for playing the Math Exercise Program!\n");
    return 0;
}