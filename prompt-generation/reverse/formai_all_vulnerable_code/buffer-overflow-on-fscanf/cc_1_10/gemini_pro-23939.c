//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

char *dictionary[MAX_WORDS];
int dictionary_size = 0;

pthread_mutex_t dictionary_lock = PTHREAD_MUTEX_INITIALIZER;

void *spell_check(void *arg) {
    char *word = (char *)arg;
    int i;

    pthread_mutex_lock(&dictionary_lock);
    for (i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            pthread_mutex_unlock(&dictionary_lock);
            return NULL;
        }
    }
    pthread_mutex_unlock(&dictionary_lock);

    printf("%s is not in the dictionary.\n", word);
    return NULL;
}

int main() {
    FILE *fp;
    char word[MAX_WORD_LENGTH];
    pthread_t threads[MAX_WORDS];
    int i;

    // Load the dictionary into memory
    fp = fopen("dictionary.txt", "r");
    while (fscanf(fp, "%s", word) != EOF) {
        dictionary[dictionary_size++] = strdup(word);
    }
    fclose(fp);

    // Spell check the words in the input file
    fp = fopen("input.txt", "r");
    while (fscanf(fp, "%s", word) != EOF) {
        pthread_create(&threads[i], NULL, spell_check, (void *)word);
        i++;
    }
    fclose(fp);

    // Wait for all threads to finish
    for (i = 0; i < MAX_WORDS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}