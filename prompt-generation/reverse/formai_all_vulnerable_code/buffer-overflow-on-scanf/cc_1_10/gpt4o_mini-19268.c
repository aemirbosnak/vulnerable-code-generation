//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

// Function prototypes
void translateWord(char* word, FILE* dictionary);
void addToDictionary(char* english, char* catLang, FILE* dictionary);
void displayDictionary(FILE* dictionary);
void saveDictionary(FILE* dictionary);

int main() {
    FILE* dictionary = fopen("dictionary.txt", "a+");
    if (dictionary == NULL) {
        fprintf(stderr, "Could not open dictionary file.\n");
        return 1;
    }

    char input[MAX_LENGTH];
    char option;
    
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Choose an option:\n");
    printf("1. Translate a word\n");
    printf("2. Add a new word\n");
    printf("3. Display all translations\n");
    printf("4. Exit\n");

    while (1) {
        printf("Your choice: ");
        scanf(" %c", &option);
        getchar(); // Consume newline

        switch (option) {
            case '1':
                printf("Enter the English word to translate: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline
                translateWord(input, dictionary);
                break;
            case '2': {
                char english[MAX_LENGTH];
                char catLang[MAX_LENGTH];
                printf("Enter the English word: ");
                fgets(english, sizeof(english), stdin);
                english[strcspn(english, "\n")] = 0; // Remove newline
                printf("Enter the Cat Language equivalent: ");
                fgets(catLang, sizeof(catLang), stdin);
                catLang[strcspn(catLang, "\n")] = 0; // Remove newline
                addToDictionary(english, catLang, dictionary);
                break;
            }
            case '3':
                displayDictionary(dictionary);
                break;
            case '4':
                saveDictionary(dictionary);
                fclose(dictionary);
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    }
}

void translateWord(char* word, FILE* dictionary) {
    rewind(dictionary); // Reset file pointer to the beginning
    char line[100];
    int found = 0;

    while (fgets(line, sizeof(line), dictionary)) {
        char* english = strtok(line, " ");
        char* catLang = strtok(NULL, "\n");

        if (english != NULL && strcmp(english, word) == 0) {
            printf("Translation: %s\n", catLang);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("The word '%s' is not in the dictionary.\n", word);
    }
}

void addToDictionary(char* english, char* catLang, FILE* dictionary) {
    fprintf(dictionary, "%s %s\n", english, catLang);
    fflush(dictionary); // Make sure the write is done
    printf("Successfully added '%s' -> '%s' to the dictionary!\n", english, catLang);
}

void displayDictionary(FILE* dictionary) {
    rewind(dictionary); // Reset file pointer to the beginning
    char line[100];

    printf("Dictionary contents:\n");
    while (fgets(line, sizeof(line), dictionary)) {
        printf("%s", line);
    }
}

void saveDictionary(FILE* dictionary) {
    // Optionally save any final work if needed
    // As we append to the file, we don't need to take special action here
}