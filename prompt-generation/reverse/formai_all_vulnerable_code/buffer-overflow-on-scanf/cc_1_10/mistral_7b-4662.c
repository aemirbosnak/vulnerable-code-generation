//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define WORD_LENGTH 20
#define MAX_TRIES 5

// Function to generate a random secret word
void generate_secret_word(char* word) {
    srand(time(NULL));
    for (int i = 0; i < WORD_LENGTH; i++) {
        word[i] = (rand() % 26) + 'a';
    }
    word[WORD_LENGTH] = '\0';
}

// Function to encrypt the secret word using bitwise operations
void encrypt_word(char* word) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        word[i] = (word[i] << 2) | (word[i] >> 4) | ((word[i] & 0xf0) >> 2);
    }
}

// Function to compare two strings for equality
int compare_strings(char* str1, char* str2) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to print the cat's message
void cat_message() {
    printf("\n\n*** The Cat says: ***\n");
    printf("You have %d tries remaining.\n", MAX_TRIES);
    printf("Remember, every letter in the word has been shifted by the same amount.\n");
    printf("Good luck!\n\n");
}

// Function to get user input and check it against the secret word
int get_user_input(char* secret_word) {
    char user_input[WORD_LENGTH];
    printf("Enter your guess: ");
    scanf("%s", user_input);
    return compare_strings(user_input, secret_word);
}

// Main function
int main() {
    char secret_word[WORD_LENGTH];
    generate_secret_word(secret_word);
    encrypt_word(secret_word);

    int tries_left = MAX_TRIES;
    while (tries_left > 0) {
        cat_message();
        int correct_guess = get_user_input(secret_word);
        if (correct_guess) {
            printf("\n*** Congratulations, you've guessed the word! ***\n");
            break;
        } else {
            tries_left--;
            printf("Incorrect guess. You have %d tries left.\n", tries_left);
        }
    }

    if (tries_left == 0) {
        printf("\n*** Sorry, you've run out of tries. The word was: %s ***\n", secret_word);
    }

    return 0;
}