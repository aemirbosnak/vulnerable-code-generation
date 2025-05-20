//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHRASES 100
#define MAX_LENGTH 256

// Structure to hold translations
typedef struct {
    char english[MAX_LENGTH];
    char alien[MAX_LENGTH];
} Translation;

Translation translations[MAX_PHRASES];
int translation_count = 0;

// Function prototypes
void add_translation(const char* english, const char* alien);
void translate(const char* input);
void load_translations(const char* filename);
void display_translations();
void clear_buffer();

int main() {
    char choice;
    char input[MAX_LENGTH];
    char filename[MAX_LENGTH];

    // Load translations from file
    printf("Enter the filename to load translations from (for example: translations.txt): ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;  // Remove newline character
    load_translations(filename);

    while (1) {
        printf("\n--- Alien Language Translator ---\n");
        printf("1. Translate a phrase\n");
        printf("2. View translations\n");
        printf("3. Add a translation\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        choice = getchar();
        clear_buffer(); // Clear newline from buffer

        switch (choice) {
            case '1':
                printf("Enter a phrase in English: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline
                translate(input);
                break;
            case '2':
                display_translations();
                break;
            case '3': {
                char eng[MAX_LENGTH], ali[MAX_LENGTH];
                printf("Enter the English phrase: ");
                fgets(eng, sizeof(eng), stdin);
                eng[strcspn(eng, "\n")] = 0; // Remove newline
                printf("Enter the Alien translation: ");
                fgets(ali, sizeof(ali), stdin);
                ali[strcspn(ali, "\n")] = 0; // Remove newline
                add_translation(eng, ali);
                break;
            }
            case '4':
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

// Function to load translations from a file
void load_translations(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%[^\n]\n%[^\n]\n", translations[translation_count].english, translations[translation_count].alien) != EOF) {
        translation_count++;
        if (translation_count >= MAX_PHRASES) {
            printf("Reached maximum number of translations.\n");
            break;
        }
    }

    fclose(file);
    printf("Loaded %d translations from %s.\n", translation_count, filename);
}

// Function to add a new translation
void add_translation(const char* english, const char* alien) {
    if (translation_count >= MAX_PHRASES) {
        printf("Cannot add more translations. Limit reached.\n");
        return;
    }
    strcpy(translations[translation_count].english, english);
    strcpy(translations[translation_count].alien, alien);
    translation_count++;
    printf("Added translation: '%s' -> '%s'\n", english, alien);
}

// Function to translate a given phrase
void translate(const char* input) {
    for (int i = 0; i < translation_count; i++) {
        if (strcasecmp(translations[i].english, input) == 0) {
            printf("Alien translation: '%s'\n", translations[i].alien);
            return;
        }
    }
    printf("Translation not found for: '%s'\n", input);
}

// Function to display all translations
void display_translations() {
    printf("\n--- Current Translations ---\n");
    for (int i = 0; i < translation_count; i++) {
        printf("'%s' -> '%s'\n", translations[i].english, translations[i].alien);
    }
}

// Function to clear the input buffer
void clear_buffer() {
    while (getchar() != '\n'); // Clear until newline
}