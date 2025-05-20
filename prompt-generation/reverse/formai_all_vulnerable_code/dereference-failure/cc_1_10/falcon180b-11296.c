//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare_ignore_case(const void *a, const void *b) {
    return strcasecmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char sentence[MAX_SENTENCE_LENGTH];
    WordCount word_counts[26] = {0}; // assuming 26 letters in the English alphabet

    while (fgets(sentence, MAX_SENTENCE_LENGTH, file)!= NULL) {
        int sentence_length = strlen(sentence);
        int word_count = 0;
        char *word = strtok(sentence, " ");
        while (word!= NULL) {
            if (strlen(word) > MAX_WORD_LENGTH) {
                printf("Error: word '%s' is too long.\n", word);
                return 1;
            }
            if (isalpha(word[0])) {
                char first_letter = toupper(word[0]);
                word_counts[first_letter - 'A'].count++;
            }
            word = strtok(NULL, " ");
            word_count++;
        }
        if (word_count == 0) {
            printf("Error: empty sentence.\n");
            return 1;
        }
        if (word_count > 1) {
            printf("Sentence with %d words:\n", word_count);
        }
        for (int i = 0; i < 26; i++) {
            if (word_counts[i].count > 0) {
                printf("%c: %d\n", 'A' + i, word_counts[i].count);
            }
        }
    }

    fclose(file);
    return 0;
}