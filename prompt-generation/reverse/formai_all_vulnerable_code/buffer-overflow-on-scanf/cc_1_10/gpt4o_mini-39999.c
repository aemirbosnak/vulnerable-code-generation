//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ATTEMPTS 5
#define HISTORY_LIMIT 100

typedef struct {
    double values[HISTORY_LIMIT];
    int count;
} History;

void add_to_history(History *history, double value) {
    if (history->count < HISTORY_LIMIT) {
        history->values[history->count++] = value;
    } else {
        printf("History is full! Can't add more values\n");
    }
}

void print_history(History *history) {
    printf("History of values (up to last %d entries):\n", HISTORY_LIMIT);
    for (int i = 0; i < history->count; ++i) {
        printf("%d: %.2f\n", i + 1, history->values[i]);
    }
}

double get_user_input() {
    double value;
    printf("Enter a number (or type 'exit' to quit): ");
    while (1) {
        if (scanf("%lf", &value) == 1) {
            return value;
        } else {
            printf("Input error. Please enter a valid number: ");
            while (getchar() != '\n'); // clear the buffer
        }
    }
}

void paranoid_computation() {
    History history = {.count = 0};
    char command[10];
    double number;

    printf("Welcome to the Paranoid Math Program!\n");
    printf("I’m here to compute your values, but you must trust me!\n");
    
    while (1) {
        printf("Do you wish to calculate? (yes/no): ");
        scanf("%s", command);

        if (strcmp(command, "no") == 0) {
            printf("You are too paranoid! Exiting program...\n");
            break;
        } else if (strcmp(command, "yes") != 0) {
            printf("I don't understand. Are you too paranoid to answer?\n");
            continue;
        }

        number = get_user_input();
        add_to_history(&history, number);

        printf("Calculating square root of %.2f...\n", number);
        double sqrt_result = sqrt(number);
        printf("Square root: %.2f\n", sqrt_result);
        add_to_history(&history, sqrt_result);

        printf("Calculating square of %.2f...\n", number);
        double square_result = pow(number, 2);
        printf("Square: %.2f\n", square_result);
        add_to_history(&history, square_result);

        printf("Calculating factorial of %.0f (if valid)...\n", number);
        if (number < 0) {
            printf("Factorial is impossible for negative numbers! Are you trying to deceive me?\n");
        } else {
            long long factorial_result = 1;
            for (int i = 1; i <= (int)number; ++i) {
                factorial_result *= i;
            }
            printf("Factorial: %lld\n", factorial_result);
            add_to_history(&history, factorial_result);
        }

        print_history(&history);

        printf("Let's do repeats to be sure...\n");
        for (int i = 0; i < MAX_ATTEMPTS; ++i) {
            number = get_user_input();
            printf("Doing calculations again with %.2f...\n", number);
            sqrt_result = sqrt(number);
            square_result = pow(number, 2);
            printf("Square root: %.2f | Square: %.2f\n", sqrt_result, square_result);
            add_to_history(&history, sqrt_result);
            add_to_history(&history, square_result);
        }

        printf("Thank you for your cooperation!\n");
    }
}

int main() {
    paranoid_computation();
    return 0;
}