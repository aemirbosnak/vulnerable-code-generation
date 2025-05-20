//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    char *riddle;
} Enigma;

Enigma fact_enigma[12] = {
    {1, "What has a heart that doesn't beat?"},
    {2, "Why was six scared of seven?"},
    {3, "Why did the tomato turn red?"},
    {4, "How many sides does a square have?"},
    {5, "What comes once in a minute, twice in a moment?"},
    {6, "What is always in front of you but can't be seen?"},
    {7, "What has keys but can't open locks?"},
    {8, "What goes through cities but doesn't pass?"},
    {9, "What begins with E, ends with E, but only contains one letter?"},
    {10, "What is so fragile that saying its name breaks it?"},
    {11, "What starts with an E, ends with an E, but only contains one letter?"},
    {12, "How many times can a barber shave all the beards in a village at once?"}
};

int recursive_factorial(int n) {
    if (n > 12 || n < 0) {
        printf("Error: Invalid input. Please input a number between 0 and 12.\n");
        exit(EXIT_FAILURE);
    }

    if (n == 0) {
        return 1;
    }

    printf("Solving the riddle for %d...\n", n);
    printf("%s\n", fact_enigma[n].riddle);

    return n * recursive_factorial(n - 1);
}

int main() {
    int num;

    printf("Enter a number between 0 and 12: ");
    scanf("%d", &num);

    if (num > 12 || num < 0) {
        printf("Error: Invalid input. Please input a number between 0 and 12.\n");
        return EXIT_FAILURE;
    }

    printf("Calculating the factorial of %d using recursion and riddles...\n", num);

    int result = recursive_factorial(num);

    printf("The factorial of %d is: %d\n", num, result);

    return EXIT_SUCCESS;
}