//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

typedef struct {
    char *word;
    int frequency;
} DictionaryEntry;

typedef struct {
    DictionaryEntry *entries;
    int entry_count;
} Dictionary;

Dictionary *create_dictionary(int size) {
    Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));
    dict->entries = (DictionaryEntry *)malloc(size * sizeof(DictionaryEntry));
    dict->entry_count = 0;
    return dict;
}

void add_word(Dictionary *dict, const char *word) {
    for (int i = 0; i < dict->entry_count; i++) {
        if (strcmp(dict->entries[i].word, word) == 0) {
            dict->entries[i].frequency++;
            return;
        }
    }
    dict->entries[dict->entry_count].word = strdup(word);
    dict->entries[dict->entry_count].frequency = 1;
    dict->entry_count++;
}

int compare(const void *a, const void *b) {
    DictionaryEntry *entryA = (DictionaryEntry *)a;
    DictionaryEntry *entryB = (DictionaryEntry *)b;
    return entryB->frequency - entryA->frequency; // Sort by frequency, descending
}

void display_dictionary(Dictionary *dict) {
    qsort(dict->entries, dict->entry_count, sizeof(DictionaryEntry), compare);
    printf("Spell Check Report:\n");
    for (int i = 0; i < dict->entry_count; i++) {
        printf("%s: %d\n", dict->entries[i].word, dict->entries[i].frequency);
    }
}

void free_dictionary(Dictionary *dict) {
    for (int i = 0; i < dict->entry_count; i++) {
        free(dict->entries[i].word);
    }
    free(dict->entries);
    free(dict);
}

int is_alpha_numeric(const char c) {
    return isalnum(c) || c == '-';
}

void process_text_file(const char *filename, Dictionary *dict) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        char *word_start = NULL;
        for (int i = 0, len = strlen(buffer); i <= len; i++) {
            if (is_alpha_numeric(buffer[i])) {
                if (!word_start) {
                    word_start = &buffer[i];
                }
            } else {
                if (word_start) {
                    buffer[i] = '\0'; // Terminate the word
                    add_word(dict, word_start);
                    word_start = NULL;
                }
            }
        }
    }
    fclose(file);
}

void interactive_spell_check(Dictionary *dict) {
    char user_input[MAX_WORD_LENGTH];
    printf("Enter a word to check (type 'exit' to quit): ");
    
    while (1) {
        fgets(user_input, MAX_WORD_LENGTH, stdin);
        user_input[strcspn(user_input, "\n")] = 0; // Remove newline character

        if (strcmp(user_input, "exit") == 0) {
            break;
        }

        for (int i = 0; i < dict->entry_count; i++) {
            if (strcmp(dict->entries[i].word, user_input) == 0) {
                printf("The word '%s' is correct! Found %d times.\n", user_input, dict->entries[i].frequency);
                break;
            }
            if (i == dict->entry_count - 1) {
                printf("The word '%s' is not in the dictionary.\n", user_input);
            }
        }
        printf("Enter a word to check (type 'exit' to quit): ");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <textfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Dictionary *dictionary = create_dictionary(MAX_WORDS);
    process_text_file(argv[1], dictionary);
    display_dictionary(dictionary);
    interactive_spell_check(dictionary);
    free_dictionary(dictionary);

    return EXIT_SUCCESS;
}