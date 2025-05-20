//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "activity_log.txt"
#define MAX_INPUT_SIZE 100

void log_event(const char *event) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error: Unable to open log file.\n");
        return;
    }
    
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strcspn(timestamp, "\n")] = 0; // Remove newline character from timestamp

    fprintf(log_file, "[%s] %s\n", timestamp, event);
    fclose(log_file);
}

void display_menu() {
    printf("=========================\n");
    printf("      Menu Options       \n");
    printf("=========================\n");
    printf("1. Add a new note\n");
    printf("2. View all notes\n");
    printf("3. Clear all notes\n");
    printf("4. Exit\n");
    printf("=========================\n");
}

void add_note() {
    char note[MAX_INPUT_SIZE];
    printf("Enter your note: ");
    fgets(note, sizeof(note), stdin);
    // Remove newline character
    note[strcspn(note, "\n")] = 0;

    FILE *notes_file = fopen("notes.txt", "a");
    if (notes_file == NULL) {
        printf("Error: Unable to open notes file.\n");
        return;
    }
    
    fprintf(notes_file, "%s\n", note);
    fclose(notes_file);
    
    char log_message[150];
    snprintf(log_message, sizeof(log_message), "Added note: %s", note);
    log_event(log_message);
}

void view_notes() {
    FILE *notes_file = fopen("notes.txt", "r");
    if (notes_file == NULL) {
        printf("Error: Unable to open notes file.\n");
        return;
    }
    
    printf("=== Your Notes ===\n");
    char note[MAX_INPUT_SIZE];
    while (fgets(note, sizeof(note), notes_file)) {
        printf("%s", note);
    }
    fclose(notes_file);
    log_event("Viewed all notes.");
}

void clear_notes() {
    FILE *notes_file = fopen("notes.txt", "w");
    if (notes_file == NULL) {
        printf("Error: Unable to open notes file.\n");
        return;
    }
    fclose(notes_file); // Just opening with "w" truncates the file

    log_event("Cleared all notes.");
    printf("All notes cleared.\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

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
                log_event("Program exited.");
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
                log_event("Invalid option chosen.");
        }
    }

    return 0;
}