//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_spam;
} Word;

void load_words(Word words[]);
int is_spam(char* message, Word words[]);

int main() {
    Word words[MAX_WORDS];
    load_words(words);

    char message[1000];
    printf("Enter a message: ");
    fgets(message, 1000, stdin);

    int is_spam_result = is_spam(message, words);

    if (is_spam_result) {
        printf("Message is spam.\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}

void load_words(Word words[]) {
    FILE* file = fopen("spam_words.txt", "r");
    if (file == NULL) {
        printf("Error loading spam words.\n");
        exit(1);
    }

    int word_count = 0;
    while (fscanf(file, "%s", words[word_count].word)!= EOF) {
        words[word_count].is_spam = 1;
        word_count++;
    }

    fclose(file);
}

int is_spam(char* message, Word words[]) {
    int word_count = 0;
    int is_spam_result = 0;

    char* word = strtok(message, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < word_count; i++) {
            if (strcmp(word, words[i].word) == 0) {
                is_spam_result = 1;
                break;
            }
        }

        if (is_spam_result == 0) {
            word_count++;
            Word new_word;
            strcpy(new_word.word, word);
            new_word.is_spam = 0;
            words[word_count - 1] = new_word;
        }

        word = strtok(NULL, " ");
    }

    return is_spam_result;
}