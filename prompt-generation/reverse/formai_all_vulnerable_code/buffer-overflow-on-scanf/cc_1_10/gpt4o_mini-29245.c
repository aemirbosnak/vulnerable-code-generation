//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100
#define MAX_LINE_LENGTH 256

void create_file();
void write_to_file(const char* filename);
void read_from_file(const char* filename);
void display_file_content(const char* filename);
void file_menu();

int main() {
    file_menu();
    return 0;
}

void file_menu() {
    int choice;
    char filename[MAX_FILENAME];

    while (1) {
        printf("\n--- Simple Text Editor ---\n");
        printf("1. Create a new file\n");
        printf("2. Write to a file\n");
        printf("3. Read from a file\n");
        printf("4. Display file content\n");
        printf("5. Exit\n");
        printf("Please choose an option (1-5): ");
        scanf("%d", &choice);
        getchar(); //to consume the newline character after the number input

        switch (choice) {
            case 1:
                create_file();
                break;
            case 2:
                printf("Enter filename to write to: ");
                fgets(filename, MAX_FILENAME, stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove the newline character
                write_to_file(filename);
                break;
            case 3:
                printf("Enter filename to read from: ");
                fgets(filename, MAX_FILENAME, stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove the newline character
                read_from_file(filename);
                break;
            case 4:
                printf("Enter filename to display content: ");
                fgets(filename, MAX_FILENAME, stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove the newline character
                display_file_content(filename);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
}

void create_file() {
    char filename[MAX_FILENAME];
    printf("Enter a name for the new file: ");
    fgets(filename, MAX_FILENAME, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove the newline character

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file '%s'.\n", filename);
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(file);
}

void write_to_file(const char* filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file '%s'. Please make sure it exists.\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Enter text to write to the file (type 'exit' on a new line to finish):\n");
    while (1) {
        fgets(line, MAX_LINE_LENGTH, stdin);
        if (strncmp(line, "exit", 4) == 0) {
            break;
        }
        fprintf(file, "%s", line);
    }

    printf("Text written to '%s' successfully.\n", filename);
    fclose(file);
}

void read_from_file(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file '%s'. Please make sure it exists.\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Reading content from '%s':\n", filename);
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}

void display_file_content(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file '%s'. Please make sure it exists.\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Content of '%s':\n", filename);
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}