//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTES 100
#define NOTE_LENGTH 256

void addNote();
void viewNotes();
void deleteNote();
void clearBuffer();

int main() {
    int choice;
    
    do {
        printf("\n--- Welcome to Your Notes App ---\n");
        printf("1. Add a Note\n");
        printf("2. View Notes\n");
        printf("3. Delete a Note\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear input buffer
        
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
                printf("Exiting the Notes App. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void addNote() {
    FILE *fp = fopen("notes.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char note[NOTE_LENGTH];
    printf("Enter your note (max %d characters): ", NOTE_LENGTH - 1);
    fgets(note, NOTE_LENGTH, stdin);
    fprintf(fp, "%s", note);
    fclose(fp);
    printf("Note added successfully!\n");
}

void viewNotes() {
    FILE *fp = fopen("notes.txt", "r");
    if (fp == NULL) {
        printf("Error opening file! No notes available.\n");
        return;
    }

    char note[NOTE_LENGTH];
    printf("\n--- Your Notes ---\n");
    while (fgets(note, NOTE_LENGTH, fp) != NULL) {
        printf("%s", note);
    }
    fclose(fp);
    printf("--- End of Notes ---\n");
}

void deleteNote() {
    FILE *fp = fopen("notes.txt", "r");
    if (fp == NULL) {
        printf("Error opening file! No notes available to delete.\n");
        return;
    }

    char notes[MAX_NOTES][NOTE_LENGTH];
    int count = 0;

    while (fgets(notes[count], NOTE_LENGTH, fp) != NULL && count < MAX_NOTES) {
        count++;
    }
    fclose(fp);

    if (count == 0) {
        printf("No notes found to delete.\n");
        return;
    }

    int noteIndex;
    printf("Which note would you like to delete (1-%d)? ", count);
    scanf("%d", &noteIndex);
    clearBuffer(); // Clear input buffer

    if (noteIndex < 1 || noteIndex > count) {
        printf("Invalid note number! Please try again.\n");
        return;
    }

    // Shift notes to remove the selected one
    FILE *newFp = fopen("notes_temp.txt", "w");
    for (int i = 0; i < count; i++) {
        if (i != noteIndex - 1) { // Skip the note to delete
            fprintf(newFp, "%s", notes[i]);
        }
    }
    fclose(newFp);
    
    // Replace old file with the new one
    remove("notes.txt");
    rename("notes_temp.txt", "notes.txt");
    printf("Note %d deleted successfully!\n", noteIndex);
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer until newline
}