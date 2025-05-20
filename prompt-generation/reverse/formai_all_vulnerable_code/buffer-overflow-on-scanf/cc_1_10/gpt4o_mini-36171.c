//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void displayContent(FILE *file) {
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }
}

void searchInFile(FILE *file, const char *word) {
    char buffer[BUFFER_SIZE];
    int line_num = 0;
    int found = 0;

    rewind(file); // Reset file pointer to the beginning
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        line_num++;
        if (strstr(buffer, word) != NULL) {
            printf("Found '%s' in line %d: %s", word, line_num, buffer);
            found = 1;
        }
    }

    if (!found) {
        printf("The word '%s' was not found in the file.\n", word);
    }
}

void readEbook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open the file");
        return;
    }

    printf("Press 'd' to display content, 's' to search for a word, or 'q' to quit.\n");

    char command;
    while (1) {
        printf("Enter command: ");
        scanf(" %c", &command);

        switch (command) {
            case 'd':
                displayContent(file);
                break;
            case 's': {
                char word[100];
                printf("Enter a word to search: ");
                scanf("%s", word);
                searchInFile(file, word);
                break;
            }
            case 'q':
                fclose(file);
                return;
            default:
                printf("Invalid command. Try again.\n");
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <ebook_file.txt>\n", argv[0]);
        return 1;
    }

    readEbook(argv[1]);
    return 0;
}