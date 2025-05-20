//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LANGUAGE_LENGTH 50
#define MAX_TRANSLATIONS 100

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Translation;

typedef struct {
    Translation translations[MAX_TRANSLATIONS];
    int count;
} Dictionary;

void initializeDictionary(Dictionary *dict) {
    dict->count = 0;
}

void addTranslation(Dictionary *dict, const char *english, const char *alien) {
    if (dict->count < MAX_TRANSLATIONS) {
        strncpy(dict->translations[dict->count].english, english, MAX_WORD_LENGTH - 1);
        strncpy(dict->translations[dict->count].alien, alien, MAX_WORD_LENGTH - 1);
        dict->count++;
    } else {
        printf("Dictionary is full!\n");
    }
}

const char* translate(Dictionary *dict, const char *english) {
    for (int i = 0; i < dict->count; i++) {
        if (strcmp(dict->translations[i].english, english) == 0) {
            return dict->translations[i].alien;
        }
    }
    return "Translation not found.";
}

void loadDictionaryFromFile(Dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open dictionary file");
        return;
    }

    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];

    while (fscanf(file, "%s %s", english, alien) == 2) {
        addTranslation(dict, english, alien);
    }

    fclose(file);
}

void saveDictionaryToFile(Dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open dictionary file for writing");
        return;
    }

    for (int i = 0; i < dict->count; i++) {
        fprintf(file, "%s %s\n", dict->translations[i].english, dict->translations[i].alien);
    }

    fclose(file);
}

void displayDictionary(Dictionary *dict) {
    printf("\nCurrent Dictionary Entries:\n");
    for (int i = 0; i < dict->count; i++) {
        printf("%s -> %s\n", dict->translations[i].english, dict->translations[i].alien);
    }
}

void interactiveTranslation(Dictionary *dict) {
    char input[MAX_WORD_LENGTH];

    printf("Enter English word to translate (or 'exit' to quit): ");
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        printf("Alien Translation: %s\n", translate(dict, input));
        printf("Enter English word to translate (or 'exit' to quit): ");
    }
}

int main() {
    Dictionary alienDict;
    initializeDictionary(&alienDict);
    
    loadDictionaryFromFile(&alienDict, "dictionary.txt");

    int choice;
    do {
        printf("\nAlien Language Translator\n");
        printf("1. Translate\n");
        printf("2. Add Translation\n");
        printf("3. Display Dictionary\n");
        printf("4. Save Dictionary\n");
        printf("5. Load Dictionary from File\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            interactiveTranslation(&alienDict);
        } else if (choice == 2) {
            char english[MAX_WORD_LENGTH], alien[MAX_WORD_LENGTH];
            printf("Enter English word: ");
            scanf("%s", english);
            printf("Enter Alien word: ");
            scanf("%s", alien);
            addTranslation(&alienDict, english, alien);
        } else if (choice == 3) {
            displayDictionary(&alienDict);
        } else if (choice == 4) {
            saveDictionaryToFile(&alienDict, "dictionary.txt");
        } else if (choice == 5) {
            loadDictionaryFromFile(&alienDict, "dictionary.txt");
        } else if (choice == 6) {
            printf("Exiting program.\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}