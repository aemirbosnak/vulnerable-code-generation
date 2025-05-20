//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define FILENAME "data.txt"

void writeToFile(const char *filename);
void readFromFile(const char *filename);
void appendToFile(const char *filename);
void displayFileContents(const char *filename);
void clearFile(const char *filename);

int main() {
    int choice;

    while (1) {
        printf("\n--- File Handling Menu ---\n");
        printf("1. Write to file\n");
        printf("2. Read from file\n");
        printf("3. Append to file\n");
        printf("4. Display file contents\n");
        printf("5. Clear file\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        getchar(); // consume newline character

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
                displayFileContents(FILENAME);
                break;
            case 5:
                clearFile(FILENAME);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void writeToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    char buffer[MAX_LINE_LENGTH];

    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    printf("Enter data to write (type 'END' to stop):\n");
    while (1) {
        fgets(buffer, MAX_LINE_LENGTH, stdin);
        if (strcmp(buffer, "END\n") == 0) {
            break;
        }
        fputs(buffer, file);
    }

    fclose(file);
    printf("Data written to %s successfully.\n", filename);
}

void readFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_LINE_LENGTH];

    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    printf("Reading from file %s:\n", filename);
    while (fgets(buffer, MAX_LINE_LENGTH, file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

void appendToFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    char buffer[MAX_LINE_LENGTH];

    if (file == NULL) {
        perror("Error opening file for appending");
        return;
    }

    printf("Enter data to append (type 'END' to stop):\n");
    while (1) {
        fgets(buffer, MAX_LINE_LENGTH, stdin);
        if (strcmp(buffer, "END\n") == 0) {
            break;
        }
        fputs(buffer, file);
    }

    fclose(file);
    printf("Data appended to %s successfully.\n", filename);
}

void displayFileContents(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_LINE_LENGTH];

    if (file == NULL) {
        perror("Error opening file for displaying");
        return;
    }

    printf("Contents of the file %s:\n", filename);
    while (fgets(buffer, MAX_LINE_LENGTH, file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

void clearFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        perror("Error opening file for clearing");
        return;
    }

    fclose(file);
    printf("File %s cleared successfully.\n", filename);
}