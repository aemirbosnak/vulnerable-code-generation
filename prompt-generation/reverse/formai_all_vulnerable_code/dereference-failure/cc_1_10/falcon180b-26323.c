//Falcon-180B DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

char* words[MAX_WORDS];
int num_words = 0;

void add_word(char* word) {
    if (num_words >= MAX_WORDS) {
        printf("Error: Maximum number of words (%d) reached.\n", MAX_WORDS);
        return;
    }
    words[num_words++] = strdup(word);
}

void process_text(char* text) {
    char* token;
    char* line = strdup(text);
    char* word = strtok_r(line, " \t\n", &token);
    while (word!= NULL) {
        add_word(word);
        word = strtok_r(NULL, " \t\n", &token);
    }
    free(line);
}

void print_words() {
    if (num_words == 0) {
        printf("No words found.\n");
        return;
    }
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }
}

int main() {
    char* text = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter text to process (press Ctrl+D to finish):\n");
    while ((read = getline(&text, &len, stdin))!= -1) {
        if (text[read - 1] == '\n') {
            text[read - 1] = '\0';
            process_text(text);
            text = NULL;
            len = 0;
        } else {
            text = realloc(text, len + read + 1);
            strncat(text, "\n", len + read + 1 - 1);
        }
    }
    if (text!= NULL) {
        process_text(text);
    }
    print_words();
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    return 0;
}