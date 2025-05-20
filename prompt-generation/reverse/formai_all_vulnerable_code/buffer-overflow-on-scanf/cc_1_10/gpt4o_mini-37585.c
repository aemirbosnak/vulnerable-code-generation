//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_CONTENT_LEN 500
#define MAX_NOTES 100
#define FILENAME "notes.txt"

typedef struct {
    char title[MAX_TITLE_LEN];
    char content[MAX_CONTENT_LEN];
} Note;

void add_note() {
    Note note;
    FILE *file = fopen(FILENAME, "ab");
    if (!file) {
        perror("Unable to open file!");
        return;
    }

    printf("Enter note title: ");
    fgets(note.title, MAX_TITLE_LEN, stdin);
    note.title[strcspn(note.title, "\n")] = 0; // Remove newline

    printf("Enter note content: ");
    fgets(note.content, MAX_CONTENT_LEN, stdin);
    note.content[strcspn(note.content, "\n")] = 0; // Remove newline

    fwrite(&note, sizeof(Note), 1, file);
    fclose(file);
    printf("Note saved successfully!\n");
}

void view_notes() {
    Note note;
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        perror("Unable to open file!");
        return;
    }

    printf("\nExisting Notes:\n");
    while (fread(&note, sizeof(Note), 1, file)) {
        printf("Title: %s\n", note.title);
        printf("Content: %s\n", note.content);
        printf("---------------------------\n");
    }

    fclose(file);
}

void delete_note() {
    Note notes[MAX_NOTES];
    int count = 0;
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        perror("Unable to open file!");
        return;
    }

    while (fread(&notes[count], sizeof(Note), 1, file)) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No notes to delete.\n");
        return;
    }

    printf("Choose a note to delete (0 to %d): ", count - 1);
    int choice;
    scanf("%d", &choice);
    getchar(); // consume the newline

    if (choice < 0 || choice >= count) {
        printf("Invalid choice!\n");
        return;
    }

    // Remove the selected note by shifting the subsequent notes
   FILE *tmpFile = fopen("temp_notes.txt", "wb");
    if (!tmpFile) {
        perror("Unable to open temp file!");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i != choice) {
            fwrite(&notes[i], sizeof(Note), 1, tmpFile);
        }
    }

    fclose(tmpFile);
    remove(FILENAME);
    rename("temp_notes.txt", FILENAME);
    printf("Note deleted successfully!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nNote Taking Application\n");
        printf("1. Add Note\n");
        printf("2. View Notes\n");
        printf("3. Delete Note\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume the newline

        switch (choice) {
            case 1:
                add_note();
                break;
            case 2:
                view_notes();
                break;
            case 3:
                delete_note();
                break;
            case 4:
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}