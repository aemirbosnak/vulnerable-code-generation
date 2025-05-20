//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define DICTIONARY_FILE "dictionary.txt"
#define INPUT_FILE "input.txt"

void load_dictionary(char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int *count) {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf(file, "%s", dictionary[*count]) != EOF && *count < MAX_WORDS) {
        (*count)++;
    }
    fclose(file);
}

int is_word_in_dictionary(char *word, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int dict_count) {
    for (int i = 0; i < dict_count; i++) {
        if (strcasecmp(word, dictionary[i]) == 0) {
            return 1; // Word found in dictionary
        }
    }
    return 0; // Word not found
}

void check_words(char *text, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int dict_count, int process_id) {
    char *word;
    word = strtok(text, " \n");
    while (word != NULL) {
        // Remove punctuation from word
        for (int i = 0; word[i]; i++) {
            if (ispunct(word[i])) {
                word[i] = '\0';
                break;
            }
        }

        if (!is_word_in_dictionary(word, dictionary, dict_count)) {
            printf("Process %d: Misspelled word: %s\n", process_id, word);
        }
        word = strtok(NULL, " \n");
    }
}

int main() {
    char dictionary[MAX_WORDS][MAX_WORD_LENGTH];
    int dict_count = 0;
    load_dictionary(dictionary, &dict_count);

    FILE *file = fopen(INPUT_FILE, "r");
    if (!file) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    char input_text[1000];
    while (fgets(input_text, sizeof(input_text), file)) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            check_words(input_text, dictionary, dict_count, getpid());
            exit(0);
        } else if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
    }
    fclose(file);

    // Wait for all child processes
    while (wait(NULL) > 0);

    return 0;
}