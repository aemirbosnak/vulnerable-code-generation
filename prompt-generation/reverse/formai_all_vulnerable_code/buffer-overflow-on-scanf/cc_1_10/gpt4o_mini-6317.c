//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PUZZLE_COUNT 5

void display_puzzle(int num1, int num2, char operation) {
    printf("In the realm of forgotten numbers, a riddle awaits:\n");
    printf("What is the result of %d %c %d?\n", num1, operation, num2);
}

char random_operation() {
    char operations[] = {'+', '-', '*', '/'};
    return operations[rand() % 4];
}

int calculate(int num1, int num2, char operation) {
    switch (operation) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return (num2 != 0) ? num1 / num2 : 0; // Avoid division by zero
        default: return 0; // Fallback case
    }
}

void cryptic_message(int correct_count) {
    if (correct_count == PUZZLE_COUNT) {
        printf("A fate intertwined with mathematical brilliance...\n");
    } else if (correct_count >= PUZZLE_COUNT / 2) {
        printf("You hold the keys to the kingdom of numbers...\n");
    } else {
        printf("Seek knowledge in the shadows, for the light of numbers will guide you...\n");
    }
}

int main() {
    srand(time(NULL));
    
    int user_answer, correct_answer;
    int correct_count = 0;

    printf("Welcome, seeker of knowledge, to the Enigma of Arithmetic.\n");
    printf("You will face %d mathematical conundrums.\n", PUZZLE_COUNT);
    printf("Prove your worth!\n");

    for (int i = 0; i < PUZZLE_COUNT; i++) {
        int num1 = rand() % 100 + 1; // Random number between 1 and 100
        int num2 = rand() % 100 + 1; // Random number between 1 and 100
        char operation = random_operation();
        
        display_puzzle(num1, num2, operation);
        
        printf("Your answer: ");
        scanf("%d", &user_answer);
        
        correct_answer = calculate(num1, num2, operation);

        if (user_answer == correct_answer) {
            printf("Correct! The numbers have whispered their secrets to you.\n");
            correct_count++;
        } else {
            printf("Alas! You missed the truth. The answer was %d.\n", correct_answer);
        }
    }

    cryptic_message(correct_count);

    printf("You have completed the challenge. Until we meet again...\n");
    return 0;
}