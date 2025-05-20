//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTES 100
#define MAX_NOTE_LENGTH 256
#define FILENAME "notes.txt"

// Function prototypes
void addNote();
void viewNotes();
void clearNotes();
void displayMenu();

int main() {
    displayMenu();
    return 0;
}

void displayMenu() {
    int choice;

    while (1) {
        printf("\n🎉 Welcome to Your Happy Note Keeper! 🎉\n");
        printf("1. Add a new note\n");
        printf("2. View all notes\n");
        printf("3. Clear all notes\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
        
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

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
                printf("Goodbye! Keep smiling! 😊\n");
                exit(0);
            default:
                printf("Oops! That's not a valid option. Please try again! 😄\n");
        }
    }
}

void addNote() {
    FILE *file = fopen(FILENAME, "a");
    char note[MAX_NOTE_LENGTH];

    if (file == NULL) {
        printf("❌ Could not open file for writing! Please check permissions.\n");
        return;
    }

    printf("📝 Enter your note (max %d characters): ", MAX_NOTE_LENGTH - 1);
    fgets(note, sizeof(note), stdin);
    // Remove newline character
    note[strcspn(note, "\n")] = 0;

    if (fprintf(file, "%s\n", note) > 0) {
        printf("🎉 Your note has been added successfully! 🥳\n");
    } else {
        printf("❌ Failed to write to the file! Try again later.\n");
    }

    fclose(file);
}

void viewNotes() {
    FILE *file = fopen(FILENAME, "r");
    char note[MAX_NOTE_LENGTH];

    if (file == NULL) {
        printf("❌ Could not open file for reading! Please check if you have notes saved.\n");
        return;
    }

    printf("\n🌟 Your Notes 🌟\n");
    int noteCount = 0;

    while (fgets(note, sizeof(note), file) != NULL) {
        printf("%d: %s",++noteCount, note);
    }

    if (noteCount == 0) {
        printf("😢 No notes to display! Add some happy notes! 🌈\n");
    }

    fclose(file);
}

void clearNotes() {
    char confirmation;
    printf("Are you sure you want to clear all notes? (y/n): ");
    scanf(" %c", &confirmation);
    
    if (confirmation == 'y' || confirmation == 'Y') {
        FILE *file = fopen(FILENAME, "w");
        
        if (file == NULL) {
            printf("❌ Could not open file to clear notes!\n");
            return;
        }

        fclose(file);
        printf("🗑️ All notes have been cleared! Feeling fresh! ☀️\n");
    } else {
        printf("😅 Notes are safe! You can still wear your happy hat! 🎩\n");
    }
}