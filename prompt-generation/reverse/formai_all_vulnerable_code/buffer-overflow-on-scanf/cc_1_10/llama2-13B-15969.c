//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_GREETING_LEN 50

int main() {
    // Declare variables
    char name[MAX_NAME_LEN];
    char greeting[MAX_GREETING_LEN];
    int age;

    // Get the user's name and age
    printf("What's your name? ");
    fgets(name, MAX_NAME_LEN, stdin);
    printf("How old are you? ");
    scanf("%d", &age);

    // Generate a personalized greeting
    if (age >= 18) {
        strcpy(greeting, "Happy birthday, young adult!");
    } else if (age >= 13 && age < 18) {
        strcpy(greeting, "Happy birthday, teenager!");
    } else {
        strcpy(greeting, "Happy birthday, kid!");
    }

    // Print the greeting
    printf("Hello, %s! %s\n", name, greeting);

    // Play a game of guess the number
    int secret_number = 100;
    int guess = 0;

    do {
        printf("Guess the number: ");
        scanf("%d", &guess);

        // Check if the user guessed the correct number
        if (guess == secret_number) {
            printf("Congratulations, you guessed it! The secret number was %d.\n", secret_number);
            break;
        } else if (guess > secret_number) {
            printf("Too high! The secret number is lower than %d.\n", secret_number);
        } else {
            printf("Too low! The secret number is higher than %d.\n", secret_number);
        }
    } while (guess != secret_number);

    return 0;
}