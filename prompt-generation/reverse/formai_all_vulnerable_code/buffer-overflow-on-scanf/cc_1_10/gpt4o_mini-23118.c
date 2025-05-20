//GPT-4o-mini DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TRIES 5
#define MAX_WORDS 10
#define MAX_LENGTH 20

void print_logo() {
    printf("========================================\n");
    printf("  Welcome to the Wacky Word Guesser!  \n");
    printf("========================================\n\n");
}

void choose_random_word(char *word) {
    const char *word_list[MAX_WORDS] = {
        "penguin", 
        "octopus",
        "banana",
        "pterodactyl",
        "kumquat",
        "supernova",
        "quizzical",
        "flabbergasted",
        "oodle",
        "bamboozle"
    };
    srand(time(NULL));
    int random_index = rand() % MAX_WORDS;
    strcpy(word, word_list[random_index]);
}

void print_attempts(int tries){
    printf("Attempts left: %d\n", MAX_TRIES - tries);
}

void print_word_state(char *word, int *guessed){
    printf("Word: ");
    for (int i = 0; i < strlen(word); i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void update_guesses(char guess, char *word, int *guessed) {
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == guess) {
            guessed[i] = 1;
        }
    }
}

int check_win(int *guessed, int length) {
    for (int i = 0; i < length; i++) {
        if (!guessed[i]) return 0;
    }
    return 1;
}

int main() {
    print_logo();

    char word[MAX_LENGTH];
    choose_random_word(word);

    int word_length = strlen(word);
    int guessed[word_length];
    for (int i = 0; i < word_length; i++) guessed[i] = 0;

    int tries = 0;
    char guess;

    printf("Let's start playing! Try to guess the word!\n");

    while (tries < MAX_TRIES) {
        print_word_state(word, guessed);
        print_attempts(tries);

        printf("Enter your guess (a single letter): ");
        scanf(" %c", &guess);

        if (guess < 'a' || guess > 'z') {
            printf("That's not a letter! Are you trying to outsmart me?\n");
            continue;
        }

        printf("You guessed: %c\n", guess);
        update_guesses(guess, word, guessed);

        if (check_win(guessed, word_length)) {
            printf("Congratulations! You guessed it: %s\n", word);
            break;
        }
        
        tries++;
        printf("Oops! That guess didn't quite hit the mark, try again.\n");
    }
    
    if (tries == MAX_TRIES) {
        printf("Game Over! The word was: %s\n", word);
    }

    printf("Thanks for playing the Wacky Word Guesser! Come back for more fun!\n");
    return 0;
}