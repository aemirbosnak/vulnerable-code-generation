//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_words(char* filename, WordCount words[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
        }
    }

    fclose(file);
}

void sort_words(WordCount words[]) {
    int i, j;
    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (words[j].count > words[i].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_words(WordCount words[]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char input_filename[MAX_WORD_LEN];
    char output_filename[MAX_WORD_LEN];
    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);

    WordCount words[MAX_WORDS];
    read_words(input_filename, words);
    sort_words(words);
    print_words(words);

    return 0;
}