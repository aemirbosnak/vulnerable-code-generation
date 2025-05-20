//GPT-4o-mini DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_WORDS 100
#define MAX_LENGTH 20
#define MAX_TRIES 7

char *words[MAX_WORDS] = {
    "elephant", "giraffe", "dolphin", "kangaroo", "penguin",
    "panda", "crocodile", "flamingo", "zebra", "chimpanzee",
    "lion", "tiger", "bear", "wolf", "fox",
    "rabbit", "squirrel", "otter", "deer", "moose",
    "koala", "sloth", "armadillo", "anteater", "rhino"
};

void print_welcome_message() {
    printf("===================================\n");
    printf("WELCOME TO THE ANIMAL HANGMAN GAME \n");
    printf("===================================\n");
    printf("Guess the animal name by selecting letters!\n");
    printf("You have %d tries to guess the word.\n", MAX_TRIES);
    printf("===================================\n\n");
}

void print_word(char *word, int *guessed) {
    for (int i = 0; i < strlen(word); i++) {
        if (guessed[i])
            printf("%c ", word[i]);
        else
            printf("_ ");
    }
    printf("\n");
}

void print_hangman(int tries) {
    switch (tries) {
        case 0:
            printf("\n  _______\n");
            printf(" |/      |\n");
            printf(" |      \n");
            printf(" |      \n");
            printf(" |      \n");
            printf(" |      \n");
            printf("_|___\n");
            break;
        case 1:
            printf("\n  _______\n");
            printf(" |/      |\n");
            printf(" |      O\n");
            printf(" |      \n");
            printf(" |      \n");
            printf(" |      \n");
            printf("_|___\n");
            break;
        case 2:
            printf("\n  _______\n");
            printf(" |/      |\n");
            printf(" |      O\n");
            printf(" |      |\n");
            printf(" |      \n");
            printf(" |      \n");
            printf("_|___\n");
            break;
        case 3:
            printf("\n  _______\n");
            printf(" |/      |\n");
            printf(" |      O\n");
            printf(" |     /|\n");
            printf(" |      \n");
            printf(" |      \n");
            printf("_|___\n");
            break;
        case 4:
            printf("\n  _______\n");
            printf(" |/      |\n");
            printf(" |      O\n");
            printf(" |     /|\\\n");
            printf(" |      \n");
            printf(" |      \n");
            printf("_|___\n");
            break;
        case 5:
            printf("\n  _______\n");
            printf(" |/      |\n");
            printf(" |      O\n");
            printf(" |     /|\\\n");
            printf(" |     /\n");
            printf(" |      \n");
            printf("_|___\n");
            break;
        case 6:
            printf("\n  _______\n");
            printf(" |/      |\n");
            printf(" |      O\n");
            printf(" |     /|\\\n");
            printf(" |     / \\\n");
            printf(" |      \n");
            printf("_|___\n");
            break;
        default:
            break;
    }
}

char* choose_word() {
    srand(time(NULL));
    return words[rand() % MAX_WORDS];
}

int main() {
    char *chosen_word = choose_word();
    int length = strlen(chosen_word);
    int guessed[MAX_LENGTH] = {0};
    int tries = 0;
    char guess;
    
    print_welcome_message();

    while (tries < MAX_TRIES) {
        print_hangman(tries);
        print_word(chosen_word, guessed);
        
        printf("Guess a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);
        
        int found = 0;
        for (int i = 0; i < length; i++) {
            if (chosen_word[i] == guess) {
                guessed[i] = 1;
                found = 1;
            }
        }

        if (!found) {
            tries++;
            printf("Wrong guess! You have %d tries left.\n", MAX_TRIES - tries);
        }

        int won = 1;
        for (int i = 0; i < length; i++)
            if (!guessed[i]) {
                won = 0;
                break;
            }

        if (won) {
            printf("\nCongratulations! You've guessed the word: %s\n", chosen_word);
            break;
        }
    }

    if (tries == MAX_TRIES) {
        print_hangman(tries);
        printf("\nSorry! You've run out of tries. The word was: %s\n", chosen_word);
    }

    return 0;
}