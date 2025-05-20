//Falcon2-11B DATASET v1.0 Category: Educational ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to my cheerful program!\n");
    printf("I'm going to do some fun things for you today!\n");

    // Let's start with a simple greeting
    printf("Hello there!\n");
    printf("How are you today?\n");

    // Let's play a game
    int number = 0;
    int guess;
    printf("I'm thinking of a number between 1 and 10. Can you guess what it is?\n");
    scanf("%d", &guess);
    while (guess!= number) {
        if (guess < number) {
            printf("Your guess is too low. Try again!\n");
        } else if (guess > number) {
            printf("Your guess is too high. Try again!\n");
        }
        printf("I'm thinking of a number between 1 and 10. Can you guess what it is?\n");
        scanf("%d", &guess);
    }
    printf("Congratulations! You guessed my number!\n");

    // Let's do some math
    int firstNum = 5;
    int secondNum = 7;
    int result = firstNum + secondNum;
    printf("Let's add %d and %d. The result is %d!\n", firstNum, secondNum, result);

    // Let's practice some string manipulation
    char word1[] = "hello";
    char word2[] = "world";
    printf("%s %s\n", word1, word2);

    // Let's do some loops
    int count = 0;
    while (count < 10) {
        printf("I'm counting up to 10. This is iteration %d.\n", count);
        count++;
    }

    // Let's do some nested loops
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("(%d, %d)\n", i, j);
        }
    }

    // Let's do some input/output
    printf("Enter your name: ");
    char name[50];
    scanf("%s", name);
    printf("Hello %s, welcome to my program!\n", name);

    printf("Enter a number between 1 and 100: ");
    int num;
    scanf("%d", &num);
    while (num < 1 || num > 100) {
        printf("Invalid input. Please enter a number between 1 and 100.\n");
        printf("Enter a number between 1 and 100: ");
        scanf("%d", &num);
    }
    printf("You entered %d\n", num);

    printf("Thanks for playing my program! Have a great day!\n");

    return 0;
}