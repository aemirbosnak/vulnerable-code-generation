//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_spam;
} word_t;

void load_words(char* filename, word_t words[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s", words[num_words].word)!= EOF) {
        words[num_words].is_spam = 0;
        num_words++;
    }

    fclose(file);
}

int is_spam(char* message, word_t words[]) {
    int num_spam_words = 0;

    char* tokens = strtok(message, " ");
    while (tokens!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(tokens, words[i].word) == 0) {
                words[i].is_spam = 1;
                num_spam_words++;
                break;
            }
        }
        tokens = strtok(NULL, " ");
    }

    return num_spam_words > 0;
}

int main() {
    word_t words[MAX_WORDS];
    load_words("spam_words.txt", words);

    char message[MAX_WORD_LENGTH];
    printf("Enter message: ");
    fgets(message, MAX_WORD_LENGTH, stdin);

    if (is_spam(message, words)) {
        printf("Message is spam\n");
    } else {
        printf("Message is not spam\n");
    }

    return 0;
}