//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: dynamic
// Example program to create a unique C online examination system in a dynamic style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int generate_random_number() {
    return (rand() % 100) + 1;
}

// Function to check if a number is prime or not
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to generate a random prime number
int generate_random_prime_number() {
    int num;
    do {
        num = generate_random_number();
    } while (!is_prime(num));
    return num;
}

// Function to print the results
void print_results(int total_questions, int correct_answers) {
    printf("Total questions: %d\n", total_questions);
    printf("Correct answers: %d\n", correct_answers);
    printf("Accuracy: %.2f%%\n", (float)correct_answers / total_questions * 100);
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize variables
    int total_questions = 10;
    int correct_answers = 0;
    int prime_number = generate_random_prime_number();

    // Ask questions
    for (int i = 1; i <= total_questions; i++) {
        int answer = 0;
        printf("Question %d: What is the %dth prime number? ", i, i);
        scanf("%d", &answer);
        if (answer == prime_number) {
            correct_answers++;
        }
    }

    // Print results
    print_results(total_questions, correct_answers);

    return 0;
}