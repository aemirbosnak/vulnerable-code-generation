//FormAI DATASET v1.0 Category: Game ; Style: all-encompassing
/* This program is a simple implementation of the well-known game called "Hangman". 
 * The premise of the game is to guess a word by providing one letter at a time, 
 * while avoiding making too many incorrect guesses. 
 * This version of the game allows the player to either input their own word for others to guess, 
 * or to play with a randomly generated word from a selection of pre-defined words. 
 * Good luck, and have fun!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_GUESSES 5
#define WORD_LIST_SIZE 10

// Function to randomly choose a word from a list of pre-defined words
void choose_word(char *word)
{
    char *word_list[WORD_LIST_SIZE] = {"programming", "computer", "algorithm", "function", "variable", 
                                       "recursion", "circuit", "binary", "compiler", "syntax" };
    int index = rand() % WORD_LIST_SIZE;
    strcpy(word, word_list[index]);
}

// Function to get user's input word
void get_word(char *word)
{
    printf("Enter a word for others to guess (maximum length of %d): ", MAX_WORD_LENGTH-1);
    scanf("%s", word);
}

// Function to hide parts of the word based on the guesses made so far
void hide_word(const char *word, char *hidden_word, const char *guessed_letters)
{
    int word_length = strlen(word);
    memset(hidden_word, '_', word_length);
    
    for (int i = 0; i < word_length; i++) {
        for (int j = 0; j < strlen(guessed_letters); j++) {
            if (word[i] == guessed_letters[j]) {
                hidden_word[i] = word[i];
            }
        }
    }
}

// Function to get user's guess
char get_guess(const char *guessed_letters)
{
    char guess;
    bool is_valid = false;
    
    while (!is_valid) {
        printf("\nGuess a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);
        
        if (!isalpha(guess)) {
            printf("Invalid input. Please enter a letter.\n");
        }
        else if (strchr(guessed_letters, guess)) {
            printf("You already guessed that letter. Please enter a different letter.\n");
        }
        else {
            is_valid = true;
        }
    }
    
    return guess;
}

int main()
{
    char word[MAX_WORD_LENGTH], hidden_word[MAX_WORD_LENGTH];
    char guessed_letters[MAX_GUESSES+1] = {0};
    int num_guesses = 0;
    bool is_word_guessed = false, game_over = false;
    srand(time(NULL));
    
    printf("Welcome to Hangman!\n\n");
    
    // Ask the player whether they want to input their own word or play with a random word
    char input_choice;
    printf("Do you want to input your own word to guess? (y/n): ");
    scanf(" %c", &input_choice);
    
    if (tolower(input_choice) == 'y') {
        get_word(word);
    }
    else {
        choose_word(word);
    }
    
    int word_length = strlen(word);
    printf("\nThe word to guess has %d letters.\n", word_length);
    
    // Main game loop
    while (!game_over) {
        hide_word(word, hidden_word, guessed_letters);
        
        printf("\n\n%s\n", hidden_word);
        printf("Guessed letters: %s\n", guessed_letters);
        
        char guess = get_guess(guessed_letters);
        guessed_letters[num_guesses++] = guess;
        
        if (strchr(word, guess)) {
            printf("Congratulations! The guess is correct.\n");
        }
        else {
            printf("Sorry, the guess is incorrect.\n");
        }
        
        if (strcmp(word, hidden_word) == 0) {
            is_word_guessed = true;
            game_over = true;
        }
        else if (++num_guesses == MAX_GUESSES) {
            game_over = true;
        }
    }
    
    // Display game outcome
    printf("\n");
    if (is_word_guessed) {
        printf("Congratulations! You guessed the word \"%s\" correctly.\n", word);
    }
    else {
        printf("Sorry, you have failed to guess the word \"%s\" within the allowed number of guesses.\n", word);
        printf("The correct word was \"%s\".\n", word);
    }
    
    return 0;
}