//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_NAME_LENGTH 100

void displayMenu() {
    printf("\n*** Welcome to the E-Book Reader ***\n");
    printf("1. Read a file\n");
    printf("2. Search for a word\n");
    printf("3. Go back to the menu\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char line[MAX_LINE_LENGTH];

    printf("\n*** Reading: %s ***\n", filename);
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
        printf("Press ENTER to continue reading... ");
        getchar(); // wait for user to press ENTER
    }

    fclose(file);
    printf("\nEnd of file reached.\n");
}

void searchInFile(const char* filename, const char* word) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;
    printf("\n*** Searching for '%s' in %s ***\n", word, filename);
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, word) != NULL) {
            printf("Found: %s", line);
            found = 1;
        }
    }

    if (!found) {
        printf("No occurrences of '%s' found in the file.\n", word);
    }

    fclose(file);
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    char word[MAX_LINE_LENGTH];
    int choice = 0;

    printf("Enter the eBook filename (with .txt extension): ");
    scanf("%s", filename);
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                readFile(filename);
                break;
            case 2:
                printf("Enter the word to search for: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0'; // remove newline character
                searchInFile(filename, word);
                break;
            case 3:
                continue;
            case 4:
                printf("Exiting the eBook Reader. Happy reading!\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    }
    
    return 0;
}