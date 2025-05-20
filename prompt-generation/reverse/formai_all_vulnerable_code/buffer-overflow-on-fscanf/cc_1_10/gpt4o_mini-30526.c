//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordEntry;

WordEntry dictionary[MAX_WORDS];
int dict_size = 0;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

int is_in_dictionary(const char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

void add_to_dictionary(const char *word) {
    if (dict_size < MAX_WORDS) {
        dictionary[dict_size].word = strdup(word);
        dictionary[dict_size].count = 1;
        dict_size++;
    }
}

void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open dictionary file");
        exit(EXIT_FAILURE);
    }
    
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        to_lowercase(word);
        add_to_dictionary(word);
    }
    fclose(file);
}

void spell_check(const char *text) {
    char *word = strtok((char *)text, " \n,.!?()[]{};:\"");
    while (word != NULL) {
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, word);
        to_lowercase(temp);
        if (!is_in_dictionary(temp)) {
            printf("Misspelled: %s\n", word);
        }
        word = strtok(NULL, " \n,.!?()[]{};:\"");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    load_dictionary(argv[1]);

    FILE *text_file = fopen(argv[2], "r");
    if (!text_file) {
        perror("Failed to open text file");
        return 1;
    }
    
    fseek(text_file, 0, SEEK_END);
    long size = ftell(text_file);
    fseek(text_file, 0, SEEK_SET);

    char *text_content = (char *)malloc(size + 1);
    fread(text_content, 1, size, text_file);
    text_content[size] = '\0';
    fclose(text_file);

    printf("Spell Checking:\n");
    spell_check(text_content);

    free(text_content);
    for (int i = 0; i < dict_size; i++) {
        free(dictionary[i].word);
    }

    return 0;
}