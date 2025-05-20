//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int word_counts[MAX_WORDS] = {0};
    struct word_count words[MAX_WORDS];
    int num_words = 0;

    char word[MAX_WORD_LENGTH];
    char *token;
    size_t len;
    while ((token = strtok_r(NULL, ",.?!;:\"'", &len))!= NULL) {
        if (len == 0) {
            continue;
        }

        strncpy(word, token, MAX_WORD_LENGTH);
        word[MAX_WORD_LENGTH - 1] = '\0';

        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (num_words == MAX_WORDS) {
            printf("Error: Too many unique words.\n");
            fclose(file);
            return 1;
        }

        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word)!= 0) {
                strcpy(words[num_words].word, word);
                words[num_words].count = 1;
                num_words++;
                break;
            }
        }
    }

    fclose(file);

    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}