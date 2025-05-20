//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTES 100
#define MAX_LENGTH 256

void show_menu() {
    printf("\n--- Tranquil Notes Manager ---\n");
    printf("1. Add a Note\n");
    printf("2. View Notes\n");
    printf("3. Delete a Note\n");
    printf("4. Exit\n");
    printf("-------------------------------\n");
    printf("Choose an option (1-4): ");
}

void add_note(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    char note[MAX_LENGTH];
    printf("Enter your note (max 255 characters): ");
    getchar(); // To consume newline from previous input
    fgets(note, MAX_LENGTH, stdin);
    note[strcspn(note, "\n")] = 0; // Remove newline character

    fprintf(file, "%s\n", note);
    printf("Your note has been added peacefully.\n");

    fclose(file);
}

void view_notes(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No notes found.\n");
        return;
    }

    char note[MAX_LENGTH];
    printf("\n--- Your Notes ---\n");
    while (fgets(note, MAX_LENGTH, file)) {
        printf("* %s", note);
    }
    printf("-------------------\n");

    fclose(file);
}

void delete_note(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No notes to delete.\n");
        return;
    }

    char notes[MAX_NOTES][MAX_LENGTH];
    int note_count = 0;

    while (fgets(notes[note_count], MAX_LENGTH, file)) {
        notes[note_count][strcspn(notes[note_count], "\n")] = 0; // Remove newline
        note_count++;
    }
    fclose(file);

    printf("\n--- Your Notes ---\n");
    for (int i = 0; i < note_count; i++) {
        printf("%d: %s\n", i + 1, notes[i]);
    }
    printf("-------------------\n");

    int choice;
    printf("Enter the number of the note to delete: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > note_count) {
        printf("Invalid choice. No note deleted.\n");
        return;
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    for (int i = 0; i < note_count; i++) {
        if (i != choice - 1) {
            fprintf(file, "%s\n", notes[i]);
        }
    }
    printf("Note %d has been deleted. Find tranquility in your refreshed list.\n", choice);

    fclose(file);
}

int main() {
    const char *filename = "notes.txt";
    int option;

    while (1) {
        show_menu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_note(filename);
                break;
            case 2:
                view_notes(filename);
                break;
            case 3:
                delete_note(filename);
                break;
            case 4:
                printf("Exiting peacefully. May your thoughts always be serene.\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
    
    return 0;
}