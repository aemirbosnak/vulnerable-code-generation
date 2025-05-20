//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 32
#define MAX_SENTENCE_LENGTH 256

// Struct for English-Cat Language dictionary
typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} Dictionary;

// Function declarations
void load_dictionary(Dictionary *dict, int *size);
void translate_sentence(char *sentence, Dictionary *dict, int dict_size);
void to_lower_case(char *str);

int main() {
    // Initialize dictionary
    Dictionary dict[MAX_WORDS];
    int dict_size = 0;

    // Load dictionary from file
    load_dictionary(dict, &dict_size);
    
    // Get user input
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence in English to translate to Cat Language:\n");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Remove newline character at the end
    sentence[strcspn(sentence, "\n")] = 0;

    // Translate and print the result
    translate_sentence(sentence, dict, dict_size);
    
    return 0;
}

// Load dictionary from a file
void load_dictionary(Dictionary *dict, int *size) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", dict[*size].english, dict[*size].cat) != EOF) {
        (*size)++;
    }

    fclose(file);
}

// Translate the input sentence
void translate_sentence(char *sentence, Dictionary *dict, int dict_size) {
    char *word = strtok(sentence, " ");
    printf("Translation in Cat Language:\n");
    
    while (word != NULL) {
        char lower_word[MAX_WORD_LENGTH];
        strcpy(lower_word, word);
        to_lower_case(lower_word);

        int found = 0;
        for (int i = 0; i < dict_size; i++) {
            if (strcmp(lower_word, dict[i].english) == 0) {
                printf("%s ", dict[i].cat);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%s ", word); // If not found, print the original word
        }

        word = strtok(NULL, " ");
    }

    printf("\n");
}

// Convert string to lowercase
void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}