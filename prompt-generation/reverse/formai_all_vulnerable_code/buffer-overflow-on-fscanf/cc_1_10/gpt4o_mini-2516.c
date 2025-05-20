//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000

typedef struct WordNode {
    char word[MAX_WORD_LENGTH];
    struct WordNode* next;
} WordNode;

typedef struct {
    WordNode* head;
} Dictionary;

void add_word(Dictionary* dict, const char* word) {
    WordNode* new_node = (WordNode*)malloc(sizeof(WordNode));
    strcpy(new_node->word, word);
    new_node->next = dict->head;
    dict->head = new_node;
}

int search_word(Dictionary* dict, const char* word) {
    WordNode* current = dict->head;
    while (current) {
        if (strcmp(current->word, word) == 0) {
            return 1; // word found
        }
        current = current->next;
    }
    return 0; // word not found
}

void free_dictionary(Dictionary* dict) {
    WordNode* current = dict->head;
    WordNode* next_node;
    while (current) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    dict->head = NULL;
}

void load_dictionary(Dictionary* dict, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file.\n");
        exit(EXIT_FAILURE);
    }
    
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        add_word(dict, word);
    }
    
    fclose(file);
}

void check_spelling(Dictionary* dict, const char* text) {
    char* token = strtok((char*)text, " ,.!?;\n");
    while (token) {
        if (!search_word(dict, token)) {
            printf("Alas! The word '%s' is unrecognized.\n", token);
        }
        token = strtok(NULL, " ,.!?;\n");
    }
}

int main() {
    Dictionary dict = {NULL};
    load_dictionary(&dict, "dictionary.txt");
    
    char input_text[1000];
    printf("Enter the text for spell checking:\n");
    fgets(input_text, sizeof(input_text), stdin);
    
    check_spelling(&dict, input_text);
    
    free_dictionary(&dict);
    return 0;
}