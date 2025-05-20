//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 32
#define WORDS_FILE "words.txt"
#define TEMP_FILE "temp.txt"

void insertWord(const char *word);
void displayWords();
void removeWord(const char *word);
int wordExists(const char *word);
void copyFile(const char *source, const char *destination);
void clearWords();

int main() {
    int choice;
    char word[MAX_WORD_LENGTH];

    do {
        printf("\n--- Word Management System ---\n");
        printf("1. Insert Word\n");
        printf("2. Display Words\n");
        printf("3. Remove Word\n");
        printf("4. Clear All Words\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a word to insert: ");
                scanf("%s", word);
                insertWord(word);
                break;
            case 2:
                displayWords();
                break;
            case 3:
                printf("Enter a word to remove: ");
                scanf("%s", word);
                removeWord(word);
                break;
            case 4:
                clearWords();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

void insertWord(const char *word) {
    FILE *file;

    if (wordExists(word)) {
        printf("Word '%s' already exists in the list.\n", word);
        return;
    }

    file = fopen(WORDS_FILE, "a");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    fprintf(file, "%s\n", word);
    fclose(file);
    printf("Word '%s' inserted successfully.\n", word);
}

void displayWords() {
    FILE *file;
    char line[MAX_LINE_LENGTH];

    file = fopen(WORDS_FILE, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    printf("\n--- List of Words ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void removeWord(const char *word) {
    FILE *file, *temp_file;
    char line[MAX_LINE_LENGTH];
    int found = 0;

    file = fopen(WORDS_FILE, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    temp_file = fopen(TEMP_FILE, "w");
    if (temp_file == NULL) {
        perror("Error opening temporary file for writing");
        fclose(file);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        // Compare the current line with the word to remove
        if (strcmp(line, word) != 0) {
            fputs(line, temp_file); // Write the line to temp file if not the one to be deleted
        } else {
            found = 1; // Found the word to delete
        }
    }

    fclose(file);
    fclose(temp_file);

    if (found) {
        // Replace original file with the temporary file
        remove(WORDS_FILE);
        rename(TEMP_FILE, WORDS_FILE);
        printf("Word '%s' removed successfully.\n", word);
    } else {
        remove(TEMP_FILE);
        printf("Word '%s' not found in the list.\n", word);
    }
}

int wordExists(const char *word) {
    FILE *file;
    char line[MAX_LINE_LENGTH];

    file = fopen(WORDS_FILE, "r");
    if (file == NULL) {
        return 0;
    }

    while (fgets(line, sizeof(line), file)) {
        // Remove newline character for comparison
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, word) == 0) {
            fclose(file);
            return 1; // Word found
        }
    }

    fclose(file);
    return 0; // Word not found
}

void clearWords() {
    if (remove(WORDS_FILE) == 0) {
        printf("All words cleared successfully.\n");
    } else {
        perror("Error clearing words");
    }
}