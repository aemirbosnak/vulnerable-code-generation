//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALIEN_WORD_LENGTH 50
#define MAX_ALIEN_DICTIONARY_SIZE 100

// Alien language dictionary
struct AlienDictionaryEntry {
    char alien_word[MAX_ALIEN_WORD_LENGTH];
    char human_word[MAX_ALIEN_WORD_LENGTH];
};

// Alien dictionary
struct AlienDictionary {
    struct AlienDictionaryEntry entries[MAX_ALIEN_DICTIONARY_SIZE];
    int size;
};

// Function to load the alien dictionary from a file
void load_alien_dictionary(struct AlienDictionary *dictionary, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening alien dictionary file");
        exit(EXIT_FAILURE);
    }

    // Read the number of entries in the dictionary
    int num_entries;
    fscanf(file, "%d\n", &num_entries);

    // Read each entry from the dictionary
    for (int i = 0; i < num_entries; i++) {
        fscanf(file, "%s %s\n", dictionary->entries[i].alien_word, dictionary->entries[i].human_word);
    }

    // Close the file
    fclose(file);

    // Set the size of the dictionary
    dictionary->size = num_entries;
}

// Function to translate an alien word to human language
char *translate_alien_word(struct AlienDictionary *dictionary, char *alien_word) {
    // Search for the alien word in the dictionary
    for (int i = 0; i < dictionary->size; i++) {
        if (strcmp(alien_word, dictionary->entries[i].alien_word) == 0) {
            return dictionary->entries[i].human_word;
        }
    }

    // The alien word was not found in the dictionary
    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided an alien dictionary file
    if (argc < 2) {
        printf("Usage: %s <alien_dictionary_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Load the alien dictionary
    struct AlienDictionary dictionary;
    load_alien_dictionary(&dictionary, argv[1]);

    // Get the alien word to be translated
    char alien_word[MAX_ALIEN_WORD_LENGTH];
    printf("Enter the alien word to be translated: ");
    scanf("%s", alien_word);

    // Translate the alien word
    char *human_word = translate_alien_word(&dictionary, alien_word);

    // Print the human translation
    if (human_word != NULL) {
        printf("The human translation of '%s' is '%s'\n", alien_word, human_word);
    } else {
        printf("The alien word '%s' was not found in the dictionary\n", alien_word);
    }

    return EXIT_SUCCESS;
}