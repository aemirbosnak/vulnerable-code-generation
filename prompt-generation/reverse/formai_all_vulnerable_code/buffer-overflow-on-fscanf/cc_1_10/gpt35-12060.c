//FormAI DATASET v1.0 Category: Spell checking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_WORD_LENGTH 50
#define HASH_SIZE 1000

typedef struct node_struct {
    char word[MAX_WORD_LENGTH];
    struct node_struct *next;
} node_t;

int hash_function(char *word) {
    int hash = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash += tolower(word[i]);
    }
    return hash % HASH_SIZE;
}

node_t *hash_table[HASH_SIZE];

void insert_word(char *word) {
    int hash = hash_function(word);

    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    strcpy(new_node->word, word);
    
    if (hash_table[hash] == NULL) {
        hash_table[hash] = new_node;
    } else {
        new_node->next = hash_table[hash];
        hash_table[hash] = new_node;
    }
}

bool search_table(char *word) {
    int hash = hash_function(word);

    node_t *current_node = hash_table[hash];

    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return true;
        }
        current_node = current_node->next;
    }
    return false;
}

void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    char current_word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", current_word) != EOF) {
        insert_word(current_word);
    }
    fclose(fp);
}

void *spell_check_text(void *input) {
    char *text = (char*)input;
    char current_word[MAX_WORD_LENGTH];
    int text_length = strlen(text);
    int start_index = 0;
    for (int i = 0; i <= text_length; i++) {
        if (text[i] == ' ' || text[i] == '\0') {
            strncpy(current_word, &text[start_index], i - start_index);
            current_word[i - start_index] = '\0';
            if (!search_table(current_word)) {
                printf("Misspelled word: %s\n", current_word);
            }
            start_index = i + 1;
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: ./spell-checker <dictionary file> <text file>\n");
        return 0;
    }

    char *dictionary_filename = argv[1];
    char *text_filename = argv[2];

    load_dictionary(dictionary_filename);

    FILE *fp = fopen(text_filename, "r");
    fseek(fp, 0L, SEEK_END);
    int text_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char *text = (char*)malloc(sizeof(char) * text_size);

    fread(text, sizeof(char), text_size, fp);
    fclose(fp);

    pthread_t spell_check_thread;
    pthread_create(&spell_check_thread, NULL, spell_check_text, (void*)text);

    pthread_join(spell_check_thread, NULL);

    free(text);

    return 0;
}