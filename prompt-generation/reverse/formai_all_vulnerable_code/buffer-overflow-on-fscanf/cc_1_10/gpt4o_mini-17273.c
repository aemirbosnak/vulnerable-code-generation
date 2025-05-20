//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50
#define FILE_NAME "translations.txt"

typedef struct {
    char english[WORD_LENGTH];
    char alien[WORD_LENGTH];
} Translation;

Translation translations[MAX_WORDS];
int num_translations = 0;

void load_translations() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No translation file found. Starting fresh.\n");
        return;
    }
    while (fscanf(file, "%s %s", translations[num_translations].english, translations[num_translations].alien) != EOF) {
        num_translations++;
    }
    fclose(file);
}

void save_translations() {
    FILE *file = fopen(FILE_NAME, "w");
    for (int i = 0; i < num_translations; i++) {
        fprintf(file, "%s %s\n", translations[i].english, translations[i].alien);
    }
    fclose(file);
}

void add_translation() {
    if (num_translations >= MAX_WORDS) {
        printf("Max translations reached. Please delete some before adding.\n");
        return;
    }
    printf("Enter English word: ");
    scanf("%s", translations[num_translations].english);
    printf("Enter Alien translation: ");
    scanf("%s", translations[num_translations].alien);
    num_translations++;
    save_translations();
    printf("Translation added!\n");
}

void translate_word() {
    char word[WORD_LENGTH];
    printf("Enter the English word to translate: ");
    scanf("%s", word);

    for (int i = 0; i < num_translations; i++) {
        if (strcmp(word, translations[i].english) == 0) {
            printf("Alien translation: %s\n", translations[i].alien);
            return;
        }
    }
    printf("Translation not found.\n");
}

void display_translations() {
    printf("\nCurrent Translations:\n");
    for (int i = 0; i < num_translations; i++) {
        printf("%s -> %s\n", translations[i].english, translations[i].alien);
    }
    printf("\n");
}

void delete_translation() {
    char word[WORD_LENGTH];
    printf("Enter the English word to delete: ");
    scanf("%s", word);
    
    for (int i = 0; i < num_translations; i++) {
        if (strcmp(word, translations[i].english) == 0) {
            for (int j = i; j < num_translations - 1; j++) {
                translations[j] = translations[j + 1];
            }
            num_translations--;
            save_translations();
            printf("Translation deleted!\n");
            return;
        }
    }
    printf("Translation not found.\n");
}

void display_menu() {
    printf("\nAlien Language Translator\n");
    printf("1. Add Translation\n");
    printf("2. Translate Word\n");
    printf("3. Display Translations\n");
    printf("4. Delete Translation\n");
    printf("5. Exit\n");
}

int main() {
    load_translations();
    int choice;
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_translation();
                break;
            case 2:
                translate_word();
                break;
            case 3:
                display_translations();
                break;
            case 4:
                delete_translation();
                break;
            case 5:
                printf("Exiting the translator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}