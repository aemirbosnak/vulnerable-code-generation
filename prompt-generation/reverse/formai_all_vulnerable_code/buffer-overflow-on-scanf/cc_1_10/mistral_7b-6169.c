//MISTRAL-7B DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void even_or_odd(int number) {
    int result;

    if (number < 0) {
        printf("Error: Negative numbers not allowed!\n");
        exit(EXIT_FAILURE);
    }

    result = number % 2;

    if (result == 0) {
        printf("%d is an even number.\n", number);
    } else {
        printf("%d is an odd number.\n", number);
    }
}

int main() {
    int number;

    printf("Welcome to the Even or Odd number game!\n");
    printf("Please enter a number: ");
    scanf("%d", &number);

    even_or_odd(number);

    return EXIT_SUCCESS;
}

// Here comes the silly part
void even_or_odd_joke(int number) {
    int result;

    if (number < 0) {
        printf("Oh noes! Negative numbers are not funny!\n");
        exit(EXIT_FAILURE);
    }

    result = number % 2;

    if (result == 0) {
        printf("%d is an even number, and that makes me feel all warm and fuzzy inside.\n", number);
    } else {
        printf("%d is an odd number, and that tickles my funny bone!\n", number);
    }
}

// And another one!
void even_or_odd_riddle(int number) {
    int result;

    if (number < 0) {
        printf("Negative numbers are a riddle, wrapped in a mystery, inside an enigma.\n");
        exit(EXIT_FAILURE);
    }

    result = number % 2;

    if (result == 0) {
        printf("Answer: The number %d is even.\n", number);
    } else {
        printf("Question: What begins with T, ends with T, but only has one letter?\n");
        printf("Answer: The number %d is odd.\n", number);
    }
}