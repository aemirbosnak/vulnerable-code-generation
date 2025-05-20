//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCES 1000
#define MAX_WORDS 5000

typedef struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_sentences(char *filename, char sentences[MAX_SENTENCES][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    int sentence_count = 0;
    char sentence[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", sentence)!= EOF) {
        strcpy(sentences[sentence_count], sentence);
        sentence_count++;
    }

    fclose(file);
}

void count_words(char sentences[MAX_SENTENCES][MAX_WORD_LENGTH], WordCount words[MAX_WORDS]) {
    int word_count = 0;

    for (int i = 0; i < MAX_SENTENCES; i++) {
        char *sentence = sentences[i];
        char *word = strtok(sentence, " ");

        while (word!= NULL) {
            int found = 0;

            for (int j = 0; j < word_count; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                if (word_count >= MAX_WORDS - 1) {
                    printf("Maximum number of unique words reached.\n");
                    break;
                }

                strcpy(words[word_count].word, word);
                words[word_count].count = 1;
                word_count++;
            }

            word = strtok(NULL, " ");
        }
    }
}

void print_word_counts(WordCount words[MAX_WORDS]) {
    printf("Word Count:\n");

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char sentences[MAX_SENTENCES][MAX_WORD_LENGTH];
    read_sentences(argv[1], sentences);

    WordCount words[MAX_WORDS];
    count_words(sentences, words);

    print_word_counts(words);

    return 0;
}