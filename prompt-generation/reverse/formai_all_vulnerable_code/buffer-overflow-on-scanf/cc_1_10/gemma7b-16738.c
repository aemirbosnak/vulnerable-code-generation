//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 20

int main()
{
    char name[MAX_CHAR];
    char secret_message[MAX_CHAR];
    int guess_count = 0;
    char guess_letter;

    system("cls");
    printf("Enter a secret message: ");
    scanf("%s", secret_message);

    printf("Enter your name: ");
    scanf("%s", name);

    system("cls");
    printf("Welcome, %s! Please guess the secret message:\n", name);

    while (guess_count < 5)
    {
        printf("Guess a letter: ");
        scanf(" %c", &guess_letter);

        guess_count++;

        if (guess_letter == secret_message[0])
        {
            printf("The first letter is correct!\n");
        }
        else if (guess_letter == secret_message[1])
        {
            printf("The second letter is correct!\n");
        }
        else if (guess_letter == secret_message[2])
        {
            printf("The third letter is correct!\n");
        }
        else if (guess_letter == secret_message[3])
        {
            printf("The fourth letter is correct!\n");
        }
        else if (guess_letter == secret_message[4])
        {
            printf("The fifth letter is correct!\n");
        }
        else
        {
            printf("Incorrect guess.\n");
        }
    }

    system("cls");
    printf("Sorry, %s, you have run out of guesses. The secret message was: %s\n", name, secret_message);

    return 0;
}