//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTES 100
#define MAX_NOTE_LENGTH 256
#define NOTE_FILE "notes.txt"

// Function Prototypes
void addNote();
void viewNotes();
void listNotes();
void displayMenu();
void clearInputBuffer();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear input buffer to avoid issues with fgets

        switch (choice) {
            case 1:
                addNote();
                break;
            case 2:
                viewNotes();
                break;
            case 3:
                listNotes();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n==== Note-Taking Application ====\n");
    printf("1. Add a new note\n");
    printf("2. View all notes\n");
    printf("3. List notes without content\n");
    printf("4. Exit\n");
}

void addNote() {
    FILE *file = fopen(NOTE_FILE, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char note[MAX_NOTE_LENGTH];
    printf("Enter your note (max %d characters): ", MAX_NOTE_LENGTH - 1);
    fgets(note, MAX_NOTE_LENGTH, stdin);
    note[strcspn(note, "\n")] = 0; // Remove newline character

    if (strlen(note) > 0) {
        fprintf(file, "%s\n", note);
        printf("Note added successfully!\n");
    } else {
        printf("Empty note not added.\n");
    }

    fclose(file);
}

void viewNotes() {
    FILE *file = fopen(NOTE_FILE, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char note[MAX_NOTE_LENGTH];
    printf("\n=== Notes ===\n");
    while (fgets(note, MAX_NOTE_LENGTH, file) != NULL) {
        printf("%s", note);
    }

    fclose(file);
}

void listNotes() {
    FILE *file = fopen(NOTE_FILE, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char note[MAX_NOTE_LENGTH];
    int noteCount = 0;
    printf("\n=== Notes List ===\n");
    while (fgets(note, MAX_NOTE_LENGTH, file) != NULL) {
        noteCount++;
        printf("Note %d\n", noteCount);
    }

    if (noteCount == 0) {
        printf("No notes found.\n");
    }

    fclose(file);
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}