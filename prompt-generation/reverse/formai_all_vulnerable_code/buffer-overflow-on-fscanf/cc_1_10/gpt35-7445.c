//FormAI DATASET v1.0 Category: Spell checking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_WORDS 1000

char dictionary[MAX_DICT_WORDS][MAX_WORD_LEN];

int dictionary_size;

void load_dictionary(char *filename) {
    FILE *fp;

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error loading dictionary file\n");
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while(fscanf(fp, "%s", word) != EOF && dictionary_size < MAX_DICT_WORDS) {
        strncpy(dictionary[dictionary_size++], word, MAX_WORD_LEN);
        dictionary[dictionary_size-1][strlen(dictionary[dictionary_size-1])] = '\0';
    }

    fclose(fp);
}

int is_valid_word(char *word) {
    for(int i=0; i<dictionary_size; i++) {
        if(strcmp(dictionary[i], word) == 0)
            return 1;
    }
    return 0;
}

void to_lowercase(char *str) {
    for(int i=0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s input-file-name dictionary-file-name\n", argv[0]);
        exit(1);
    }

    load_dictionary(argv[2]);

    FILE *fp;
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Error opening file %s\n",argv[1]);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    int ln = 1, pos = 0, errors = 0;

    while(fscanf(fp, "%s", word) != EOF) {
        to_lowercase(word);

        if(!is_valid_word(word)) {
            errors++;
            printf("Error on line: %d, position: %d, word: %s\n", ln, pos+1, word);
        }

        pos += strlen(word) + 1;
        if(strchr("\n", fgetc(fp)) != NULL) {
            ln++;
            pos = 0;
        }
        fseek(fp, -1, SEEK_CUR);
    }

    printf("\n%d errors found in %s\n", errors, argv[1]);
    fclose(fp);
    return 0;
}