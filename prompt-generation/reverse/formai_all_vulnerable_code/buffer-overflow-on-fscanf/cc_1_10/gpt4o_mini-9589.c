//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define max lengths for words and translations
#define MAX_WORD_LENGTH 50
#define MAX_TRANSLATION_LENGTH 200
#define DICTIONARY_SIZE 100

// Structure to map alien languages to English
typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} DictionaryEntry;

// Function to translate an English word to Alien
char* translate_to_alien(const char* word, DictionaryEntry dictionary[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(dictionary[i].english, word) == 0) {
            return dictionary[i].alien;
        }
    }
    return "Translation not found!";
}

// Function to translate an Alien word to English
char* translate_to_english(const char* word, DictionaryEntry dictionary[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(dictionary[i].alien, word) == 0) {
            return dictionary[i].english;
        }
    }
    return "Translation not found!";
}

// Function to load dictionary from a file
int load_dictionary(const char* filename, DictionaryEntry dictionary[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open dictionary file");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", dictionary[count].english, dictionary[count].alien) != EOF) {
        count++;
        if (count >= DICTIONARY_SIZE) {
            break; // Avoid overflow
        }
    }
    
    fclose(file);
    return count;
}

// Function to display the menu
void display_menu() {
    printf("Alien Language Translator\n");
    printf("1. Translate English to Alien\n");
    printf("2. Translate Alien to English\n");
    printf("3. Exit\n");
}

int main() {
    DictionaryEntry dictionary[DICTIONARY_SIZE];
    int dictionary_size = load_dictionary("dictionary.txt", dictionary);
    if (dictionary_size == -1) {
        return EXIT_FAILURE;
    }

    int choice;
    char input[MAX_WORD_LENGTH];
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer

        switch (choice) {
            case 1:
                printf("Enter an English word to translate: ");
                fgets(input, MAX_WORD_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline char
                printf("Alien Translation: %s\n", translate_to_alien(input, dictionary, dictionary_size));
                break;
            case 2:
                printf("Enter an Alien word to translate: ");
                fgets(input, MAX_WORD_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline char
                printf("English Translation: %s\n", translate_to_english(input, dictionary, dictionary_size));
                break;
            case 3:
                printf("Exiting the translator.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");

    } while (choice != 3);

    return EXIT_SUCCESS;
}