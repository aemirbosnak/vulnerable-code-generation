//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int index;
} Word;

typedef struct {
    Word *words;
    int num_words;
    int size;
} Dictionary;

Dictionary *create_dictionary() {
    Dictionary *dict = malloc(sizeof(Dictionary));
    dict->words = malloc(MAX_SIZE * sizeof(Word));
    dict->num_words = 0;
    dict->size = MAX_SIZE;
    return dict;
}

void destroy_dictionary(Dictionary *dict) {
    free(dict->words);
    free(dict);
}

int load_dictionary(Dictionary *dict, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }
    int word_len;
    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        word_len = strlen(word);
        if (word_len > MAX_WORD_LEN) {
            printf("Error: word %s is too long (max %d characters)\n", word, MAX_WORD_LEN);
            fclose(file);
            return 1;
        }
        Word *new_word = malloc(sizeof(Word));
        strcpy(new_word->word, word);
        new_word->index = dict->num_words;
        dict->words[dict->num_words++] = *new_word;
    }
    fclose(file);
    return 0;
}

int search_dictionary(Dictionary *dict, char *query) {
    int i = 0;
    while (i < dict->num_words) {
        if (strcmp(dict->words[i].word, query) == 0) {
            printf("Found %s at index %d\n", dict->words[i].word, dict->words[i].index);
            return 0;
        }
        i++;
    }
    printf("Not found\n");
    return 1;
}

int main() {
    Dictionary *dict = create_dictionary();
    load_dictionary(dict, "dictionary.txt");
    char query[MAX_WORD_LEN];
    printf("Enter a word to search for: ");
    scanf("%s", query);
    search_dictionary(dict, query);
    destroy_dictionary(dict);
    return 0;
}