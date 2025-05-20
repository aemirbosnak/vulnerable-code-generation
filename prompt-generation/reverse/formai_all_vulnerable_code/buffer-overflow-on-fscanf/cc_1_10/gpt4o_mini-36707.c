//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define DICTIONARY_SIZE 100

typedef struct {
    char *english;
    char *alien;
} TranslationEntry;

TranslationEntry dictionary[DICTIONARY_SIZE];
int entry_count = 0;

void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%ms %ms", &dictionary[entry_count].english, &dictionary[entry_count].alien) == 2) {
        entry_count++;
        if (entry_count >= DICTIONARY_SIZE) {
            fprintf(stderr, "Dictionary is full, increasing size limit needed!\n");
            break;
        }
    }
    fclose(file);
}

char *translate_word(const char *word) {
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(dictionary[i].english, word) == 0) {
            return dictionary[i].alien;
        }
    }
    return NULL; // Word not found
}

void translate_sentence(const char *sentence, char *translated) {
    char buffer[BUFFER_SIZE];
    char *token;
    char *sentence_copy = strdup(sentence);
    char *ptr = translated;

    token = strtok(sentence_copy, " ");
    while (token != NULL) {
        char *translated_word = translate_word(token);
        if (translated_word != NULL) {
            ptr += sprintf(ptr, "%s ", translated_word);
        } else {
            ptr += sprintf(ptr, "%s ", token); // Keep original
        }
        token = strtok(NULL, " ");
    }
    free(sentence_copy);
    *ptr = '\0'; // Null terminate the translated string
}

void print_translation(const char *sentence) {
    char translated[BUFFER_SIZE] = {0};
    translate_sentence(sentence, translated);
    printf("Translated: %s\n", translated);
}

void free_dictionary() {
    for (int i = 0; i < entry_count; i++) {
        free(dictionary[i].english);
        free(dictionary[i].alien);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dictionary_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_dictionary(argv[1]);

    char input_sentence[BUFFER_SIZE];
    printf("Enter an English sentence to translate to Alien language (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        if (fgets(input_sentence, sizeof(input_sentence), stdin) == NULL) {
            break; // Handle EOF
        }

        if (strcmp(input_sentence, "exit\n") == 0) {
            break;
        }

        // Remove newline character from input
        input_sentence[strcspn(input_sentence, "\n")] = 0;

        print_translation(input_sentence);
    }

    free_dictionary();
    return EXIT_SUCCESS;
}