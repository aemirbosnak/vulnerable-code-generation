//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTES 100
#define NOTE_LENGTH 256
#define FILENAME "notes.txt"

// Function to display the menu options
void displayMenu() {
    printf("\n====== Note Management System ======\n");
    printf("1. Add a note\n");
    printf("2. View notes\n");
    printf("3. Clear all notes\n");
    printf("4. Exit\n");
    printf("====================================\n");
    printf("Enter your choice: ");
}

// Function to add a note
void addNote() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    char note[NOTE_LENGTH];
    printf("Enter your note (max %d characters): ", NOTE_LENGTH - 1);
    getchar(); // To consume newline from previous input
    fgets(note, sizeof(note), stdin);
    
    // Remove newline character if present
    size_t len = strlen(note);
    if (len > 0 && note[len - 1] == '\n') {
        note[len - 1] = '\0';
    }

    fprintf(file, "%s\n", note);
    fclose(file);
    printf("Note added successfully!\n");
}

// Function to view the notes
void viewNotes() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\n===== Your Notes =====\n");
    char note[NOTE_LENGTH];
    int line = 1;
    while (fgets(note, sizeof(note), file) != NULL) {
        printf("%d: %s", line, note);
        line++;
    }
    fclose(file);
    if (line == 1) {
        printf("No notes found.\n");
    }
}

// Function to clear all notes
void clearNotes() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    // Closing immediately to clear the file
    fclose(file);
    printf("All notes cleared successfully!\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addNote();
                break;
            case 2:
                viewNotes();
                break;
            case 3:
                clearNotes();
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}