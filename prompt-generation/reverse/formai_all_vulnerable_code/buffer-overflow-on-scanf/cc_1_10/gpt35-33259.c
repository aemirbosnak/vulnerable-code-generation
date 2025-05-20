//FormAI DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximum number of notes that can be stored
#define MAX_NOTES 100

// structure to hold information for a single note
typedef struct {
    int year;
    int month;
    int day;
    char text[256];
} Note;

// array to store all the notes
Note notes[MAX_NOTES];

// current number of notes stored
int num_notes = 0;

// function to add a new note to the array
void add_note() {
    Note new_note;
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &new_note.year, &new_note.month, &new_note.day);
    printf("Enter the note text: ");
    scanf(" %[^\n]s", new_note.text);
    notes[num_notes++] = new_note;
    printf("Note added successfully!\n");
}

// function to print all notes from a specific year
void print_notes_from_year() {
    int year;
    printf("Enter the year to search: ");
    scanf("%d", &year);
    printf("Notes from year %d:\n", year);
    for (int i = 0; i < num_notes; i++) {
        if (notes[i].year == year) {
            printf("Date: %d-%02d-%02d\n", notes[i].year, notes[i].month, notes[i].day);
            printf("Note: %s\n\n", notes[i].text);
        }
    }
}

int main() {
    while (1) {
        printf("Digital Diary Menu:\n");
        printf("1. Add a new note.\n");
        printf("2. Search notes from a specific year.\n");
        printf("3. Exit the program.\n");
        int choice;
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_note();
                break;
            case 2:
                print_notes_from_year();
                break;
            case 3:
                printf("Goodbye.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}