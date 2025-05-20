//FormAI DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define DICT_SIZE 100

typedef struct DictNode {
    char word[MAX_WORD_LEN+1];
    struct DictNode* next;
} DictNode;

DictNode* create_dict_node(char* word) {
    DictNode* node = (DictNode*) malloc(sizeof(DictNode));
    strncpy(node->word, word, MAX_WORD_LEN);
    node->next = NULL;
    return node;
}

void insert_dict_word(DictNode* dict[], char* word) {
    int idx = tolower(word[0]) - 'a';
    if (dict[idx] == NULL) {
        dict[idx] = create_dict_node(word);
    }
    else {
        DictNode* trav = dict[idx];
        while (trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = create_dict_node(word);
    }
}

int is_word_in_dict(DictNode* dict[], char* word) {
    int idx = tolower(word[0]) - 'a';
    DictNode* trav = dict[idx];
    while (trav != NULL) {
        if (strcmp(trav->word, word) == 0) {
            return 1;
        }
        trav = trav->next;
    }
    return 0;
}

void free_dict(DictNode* dict[]) {
    for (int i = 0; i < DICT_SIZE; i++) {
        DictNode* curr = dict[i];
        while (curr != NULL) {
            DictNode* next = curr->next;
            free(curr);
            curr = next;
        }
    }
}

void check_file(DictNode* dict[], char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    char c = fgetc(fp);
    char word[MAX_WORD_LEN+1];
    int word_idx = 0;
    int line_num = 1;
    while (c != EOF) {
        if (c == '\n') {
            line_num++;
        }
        else if (isalpha(c)) {
            word[word_idx++] = c;
            while (isalpha(c = fgetc(fp))) {
                word[word_idx++] = c;
            }
            word[word_idx] = '\0';

            if (!is_word_in_dict(dict, word)) {
                printf("Error at line %d: %s is not a valid word in dictionary\n", line_num, word);
            }
            word_idx = 0;
            continue;
        }
        c = fgetc(fp);
    }
    fclose(fp);
}

int main() {
    DictNode* dict[DICT_SIZE] = {NULL};

    // Load dictionary file
    FILE* fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open dictionary file\n");
        free_dict(dict);
        return -1;
    }

    char word[MAX_WORD_LEN+1];
    while (fscanf(fp, "%s", word) == 1) {
        insert_dict_word(dict, word);
    }

    fclose(fp);

    // Check spelling of input file
    check_file(dict, "input.txt");

    // Free dictionary memory
    free_dict(dict);

    return 0;
}