//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

char words[MAX_WORDS][MAX_WORD_LENGTH];
int frequency[MAX_WORDS];
int num_words = 0;

void sanitize_word(char *word) {
    int len = strlen(word);
    if (len > MAX_WORD_LENGTH) {
        word[MAX_WORD_LENGTH - 1] = '\0';
        len = MAX_WORD_LENGTH - 1;
    }
    for (int i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            word[i] = '\0';
            len = i;
            break;
        }
        word[i] = tolower(word[i]);
    }
}

int lookup_word(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], word) == 0) {
            return i;
        }
    }
    return -1;
}

void add_word(char *word) {
    sanitize_word(word);
    if (strlen(word) == 0) {
        return;
    }
    int index = lookup_word(word);
    if (index >= 0) {
        frequency[index]++;
    } else {
        strcpy(words[num_words], word);
        frequency[num_words] = 1;
        num_words++;
    }
}

void sort_words() {
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char temp[MAX_WORD_LENGTH];
                int temp_freq = frequency[i];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
                frequency[i] = frequency[j];
                frequency[j] = temp_freq;
            }
        }
    }
}

void print_words() {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], frequency[i]);
    }
}

int main() {
    char buffer[MAX_WORD_LENGTH];
    while (scanf("%s", buffer) != EOF) {
        add_word(buffer);
    }
    sort_words();
    print_words();
    return 0;
}