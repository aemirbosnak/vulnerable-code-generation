//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_spam;
} Word;

void load_words(Word words[], int num_words) {
    FILE *file = fopen("spam_words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open spam_words.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s", words[i].word)!= EOF && i < num_words) {
        i++;
    }

    fclose(file);
}

int is_spam(char *message, Word words[], int num_words) {
    int num_spam_words = 0;

    char *word = strtok(message, " ");
    while (word!= NULL) {
        int j;
        for (j = 0; j < num_words; j++) {
            if (strcmp(word, words[j].word) == 0) {
                num_spam_words++;
                break;
            }
        }

        word = strtok(NULL, " ");
    }

    return num_spam_words > 0;
}

int main() {
    Word words[MAX_WORDS];
    int num_words = 0;

    load_words(words, MAX_WORDS);
    num_words = MAX_WORDS;

    char message[1024];
    while (fgets(message, sizeof(message), stdin)!= NULL) {
        if (is_spam(message, words, num_words)) {
            printf("SPAM\n");
        } else {
            printf("NOT SPAM\n");
        }
    }

    return 0;
}