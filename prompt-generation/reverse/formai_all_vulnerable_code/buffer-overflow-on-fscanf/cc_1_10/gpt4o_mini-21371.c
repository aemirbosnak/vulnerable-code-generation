//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_TRANSLATIONS 100

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Translation;

void loadTranslations(Translation translations[], int *count) {
    FILE *file = fopen("translations.txt", "r");
    if (file == NULL) {
        perror("Could not open translations.txt");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf(file, "%s %s", translations[*count].english, translations[*count].alien) != EOF) {
        (*count)++;
        if (*count >= MAX_TRANSLATIONS) {
            break;
        }
    }

    fclose(file);
}

void translateToAlien(char *input, Translation translations[], int count) {
    char *word = strtok(input, " ");
    printf("Alien Translation: ");
    while (word != NULL) {
        int translated = 0;
        for (int i = 0; i < count; i++) {
            if (strcasecmp(word, translations[i].english) == 0) {
                printf("%s ", translations[i].alien);
                translated = 1;
                break;
            }
        }
        if (!translated) {
            printf("%s ", word); // If no translation found, print original word.
        }
        word = strtok(NULL, " ");
    }
    printf("\n");
}

void translateToEnglish(char *input, Translation translations[], int count) {
    char *word = strtok(input, " ");
    printf("English Translation: ");
    while (word != NULL) {
        int translated = 0;
        for (int i = 0; i < count; i++) {
            if (strcasecmp(word, translations[i].alien) == 0) {
                printf("%s ", translations[i].english);
                translated = 1;
                break;
            }
        }
        if (!translated) {
            printf("%s ", word); // If no translation found, print original word.
        }
        word = strtok(NULL, " ");
    }
    printf("\n");
}

void displayMenu() {
    printf("Alien Language Translator\n");
    printf("1. Translate from English to Alien\n");
    printf("2. Translate from Alien to English\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Translation translations[MAX_TRANSLATIONS];
    int count = 0;

    loadTranslations(translations, &count);

    int choice;
    char input[500];

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // To consume the newline after entering choice

        switch (choice) {
            case 1:
                printf("Enter English text to translate: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline
                translateToAlien(input, translations, count);
                break;
            case 2:
                printf("Enter Alien text to translate: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline
                translateToEnglish(input, translations, count);
                break;
            case 3:
                printf("Exiting the translator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 3);

    return 0;
}