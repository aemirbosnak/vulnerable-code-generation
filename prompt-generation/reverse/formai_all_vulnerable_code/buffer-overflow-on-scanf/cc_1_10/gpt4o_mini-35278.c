//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_CONTENT_LEN 256
#define FILENAME "notes.txt"

// Function prototypes
void addNote();
void viewNotes();
void deleteNote();
void clearBuffer();

int main() {
    int choice;
    do {
        printf("\nNote Management System\n");
        printf("1. Add Note\n");
        printf("2. View Notes\n");
        printf("3. Delete Note\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear newline from buffer

        switch (choice) {
            case 1:
                addNote();
                break;
            case 2:
                viewNotes();
                break;
            case 3:
                deleteNote();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addNote() {
    char title[MAX_TITLE_LEN];
    char content[MAX_CONTENT_LEN];
    FILE *file;

    printf("Enter note title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline

    printf("Enter note content: ");
    fgets(content, sizeof(content), stdin);
    content[strcspn(content, "\n")] = '\0'; // Remove newline

    file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    fprintf(file, "Title: %s\nContent: %s\n---\n", title, content);
    fclose(file);
    printf("Note added successfully!\n");
}

void viewNotes() {
    char buffer[512];
    FILE *file;

    file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("\nNotes:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

void deleteNote() {
    char title[MAX_TITLE_LEN];
    char buffer[512];
    FILE *file, *tempFile;

    printf("Enter the title of the note to delete: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline

    file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Unable to open temporary file");
        fclose(file);
        return;
    }

    int noteFound = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, title) == NULL) {
            fprintf(tempFile, "%s", buffer);
        } else {
            noteFound = 1;
            // Skip the content line and the separator line
            fgets(buffer, sizeof(buffer), file);
            fgets(buffer, sizeof(buffer), file);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (noteFound) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Note deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("Note with title '%s' not found.\n", title);
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}