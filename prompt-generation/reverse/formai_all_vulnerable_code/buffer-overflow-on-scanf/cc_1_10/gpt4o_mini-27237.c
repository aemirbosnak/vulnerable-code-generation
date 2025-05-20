//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_LINES 100

void readFromFile(const char *filename);
void writeToFile(const char *filename);
void displayFileContents(const char *filename);
void appendToFile(const char *filename);
void clearFile(const char *filename);

int main() {
    char filename[50];
    int choice;
    
    printf("Enter the name of the file (with .txt extension): ");
    scanf("%s", filename);

    do {
        printf("\nFile Handling Menu:\n");
        printf("1. Write to File\n");
        printf("2. Read from File\n");
        printf("3. Display File Contents\n");
        printf("4. Append to File\n");
        printf("5. Clear File\n");
        printf("0. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                readFromFile(filename);
                break;
            case 3:
                displayFileContents(filename);
                break;
            case 4:
                appendToFile(filename);
                break;
            case 5:
                clearFile(filename);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void writeToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Enter text to write to the file (type 'exit' to stop):\n");
    
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, "exit\n") == 0) {
            break;
        }
        fputs(line, file);
    }

    fclose(file);
    printf("Data written to %s successfully.\n", filename);
}

void readFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file for reading");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Reading from %s:\n", filename);
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

void displayFileContents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file for displaying");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Contents of the file %s:\n", filename);
    
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

void appendToFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Failed to open file for appending");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Enter text to append to the file (type 'exit' to stop):\n");
    
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, "exit\n") == 0) {
            break;
        }
        fputs(line, file);
    }

    fclose(file);
    printf("Data appended to %s successfully.\n", filename);
}

void clearFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file for clearing");
        return;
    }

    fclose(file);
    printf("File %s has been cleared.\n", filename);
}