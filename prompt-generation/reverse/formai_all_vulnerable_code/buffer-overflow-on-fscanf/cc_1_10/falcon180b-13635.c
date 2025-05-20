//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct word dictionary[MAX_WORDS];
int dictionary_size = 0;

void load_dictionary(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        struct word* entry = &dictionary[dictionary_size++];
        strcpy(entry->word, word);
        entry->count = 0;
    }

    fclose(fp);
}

void spell_check(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < dictionary_size; i++) {
            int j;
            for (j = 0; j < strlen(dictionary[i].word); j++) {
                if (tolower(word[j])!= tolower(dictionary[i].word[j])) {
                    break;
                }
            }
            if (j == strlen(dictionary[i].word)) {
                printf("%s -> %s\n", word, dictionary[i].word);
                dictionary[i].count++;
                break;
            }
        }
        if (i == dictionary_size) {
            printf("%s: unknown word\n", word);
        }
    }

    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        exit(1);
    }

    load_dictionary(argv[1]);
    spell_check(argv[2]);

    return 0;
}