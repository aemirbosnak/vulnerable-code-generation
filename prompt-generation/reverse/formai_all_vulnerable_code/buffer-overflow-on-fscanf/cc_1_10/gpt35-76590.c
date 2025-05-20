//FormAI DATASET v1.0 Category: Spell checking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_WORD_LEN 256  // maximum word length to check
#define DICT_ENTRIES 1024 // number of entries in the dictionary

char *dictionary[DICT_ENTRIES]; // dictionary of words
int dict_size = 0;              // number of words in the dictionary
pthread_mutex_t mutex_dict;     // mutex to protect access to the dictionary
pthread_mutex_t mutex_file;     // mutex to protect access to the file

/**
 * Load the dictionary from a file
 */
void load_dictionary(char *filename) {
    FILE *fp;
    char *word = malloc(MAX_WORD_LEN * sizeof(char)); // allocate memory for a word

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    pthread_mutex_lock(&mutex_dict); // acquire the dictionary lock

    while (fgets(word, MAX_WORD_LEN, fp) != NULL) {
        // remove trailing newline character from the word
        word[strlen(word) - 1] = '\0';

        // allocate memory for the word in the dictionary and add it
        dictionary[dict_size++] = strdup(word);
    }

    pthread_mutex_unlock(&mutex_dict); // release the dictionary lock
}

/**
 * Spell check a given word
 */
void *spell_check(void *arg) {
    char *word = (char*) arg; // cast argument to char*

    // convert the word to lowercase
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }

    pthread_mutex_lock(&mutex_dict); // acquire the dictionary lock

    // check if the word is in the dictionary
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            pthread_mutex_unlock(&mutex_dict); // release the dictionary lock
            return NULL;
        }
    }

    pthread_mutex_unlock(&mutex_dict); // release the dictionary lock

    // word not found, print error message
    printf("Spelling error: %s\n", word);

    return NULL;
}

/**
 * Read a file and spell check its content
 */
void spell_check_file(char *filename) {
    FILE *fp;
    char *word = malloc(MAX_WORD_LEN * sizeof(char)); // allocate memory for a word

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    pthread_mutex_lock(&mutex_file); // acquire the file lock

    while (fscanf(fp, "%s", word) == 1) {
        // create a thread to spell check the word
        pthread_t tid;
        pthread_create(&tid, NULL, spell_check, word);

        // wait for the thread to finish
        pthread_join(tid, NULL);
    }

    pthread_mutex_unlock(&mutex_file); // release the file lock
}

int main(int argc, char *argv[]) {
    // check arguments
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <input_file>\n", argv[0]);
        return 1;
    }

    // initialize the mutexes
    pthread_mutex_init(&mutex_dict, NULL);
    pthread_mutex_init(&mutex_file, NULL);

    // load the dictionary
    load_dictionary(argv[1]);

    // spell check the input file
    spell_check_file(argv[2]);

    // destroy the mutexes
    pthread_mutex_destroy(&mutex_dict);
    pthread_mutex_destroy(&mutex_file);

    return 0;
}