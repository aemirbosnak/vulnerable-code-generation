//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICT_LENGTH 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} DictEntry;

void sanitise_word(char* word) {
    int length = strlen(word);

    for(int i = 0; i < length; ++i) {
        word[i] = tolower(word[i]);
    }

    if(ispunct(word[length - 1])) {
        word[length - 1] = '\0';
    }
}

int linear_search(DictEntry* dictionary, char* word, int length) {
    for(int i = 0; i < length; ++i) {
        if(strcmp(dictionary[i].word, word) == 0) {
            return i;
        }
    }

    return -1;
}

void insert_word(DictEntry* dictionary, char* word, int* length) {
    sanitise_word(word);

    int index = linear_search(dictionary, word, *length);

    if(index != -1) {
        dictionary[index].count += 1;
    } else if(*length < MAX_DICT_LENGTH) {
        strncpy(dictionary[*length].word, word, MAX_WORD_LENGTH);
        dictionary[*length].count = 1;
        (*length)++;
    }
}

void print_dictionary(DictEntry* dictionary, int length) {
    printf("Frequency Counter Results:\n\n");

    for(int i = 0; i < length; ++i) {
        printf("%s: %d\n", dictionary[i].word, dictionary[i].count);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please specify a file path\n");
        return 1;
    }

   // Open File
    FILE* fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }

    // Read text from file and split it into words
    DictEntry dictionary[MAX_DICT_LENGTH];
    char word[MAX_WORD_LENGTH];
    int dict_length = 0;

    while(fscanf(fp, "%s", word) == 1) {
        insert_word(dictionary, word, &dict_length);
    }

    // Close file and print results
    fclose(fp);
    print_dictionary(dictionary, dict_length);

    return 0;
}