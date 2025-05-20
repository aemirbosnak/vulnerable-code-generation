//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTES 100
#define NOTE_LENGTH 256
#define FILENAME "notes.txt"

void add_note();
void view_notes();
void clear_notes();
void display_menu();

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character after scanf

        switch (choice) {
            case 1:
                add_note();
                break;
            case 2:
                view_notes();
                break;
            case 3:
                clear_notes();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n=== Note Taking Application ===\n");
    printf("1. Add Note\n");
    printf("2. View Notes\n");
    printf("3. Clear All Notes\n");
    printf("4. Exit\n");
}

void add_note() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char note[NOTE_LENGTH];
    printf("Enter your note (max %d characters): ", NOTE_LENGTH - 1);
    fgets(note, NOTE_LENGTH, stdin);
    note[strcspn(note, "\n")] = 0; // Remove newline character

    fprintf(file, "%s\n", note);
    fclose(file);
    printf("Note added successfully!\n");
}

void view_notes() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char note[NOTE_LENGTH];
    printf("\n=== Your Notes ===\n");
    while (fgets(note, NOTE_LENGTH, file)) {
        printf("%s", note);
    }
    fclose(file);
}

void clear_notes() {
    if (remove(FILENAME) == 0) {
        printf("All notes cleared successfully!\n");
    } else {
        perror("Error clearing notes");
    }
}