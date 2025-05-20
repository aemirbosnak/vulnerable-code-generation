//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100
#define SPAM_THRESHOLD 0.5

typedef struct {
    char *word;
    int is_spam;
} Word;

void load_words(Word words[], int num_words, char filename[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s", words[i].word)!= EOF) {
        i++;
        if (i >= num_words) {
            printf("Too many words in file.\n");
            exit(1);
        }
    }

    for (i = 0; i < num_words; i++) {
        words[i].is_spam = 0;
    }

    fclose(file);
}

int is_spam(Word words[], int num_words, char *message) {
    int spam_count = 0;

    char *word = strtok(message, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].is_spam = 1;
                spam_count++;
            }
        }
        word = strtok(NULL, " ");
    }

    double spam_ratio = (double)spam_count / num_words;
    return spam_ratio >= SPAM_THRESHOLD;
}

int main() {
    Word words[MAX_NUM_WORDS];
    int num_words = 0;

    load_words(words, MAX_NUM_WORDS, "spam_words.txt");
    num_words = MAX_NUM_WORDS;

    char message[MAX_WORD_LENGTH];
    printf("Enter message to check for spam: ");
    fgets(message, MAX_WORD_LENGTH, stdin);

    if (is_spam(words, num_words, message)) {
        printf("Message is spam.\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}