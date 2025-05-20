//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10
#define MAX_GUESSES 7

// Function prototypes
void generate_word(char *word);
bool is_valid_guess(char *guess, char *word);
void print_hangman(int guesses_left);

int main()
{
    srand(time(NULL));
    char word[MAX_WORD_LENGTH + 1];
    generate_word(word);
    char guess[MAX_WORD_LENGTH + 1];
    int guesses_left = MAX_GUESSES;
    char *correct_guess = malloc(MAX_WORD_LENGTH * sizeof(char));
    correct_guess[0] = '\0';

    while (guesses_left > 0 && strcmp(guess, word)!= 0)
    {
        printf("Guesses left: %d\n", guesses_left);
        printf("Current word: ");
        for (int i = 0; i < strlen(word); i++)
        {
            if (isalpha(word[i]))
            {
                printf("%c", word[i]);
            }
            else
            {
                printf("_");
            }
        }
        printf("\n");

        printf("Enter your guess: ");
        fgets(guess, MAX_WORD_LENGTH + 1, stdin);
        guess[strcspn(guess, "\n")] = '\0';

        if (is_valid_guess(guess, word))
        {
            strcat(correct_guess, guess);
        }
        else
        {
            guesses_left--;
        }
    }

    if (strcmp(guess, word) == 0)
    {
        printf("Congratulations! You guessed the word '%s'!\n", word);
    }
    else
    {
        printf("Sorry, you ran out of guesses. The correct word was '%s'.\n", word);
    }

    free(correct_guess);
    return 0;
}

// Function to generate a random word
void generate_word(char *word)
{
    const char *words[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine", "watermelon", "xylophone", "yogurt", "zebra"};
    int rand_index = rand() % (sizeof(words) / sizeof(words[0]));
    strcpy(word, words[rand_index]);
}

// Function to check if a guess is valid
bool is_valid_guess(char *guess, char *word)
{
    for (int i = 0; i < strlen(guess); i++)
    {
        if (!isalpha(guess[i]))
        {
            return false;
        }
        else if (tolower(guess[i])!= tolower(word[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to print the hangman
void print_hangman(int guesses_left)
{
    if (guesses_left == 0)
    {
        printf("You lose! The hangman is complete.\n");
    }
    else
    {
        printf("Current hangman:\n");
        printf("  +---+\n");
        printf("  O   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=======\n");
    }
}