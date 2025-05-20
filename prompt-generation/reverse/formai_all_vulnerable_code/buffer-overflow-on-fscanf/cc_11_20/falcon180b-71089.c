//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    struct word_count words[MAX_WORDS];
    int num_words = 0;
    char word[MAX_WORD_LENGTH];
    int word_length = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words\n");
            fclose(file);
            return 1;
        }

        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }

        word_length = strlen(word);
        if (word_length > MAX_WORD_LENGTH) {
            word_length = MAX_WORD_LENGTH;
        }

        strncpy(words[num_words].word, word, word_length);
        words[num_words].word[word_length] = '\0';
        words[num_words].count = 1;
        num_words++;
    }

    fclose(file);

    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }

    printf("Total words: %d\n", num_words);

    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}