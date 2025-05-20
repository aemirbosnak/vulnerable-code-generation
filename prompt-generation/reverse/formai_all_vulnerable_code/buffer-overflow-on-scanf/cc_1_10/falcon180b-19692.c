//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compare_words(const void *a, const void *b) {
    struct word_frequency *word1 = (struct word_frequency *)a;
    struct word_frequency *word2 = (struct word_frequency *)b;

    return strcmp(word1->word, word2->word);
}

void print_word_frequency(struct word_frequency *word_frequency, int num_words) {
    qsort(word_frequency, num_words, sizeof(struct word_frequency), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequency[i].word, word_frequency[i].frequency);
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char ch;
    int word_count = 0;
    struct word_frequency word_frequency[MAX_WORDS];

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            int word_length = 0;
            char word[MAX_WORD_LENGTH];

            while (isalpha(ch)) {
                word[word_length++] = tolower(ch);
                ch = fgetc(file);
            }

            word[word_length] = '\0';

            for (int i = 0; i < word_count; i++) {
                if (strcmp(word_frequency[i].word, word) == 0) {
                    word_frequency[i].frequency++;
                    break;
                }
            }

            if (word_count >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }

            strcpy(word_frequency[word_count].word, word);
            word_frequency[word_count].frequency = 1;
            word_count++;
        }
    }

    fclose(file);

    print_word_frequency(word_frequency, word_count);

    return 0;
}