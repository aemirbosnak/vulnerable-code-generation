//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>

// It's always nice to keep the DRY principle in mind. So let's just say:
#define BEGINNER_LEVEL 5
#define INTERMEDIATE_LEVEL 10
#define EXPERT_LEVEL 15

// We all know that factorials grow faster than a cat meme goes viral!
unsigned long long hilariously_large_factorial(int num) {
    unsigned long long result = 1;
    for (int i = 1; i <= num; i++) {
        // Apparently, the last person who said "It can't grow THAT fast" disappeared...
        // May their data types soar on towards infinity!
        result *= i;
        printf("Multiplying %d, Current Result: %llu\n", i, result);
    }
    return result;
}

// Our fancy little function to display factorials with a sense of drama!
void display_factorial(int number) {
    printf("Let's calculate the factorial of %d...\n*drum rolls*\n", number);
    unsigned long long result = hilariously_large_factorial(number);
    printf("And the final answer is... *ta-da!* %llu !\n\n", result);
}

int main() {
    // Welcome message with humor thrown in for good measure.
    printf("Welcome to the Magical Kingdom of Factorials!\n");
    printf("Here, the numbers dance, and the results fairytale! 🧙‍♂️✨\n\n");

    // Let's get user input
    int number;

    // Let's keep it simple for now...
    printf("Enter a number between 0 and %d (we don't want to scare the kids off!) for factoring fun: ", EXPERT_LEVEL);
    scanf("%d", &number);

    // Check if the number is within a reasonable range
    if (number < 0) {
        printf("Oops! Negative numbers have gone on holiday!\n");
    } else if (number > EXPERT_LEVEL) {
        printf("Whoa there! Are you trying to summon the factorial dragon?\n");
    } else {
        display_factorial(number);
    }

    printf("Thanks for playing! And remember, don’t take integers too seriously—\n");
    printf("You can always make them float!\n🎈\n");

    return 0;
}