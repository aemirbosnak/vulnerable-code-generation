//FormAI DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_SIZE 50
#define MAX_MISSPELLED_WORDS 20
#define NUM_PLAYERS 2

// Function to check if two strings are equal
int string_equal(char *str1, char *str2) {
    if(strlen(str1) != strlen(str2))
        return 0;
    return strcmp(str1, str2) == 0;
}

// Function to check if a word is contained in a words array
int contains_word(char **words, int num_words, char *word) {
    for(int i = 0; i < num_words; i++) {
        if(string_equal(words[i], word))
            return 1;
    }
    return 0;
}

// Function to randomly select a word from a list of words
char *random_word(char **words, int n) {
    srand(time(NULL));
    int random_index = rand() % n;
    return words[random_index];
}

// Function to add a word to an array of misspelled words
void add_misspelled_word(char **misspelled_words, int *num_misspelled_words, char *word) {
    misspelled_words[*num_misspelled_words] = malloc(sizeof(char) * (strlen(word) + 1));
    strcpy(misspelled_words[*num_misspelled_words], word);
    (*num_misspelled_words)++;
}

// Function to check if a word is misspelled
int is_misspelled(char **words, int num_words, char *word) {
    if(!contains_word(words, num_words, word))
        return 1;
    return 0;
}

// Function to play the game
void play_game(char **words, int n) {
    char **misspelled_words = malloc(sizeof(char*) * MAX_MISSPELLED_WORDS);
    int num_misspelled_words = 0;

    for(int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d, it's your turn!\n", i+1);

        char *word = random_word(words, n);
        printf("Please enter a word that rhymes with %s: ", word);

        char *input_word = malloc(sizeof(char) * MAX_WORD_SIZE);
        scanf("%s", input_word);

        if(is_misspelled(words, n, input_word)) {
            add_misspelled_word(misspelled_words, &num_misspelled_words, input_word);
            printf("Sorry, that word is misspelled. You have %d misspellings.\n", num_misspelled_words);
        }
        else {
            printf("Nice job, that word is correct! You have a score of %d.\n", i+1);
        }
    }

    printf("Game over! The misspelled words are:\n");
    for(int i = 0; i < num_misspelled_words; i++) {
        printf("%s\n", misspelled_words[i]);
        free(misspelled_words[i]);
    }
    free(misspelled_words);
}

int main() {
    char *words[] = {
        "cat", "bat", "rat", "sat", "hat", "pat",
        "cake", "lake", "bake", "rake", "take", "stake",
        "dog", "frog", "log", "bog", "jog", "cog",
        "bird", "herd", "nerd", "word", "turd", "curd"
    };
    int n = sizeof(words) / sizeof(words[0]);

    play_game(words, n);

    return 0;
}