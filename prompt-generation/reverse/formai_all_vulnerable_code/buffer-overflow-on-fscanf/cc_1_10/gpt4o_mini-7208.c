//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define DICTIONARY_SIZE 100

typedef struct {
    char *english;
    char *alien;
} DictionaryEntry;

DictionaryEntry dictionary[DICTIONARY_SIZE];
int entryCount = 0;

void loadDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open dictionary file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%s %s", dictionary[entryCount].english, dictionary[entryCount].alien) != EOF) {
        entryCount++;
        if (entryCount >= DICTIONARY_SIZE) {
            fprintf(stderr, "Dictionary size limit reached. Only %d entries loaded.\n", DICTIONARY_SIZE);
            break;
        }
    }

    fclose(file);
}

char *translateToAlien(const char *input) {
    static char output[MAX_LENGTH];
    output[0] = '\0';

    char *token = strtok(strdup(input), " ");
    while (token != NULL) {
        for (int i = 0; i < entryCount; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                strcat(output, dictionary[i].alien);
                strcat(output, " ");
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return output;
}

void displayMenu() {
    printf("\n=== Alien Language Translator ===\n");
    printf("1. Translate a phrase\n");
    printf("2. Exit\n");
    printf("=================================\n");
}

int main() {
    char input[MAX_LENGTH];
    int choice;

    loadDictionary("dictionary.txt");

    do {
        displayMenu();
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear the buffer
            continue;
        }

        if (choice == 1) {
            printf("Enter a phrase to translate: ");
            getchar(); // to consume the newline after choice input
            fgets(input, MAX_LENGTH, stdin);
            input[strcspn(input, "\n")] = 0; // remove trailing newline
            
            char *output = translateToAlien(input);
            printf("Translated to Alien Language: %s\n", output);
        } else if (choice != 2) {
            printf("Invalid choice. Please select 1 or 2.\n");
        }

    } while (choice != 2);

    printf("Thank you for using the Alien Language Translator!\n");
    return 0;
}