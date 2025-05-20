//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_BOOK_TITLE 50
#define MAX_CMD_LENGTH 10

void displayHelp() {
    printf("Commands:\n");
    printf("  next   - Go to the next line\n");
    printf("  prev   - Go to the previous line\n");
    printf("  goto   - Go to a specific line (type 'goto <line number>')\n");
    printf("  quit   - Exit the eBook reader\n");
    printf("  help   - Show this help message\n");
}

void readBook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    char *bookLines[1000];  // Supposed maximum of 1000 lines in the book
    int lineCounter = 0;

    // Read each line and save it to the bookLines array
    while (fgets(line, sizeof(line), file) && lineCounter < 1000) {
        bookLines[lineCounter] = strdup(line); // Allocate memory for each line
        lineCounter++;
    }
    fclose(file);

    int currentLine = 0; // Start at the first line
    char command[MAX_CMD_LENGTH];

    displayHelp();

    while (1) {
        // Print the current line being read
        if (currentLine < lineCounter) {
            printf("%s", bookLines[currentLine]);
        } else {
            printf("End of book reached.\n");
            break;
        }

        // Prompt for user command
        printf("\nEnter command: ");
        scanf("%s", command);

        if (strcmp(command, "next") == 0) {
            currentLine++;
        } else if (strcmp(command, "prev") == 0) {
            if (currentLine > 0) {
                currentLine--;
            } else {
                printf("You are already at the beginning of the book.\n");
            }
        } else if (strcmp(command, "goto") == 0) {
            int lineNumber;
            scanf("%d", &lineNumber);
            if (lineNumber >= 0 && lineNumber < lineCounter) {
                currentLine = lineNumber;
            } else {
                printf("Invalid line number. It should be between 0 and %d.\n", lineCounter - 1);
            }
        } else if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strcmp(command, "help") == 0) {
            displayHelp();
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    // Free allocated memory for book lines
    for (int i = 0; i < lineCounter; i++) {
        free(bookLines[i]);
    }
}

int main() {
    char filename[MAX_BOOK_TITLE];

    printf("Welcome to the Simple eBook Reader!\n");
    printf("Please enter the name of the text file you want to read: ");
    scanf("%s", filename);

    readBook(filename);

    return 0;
}