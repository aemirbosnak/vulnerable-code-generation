//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTES 100
#define MAX_TITLE_LENGTH 50
#define MAX_CONTENT_LENGTH 500
#define FILENAME "notes.txt"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Note;

void save_notes(Note notes[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Could not open file for writing");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n", notes[i].title, notes[i].content);
    }
    fclose(file);
}

int load_notes(Note notes[]) {
    FILE *file = fopen(FILENAME, "r");
    int count = 0;

    if (file == NULL) {
        return 0;
    }

    while (fgets(notes[count].title, MAX_TITLE_LENGTH, file)) {
        // Remove the newline character
        notes[count].title[strcspn(notes[count].title, "\n")] = 0;
        fgets(notes[count].content, MAX_CONTENT_LENGTH, file);
        notes[count].content[strcspn(notes[count].content, "\n")] = 0;
        count++;
    }

    fclose(file);
    return count;
}

void add_note(Note notes[], int *count) {
    if (*count >= MAX_NOTES) {
        printf("Note limit reached. Cannot add more notes.\n");
        return;
    }
    
    printf("Enter note title: ");
    fgets(notes[*count].title, MAX_TITLE_LENGTH, stdin);
    notes[*count].title[strcspn(notes[*count].title, "\n")] = 0;

    printf("Enter note content: ");
    fgets(notes[*count].content, MAX_CONTENT_LENGTH, stdin);
    notes[*count].content[strcspn(notes[*count].content, "\n")] = 0;

    (*count)++;
    save_notes(notes, *count);
    printf("Note added successfully.\n");
}

void view_notes(Note notes[], int count) {
    if (count == 0) {
        printf("No notes available.\n");
        return;
    }

    printf("\n--- Notes ---\n");
    for (int i = 0; i < count; i++) {
        printf("Note %d:\n", i + 1);
        printf("Title: %s\n", notes[i].title);
        printf("Content: %s\n\n", notes[i].content);
    }
}

void delete_note(Note notes[], int *count) {
    if (*count == 0) {
        printf("No notes available to delete.\n");
        return;
    }

    int index;
    printf("Enter the note number to delete (1 to %d): ", *count);
    scanf("%d", &index);
    getchar(); // Consume newline left in input buffer

    if (index < 1 || index > *count) {
        printf("Invalid note number.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        notes[i] = notes[i + 1];
    }
    (*count)--;

    save_notes(notes, *count);
    printf("Note deleted successfully.\n");
}

int main() {
    Note notes[MAX_NOTES];
    int count = load_notes(notes);
    int choice;

    do {
        printf("\n--- Note Taking Application ---\n");
        printf("1. Add Note\n");
        printf("2. View Notes\n");
        printf("3. Delete Note\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline from input buffer

        switch (choice) {
            case 1:
                add_note(notes, &count);
                break;
            case 2:
                view_notes(notes, count);
                break;
            case 3:
                delete_note(notes, &count);
                break;
            case 4:
                printf("Exiting the application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}