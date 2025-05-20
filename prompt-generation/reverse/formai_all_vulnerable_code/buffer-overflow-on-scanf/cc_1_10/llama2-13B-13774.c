//LLAMA2-13B DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a cheerful function to print a smiley face 😊
void print_smiley() {
    printf(":)");
}

int main() {
    // Initialize a cheerful greeting 👋
    printf("Hello, world! 🌟\n");

    // Ask the user for their name 👩‍💼
    printf("What's your name, my dear? 💕\n");
    char name[50];
    fgets(name, 50, stdin);

    // Create a cheerful message based on the user's name 📝
    printf("Hello, %s! 👋\n", name);

    // Ask the user to guess a number 🤔
    printf("Guess a number between 1 and 100, my dear! 🤔\n");
    int guess;
    scanf("%d", &guess);

    // Generate a random number between 1 and 100 🎉
    int random_number = rand() % 100 + 1;

    // Print a cheerful message if the user's guess is correct 🎉
    if (guess == random_number) {
        print_smiley();
        printf("Yay, you guessed it! 🎉\n");
    }

    // Print a cheerful message if the user's guess is too high 🤦‍♀️
    else if (guess > random_number) {
        print_smiley();
        printf("Oops, too high! 🤦‍♀️\n");
    }

    // Print a cheerful message if the user's guess is too low 🤦‍♂️
    else {
        print_smiley();
        printf("Aww, too low! 🤦‍♂️\n");
    }

    // Print a cheerful farewell 👋
    printf("Farewell, my dear! 👋\n");
    return 0;
}