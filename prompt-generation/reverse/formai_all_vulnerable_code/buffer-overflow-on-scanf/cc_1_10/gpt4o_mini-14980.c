//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTES 100
#define NOTE_LENGTH 256
#define FILENAME "notes.txt"

void displayMenu();
void addNote();
void viewNotes();
void updateNote();
void deleteNote();
void clearBuffer();

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();  // Clear the input buffer

        switch (choice) {
            case 1:
                addNote();
                break;
            case 2:
                viewNotes();
                break;
            case 3:
                updateNote();
                break;
            case 4:
                deleteNote();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Note Taking Application ---\n");
    printf("1. Add Note\n");
    printf("2. View Notes\n");
    printf("3. Update Note\n");
    printf("4. Delete Note\n");
    printf("5. Exit\n");
}

void addNote() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Unable to open file for writing");
        return;
    }
    
    char note[NOTE_LENGTH];
    printf("Enter your note: ");
    fgets(note, NOTE_LENGTH, stdin);
    
    fprintf(file, "%s", note);
    fclose(file);
    printf("Note added successfully!\n");
}

void viewNotes() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    char note[NOTE_LENGTH];
    printf("\n--- Notes ---\n");
    while (fgets(note, NOTE_LENGTH, file) != NULL) {
        printf("%s", note);
    }
    fclose(file);
}

void updateNote() {
    viewNotes();
    int noteToUpdate;
    printf("Enter the note number to update (starting from 1): ");
    scanf("%d", &noteToUpdate);
    clearBuffer();

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    char notes[MAX_NOTES][NOTE_LENGTH];
    int count = 0;

    while (fgets(notes[count], NOTE_LENGTH, file) != NULL) {
        count++;
    }
    fclose(file);

    if (noteToUpdate < 1 || noteToUpdate > count) {
        printf("Invalid note number.\n");
        return;
    }

    printf("Enter the updated note: ");
    fgets(notes[noteToUpdate - 1], NOTE_LENGTH, stdin);

    file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Unable to open file for writing");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s", notes[i]);
    }
    fclose(file);
    printf("Note updated successfully!\n");
}

void deleteNote() {
    viewNotes();
    int noteToDelete;
    printf("Enter the note number to delete (starting from 1): ");
    scanf("%d", &noteToDelete);
    clearBuffer();

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    char notes[MAX_NOTES][NOTE_LENGTH];
    int count = 0;

    while (fgets(notes[count], NOTE_LENGTH, file) != NULL) {
        count++;
    }
    fclose(file);

    if (noteToDelete < 1 || noteToDelete > count) {
        printf("Invalid note number.\n");
        return;
    }

    file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Unable to open file for writing");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i != noteToDelete - 1) {
            fprintf(file, "%s", notes[i]);
        }
    }
    fclose(file);
    printf("Note deleted successfully!\n");
}

void clearBuffer() {
    while (getchar() != '\n');
}