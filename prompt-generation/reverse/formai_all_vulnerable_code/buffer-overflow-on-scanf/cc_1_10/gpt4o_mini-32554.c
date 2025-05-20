//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define FILENAME "notes.txt"

// Function declarations
void displayMenu();
void addNote();
void viewNotes();
void deleteNote();
void clearBuffer();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear newline left in the input buffer

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
                printf("Exiting the application...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n--- Note Taking Application ---\n");
    printf("1. Add Note\n");
    printf("2. View Notes\n");
    printf("3. Delete Note\n");
    printf("4. Exit\n");
}

void addNote() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return;
    }

    char note[MAX_LENGTH];
    printf("Enter your note: ");
    fgets(note, MAX_LENGTH, stdin);
    
    // Remove the newline character if present
    note[strcspn(note, "\n")] = 0;

    fprintf(file, "%s\n", note);
    fclose(file);

    printf("Note added successfully!\n");
}

void viewNotes() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Failed to open file for reading");
        return;
    }

    char note[MAX_LENGTH];
    printf("\n--- Your Notes ---\n");
    while (fgets(note, MAX_LENGTH, file) != NULL) {
        printf("%s", note);
    }
    fclose(file);
}

void deleteNote() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Failed to open file for reading");
        return;
    }

    char notes[MAX_LENGTH][MAX_LENGTH];
    int count = 0;
    while (fgets(notes[count], MAX_LENGTH, file) != NULL) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No notes to delete.\n");
        return;
    }

    printf("\n--- Your Notes ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s", i + 1, notes[i]);
    }

    int noteIndex;
    printf("Enter the note number to delete: ");
    scanf("%d", &noteIndex);

    if (noteIndex < 1 || noteIndex > count) {
        printf("Invalid note number. Deletion failed.\n");
        return;
    }

    // Rewrite the notes, skipping the deleted one
    file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i != noteIndex - 1) {
            fprintf(file, "%s", notes[i]);
        }
    }

    fclose(file);
    printf("Note deleted successfully!\n");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}