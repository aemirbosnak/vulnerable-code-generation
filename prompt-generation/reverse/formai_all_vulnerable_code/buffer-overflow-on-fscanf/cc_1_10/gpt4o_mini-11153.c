//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define ALIEN_VOCAB_SIZE 10

// Structures to define a simple alien language vocabulary
typedef struct {
    char english[MAX_LENGTH];
    char alien[MAX_LENGTH];
} Translation;

// Function prototypes
void load_translations(Translation *vocab, int *size);
void translate(const Translation *vocab, int size);
void display_translations(const Translation *vocab, int size);
void add_translation(Translation *vocab, int *size);
void save_translations(const Translation *vocab, int size);

int main() {
    Translation vocab[ALIEN_VOCAB_SIZE];
    int vocab_size = 0;
    int choice;

    load_translations(vocab, &vocab_size);

    do {
        printf("\n--- Alien Language Translator ---\n");
        printf("1. Translate English to Alien\n");
        printf("2. Display all translations\n");
        printf("3. Add a new translation\n");
        printf("4. Save translations to file\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                translate(vocab, vocab_size);
                break;
            case 2:
                display_translations(vocab, vocab_size);
                break;
            case 3:
                add_translation(vocab, &vocab_size);
                break;
            case 4:
                save_translations(vocab, vocab_size);
                break;
            case 0:
                printf("Exiting the translator... Farewell, Earthling!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 0);

    return 0;
}

void load_translations(Translation *vocab, int *size) {
    FILE *file = fopen("translations.txt", "r");
    if (file == NULL) {
        printf("No translation file found. Starting with an empty vocabulary.\n");
        return;
    }

    while (fscanf(file, "%s %s", vocab[*size].english, vocab[*size].alien) != EOF) {
        (*size)++;
    }

    fclose(file);
}

void translate(const Translation *vocab, int size) {
    char input[MAX_LENGTH];
    printf("Enter an English word to translate to Alien: ");
    scanf("%s", input);

    for (int i = 0; i < size; i++) {
        if (strcmp(input, vocab[i].english) == 0) {
            printf("The Alien translation of '%s' is '%s'.\n", input, vocab[i].alien);
            return;
        }
    }

    printf("Translation not found for '%s'.\n", input);
}

void display_translations(const Translation *vocab, int size) {
    printf("\n--- Current Translations ---\n");
    for (int i = 0; i < size; i++) {
        printf("%s -> %s\n", vocab[i].english, vocab[i].alien);
    }
}

void add_translation(Translation *vocab, int *size) {
    if (*size >= ALIEN_VOCAB_SIZE) {
        printf("Vocabulary limit reached! Cannot add more translations.\n");
        return;
    }
    
    char english[MAX_LENGTH];
    char alien[MAX_LENGTH];

    printf("Enter the English word: ");
    scanf("%s", english);
    printf("Enter the Alien translation: ");
    scanf("%s", alien);
    
    strcpy(vocab[*size].english, english);
    strcpy(vocab[*size].alien, alien);
    (*size)++;
    printf("Translation added successfully!\n");
}

void save_translations(const Translation *vocab, int size) {
    FILE *file = fopen("translations.txt", "w");
    if (file == NULL) {
        printf("Error saving translations to file.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %s\n", vocab[i].english, vocab[i].alien);
    }

    fclose(file);
    printf("Translations saved successfully!\n");
}