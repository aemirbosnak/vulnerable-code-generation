//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1024
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
    char **words;
    int size;
} Dictionary;

Dictionary* load_dictionary(const char *filename);
bool is_word_correct(Dictionary *dict, const char *word);
void free_dictionary(Dictionary *dict);
void spell_check_text(Dictionary *dict, const char *filename);
void suggest_corrections(const char *word, Dictionary *dict);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    Dictionary *dict = load_dictionary(argv[1]);
    if (dict == NULL) {
        printf("Error loading dictionary file!\n");
        return 1;
    }

    spell_check_text(dict, argv[2]);

    free_dictionary(dict);
    return 0;
}

Dictionary* load_dictionary(const char *filename) {
    Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));
    if (dict == NULL) {
        return NULL;
    }

    dict->words = (char **)malloc(MAX_DICTIONARY_SIZE * sizeof(char *));
    if (dict->words == NULL) {
        free(dict);
        return NULL;
    }

    dict->size = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        free(dict->words);
        free(dict);
        return NULL;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        dict->words[dict->size] = strdup(word);
        dict->size++;
    }
    
    fclose(file);
    return dict;
}

bool is_word_correct(Dictionary *dict, const char *word) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i], word) == 0) {
            return true;
        }
    }
    return false;
}

void free_dictionary(Dictionary *dict) {
    for (int i = 0; i < dict->size; i++) {
        free(dict->words[i]);
    }
    free(dict->words);
    free(dict);
}

void spell_check_text(Dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \n");
        while (token != NULL) {
            if (!is_word_correct(dict, token)) {
                printf("Misspelled word: %s\n", token);
                suggest_corrections(token, dict);
            }
            token = strtok(NULL, " \n");
        }
    }

    fclose(file);
}

void suggest_corrections(const char *word, Dictionary *dict) {
    printf("Suggestions for \"%s\": ", word);
    int suggestions_found = 0;

    for (int i = 0; i < dict->size; i++) {
        if (strlen(dict->words[i]) > 1 && 
            abs((int)strlen(dict->words[i]) - (int)strlen(word)) <= 1) {
            // Check if the word is similar in length
            // and can be a potential suggestion
            printf("\"%s\" ", dict->words[i]);
            suggestions_found++;
        }
    }

    if (suggestions_found == 0) {
        printf("No suggestions available.");
    }
    printf("\n");
}