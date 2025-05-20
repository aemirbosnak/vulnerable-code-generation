//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256
#define FILENAME "example.txt"

// Function declarations
void writeToFile(const char *filename);
void readFromFile(const char *filename);
void displayContent(char lines[MAX_LINES][MAX_LENGTH], int lineCount);
void appendToFile(const char *filename);

int main() {
    // Menu options for file operation
    int choice;
    
    while (1) {
        printf("\nFile Handling Program\n");
        printf("1. Write to File\n");
        printf("2. Read from File\n");
        printf("3. Append to File\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a valid choice.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                writeToFile(FILENAME);
                break;
            case 2:
                readFromFile(FILENAME);
                break;
            case 3:
                appendToFile(FILENAME);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option (1-4).\n");
        }
    }
    
    return 0;
}

void writeToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        return;
    }

    char buffer[MAX_LENGTH];
    printf("Enter text to write to file (type 'exit' to stop):\n");

    while (1) {
        fgets(buffer, MAX_LENGTH, stdin); // Read a line
        
        // Remove newline character if it exists
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        
        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        fputs(buffer, file);
        fputc('\n', file); // Add a newline after each entry
    }
    
    fclose(file);
    printf("Data written to %s successfully.\n", filename);
}

void readFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for reading.\n");
        return;
    }

    char lines[MAX_LINES][MAX_LENGTH];
    int lineCount = 0;

    // Read lines from the file
    while (fgets(lines[lineCount], MAX_LENGTH, file) && lineCount < MAX_LINES) {
        lineCount++;
    }

    fclose(file);
    printf("Content of %s:\n", filename);
    displayContent(lines, lineCount);
}

void displayContent(char lines[MAX_LINES][MAX_LENGTH], int lineCount) {
    for (int i = 0; i < lineCount; i++) {
        printf("%d: %s", i + 1, lines[i]);
    }
}

void appendToFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for appending.\n");
        return;
    }

    char buffer[MAX_LENGTH];
    printf("Enter text to append to file (type 'exit' to stop):\n");

    while (1) {
        fgets(buffer, MAX_LENGTH, stdin); // Read a line
        
        // Remove newline character if it exists
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        
        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        fputs(buffer, file);
        fputc('\n', file); // Add a newline after each entry
    }
    
    fclose(file);
    printf("Data appended to %s successfully.\n", filename);
}