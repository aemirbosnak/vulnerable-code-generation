//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256
#define MAX_ALIEN_WORDS 100

typedef struct {
    char human[30];
    char alien[30];
} Translation;

// Declare a list of translations
Translation dictionary[MAX_ALIEN_WORDS];
int dict_size = 0;

// Function to trim whitespace
char* trim_whitespace(char* str) {
    char *end;

    while (isspace(*str)) str++; // Trim leading space
    if (*str == 0) return str; // All spaces
    
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--; // Trim trailing space
    *(end + 1) = 0; // Null terminate

    return str;
}

// Load translations from a file
void load_translations(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open translation file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", dictionary[dict_size].human, dictionary[dict_size].alien) == 2) {
        dict_size++;
        if (dict_size >= MAX_ALIEN_WORDS) {
            printf("Warning: Translation dictionary is full!\n");
            break;
        }
    }
    fclose(file);
}

// Translate a human phrase to alien language
void translate_to_alien(const char* human_phrase) {
    char* token = strtok(human_phrase, " ");
    printf("Alien Translation: ");
    int first_token = 1;

    while (token) {
        token = trim_whitespace(token);
        int found = 0;
        for (int i = 0; i < dict_size; i++) {
            if (strcasecmp(token, dictionary[i].human) == 0) {
                if (!first_token) {
                    printf(" ");
                }
                printf("%s", dictionary[i].alien);
                found = 1;
                break;
            }
        }
        if (!found) {
            if (!first_token) {
                printf(" ");
            }
            printf("UNKNOWN");
        }
        first_token = 0;
        token = strtok(NULL, " ");
    }
    printf("\n");
}

// Main function to execute the translator
int main() {
    char human_phrase[MAX_INPUT_LENGTH];
    char translation_file[] = "translations.txt";

    load_translations(translation_file);

    printf("Post-apocalyptic Alien Language Translator\n");
    printf("Enter your phrase to translate (or type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(human_phrase, MAX_INPUT_LENGTH, stdin);
        if (strcmp(trim_whitespace(human_phrase), "exit") == 0) {
            break;
        }

        // Remove the newline character
        human_phrase[strcspn(human_phrase, "\n")] = 0;
        translate_to_alien(human_phrase);
    }

    return 0;
}