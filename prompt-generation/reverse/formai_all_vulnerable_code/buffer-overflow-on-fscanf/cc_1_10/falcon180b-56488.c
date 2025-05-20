//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>

// Global variables
char *dictionary[10000];
int num_words = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Function to load dictionary
void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    char word[50];
    while (fscanf(fp, "%s", word)!= EOF) {
        dictionary[num_words++] = strdup(word);
    }

    fclose(fp);
}

// Function to check if a word is in the dictionary
bool is_word(char *word) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            pthread_mutex_unlock(&lock);
            return true;
        }
    }
    pthread_mutex_unlock(&lock);
    return false;
}

// Function to check spelling of a sentence
void check_spelling(char *sentence) {
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        if (!is_word(word)) {
            printf("Misspelled word: %s\n", word);
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    load_dictionary("dictionary.txt");

    char sentence[100];
    printf("Enter a sentence to check spelling: ");
    scanf("%s", sentence);

    check_spelling(sentence);

    return 0;
}