//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void read_words(struct word_frequency *words, int max_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open words.txt\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s", words[num_words].word) == 1) {
        num_words++;
        if (num_words == max_words) {
            break;
        }
    }

    fclose(file);
}

void count_words(struct word_frequency *words, int max_words, char *text) {
    int num_words = 0;

    char *word = strtok(text, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }

        if (i == num_words) {
            if (num_words < max_words) {
                strcpy(words[num_words].word, word);
                words[num_words].frequency = 1;
                num_words++;
            }
        }

        word = strtok(NULL, " ");
    }
}

void print_words(struct word_frequency *words, int num_words) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    struct word_frequency words[MAX_WORDS];
    read_words(words, MAX_WORDS);

    char text[100000];
    printf("Enter text to analyze:\n");
    fgets(text, sizeof(text), stdin);

    count_words(words, MAX_WORDS, text);

    print_words(words, MAX_WORDS);

    return 0;
}