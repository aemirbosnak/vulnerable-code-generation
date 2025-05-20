//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char magic_word[10];

    // Part 1: Guess the Magic Number
    printf("Welcome to the Magic Math Puzzle! \n");
    printf("I am thinking of a number between 1 and 100. Can you guess it?\n");
    printf("You have 3 chances. Good luck! \n");

    for (int i = 0; i < 3; i++) {
        printf("Guess: ");
        scanf("%d", &num1);

        if (num1 == MAGIC_NUMBER) {
            printf("Congratulations! You guessed it! \n");
            break;
        } else if (num1 > MAGIC_NUMBER) {
            printf("Too high! Try again. \n");
        } else {
            printf("Too low! Try again. \n");
        }
    }

    // Part 2: Solve the Math Puzzle
    printf("Now, let's play a math puzzle! \n");
    printf("I have two numbers, and I want you to add them up. But there's a catch! \n");
    printf("The first number is a magic word, and the second number is a number between 1 and 100. \n");
    printf("You need to figure out the magic word and add the two numbers to get the correct answer. \n");

    // Generate a random magic word
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        magic_word[i] = 'a' + (rand() % 26);
    }

    printf("The magic word is: %s \n", magic_word);

    // Part 3: Enter the Answer
    printf("Now, enter the answer: ");
    scanf("%d", &sum);

    // Check if the answer is correct
    if (sum == (atoi(magic_word) + num2)) {
        printf("Congratulations! You solved the puzzle! \n");
    } else {
        printf("Oops! You didn't solve the puzzle. Better luck next time! \n");
    }

    return 0;
}