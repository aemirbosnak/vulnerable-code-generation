//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // initialize mutex

// function to check for valid alien characters
bool is_valid_char(char c) {
    return c >= 'a' && c <= 'z'; // alien characters can only be lowercase alphabets
}

// struct to hold the translation data
typedef struct {
    char original[100];
    char translated[100];
} translation;

// function to translate an Alien Language string
void  translate_alien_language(char* original, char* translated) {
    int original_len = strlen(original);
    for(int i=0; i<original_len; i++) {
        if(is_valid_char(original[i])) {
            translated[i] = 'a' + ((original[i]-'a') + 3) % 26; // translate each valid character by shifting three positions to the right (wrapping around if necessary)
        } else {
            translated[i] = original[i]; // ignore invalid characters
        }
    }
    translated[original_len] = '\0'; // add null terminator at the end of the translated string
}

// function to process input and output
void* process_data(void* arg) {
    translation* t = (translation*) arg;
    pthread_mutex_lock(&mutex); // acquire mutex before accessing shared variables
    printf("Original string: %s\n", t->original);
    translate_alien_language(t->original, t->translated);
    printf("Translated string: %s\n", t->translated);
    pthread_mutex_unlock(&mutex); // release mutex after accessing shared variables
    return NULL;
}

int main() {
    char input_string[100];
    printf("Enter an Alien Language string (lowercase alphabets only): ");
    scanf("%s", input_string);

    pthread_t thread_id;
    translation t;
    strcpy(t.original, input_string);

    pthread_create(&thread_id, NULL, process_data, &t); // create new thread and start processing data

    pthread_join(thread_id, NULL); // wait for the thread to finish
    
    return 0;
}