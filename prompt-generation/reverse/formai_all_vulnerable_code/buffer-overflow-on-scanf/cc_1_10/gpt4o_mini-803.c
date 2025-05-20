//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_QUIZ_QUESTIONS 5

void print_menu() {
    printf("\n--- Welcome to the Math Exercise Program ---\n");
    printf("1. Basic Arithmetic Quiz\n");
    printf("2. Calculate Mean and Standard Deviation\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

int generate_quiz_question() {
    // Generate two random numbers
    int num1 = rand() % 100; // Random number between 0 and 99
    int num2 = rand() % 100; // Random number between 0 and 99
    
    // Random operation
    char operations[4] = {'+', '-', '*', '/'};
    char operation = operations[rand() % 4];

    // Calculate the answer
    int correct_answer;
    switch (operation) {
        case '+':
            correct_answer = num1 + num2;
            break;
        case '-':
            correct_answer = num1 - num2;
            break;
        case '*':
            correct_answer = num1 * num2;
            break;
        case '/':
            correct_answer = num2 != 0 ? num1 / num2 : 0; // Avoid division by zero
            break;
        default:
            correct_answer = 0;
            break;
    }
    
    // Print the question
    printf("%d %c %d = ?\n", num1, operation, num2);
    return correct_answer;
}

void arithmetic_quiz() {
    printf("\n--- Let's Start the Arithmetic Quiz! ---\n");
    int score = 0;

    for (int i = 0; i < MAX_QUIZ_QUESTIONS; i++) {
        int correct_answer = generate_quiz_question();
        int user_answer;

        printf("Your answer: ");
        scanf("%d", &user_answer);

        if (user_answer == correct_answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %d.\n", correct_answer);
        }
    }
    
    printf("\nYour score: %d out of %d\n", score, MAX_QUIZ_QUESTIONS);
}

void calculate_statistics() {
    int n;
    printf("\n--- Calculate Mean and Standard Deviation ---\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    double numbers[n];
    double sum = 0.0;

    printf("Enter %d numbers:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%lf", &numbers[i]);
        sum += numbers[i];
    }

    double mean = sum / n;
    double sum_squared_diff = 0.0;

    for (int i = 0; i < n; i++) {
        sum_squared_diff += pow(numbers[i] - mean, 2);
    }

    double standard_deviation = sqrt(sum_squared_diff / n);

    printf("Mean: %.2lf\n", mean);
    printf("Standard Deviation: %.2lf\n", standard_deviation);
}

int main() {
    srand(time(0)); // Seed for random function
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                arithmetic_quiz();
                break;
            case 2:
                calculate_statistics();
                break;
            case 3:
                printf("Thank you for using the Math Exercise Program! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please select again.\n");
        }
    }

    return 0;
}