//FormAI DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

// Entry struct
struct Entry {
    char date[50];
    char text[1000];
};

// Global variables
struct Entry entries[MAX_ENTRIES];
int num_entries = 0;

// Function prototypes
void print_menu();
void add_entry();
void view_entries();
void save_entries();
void load_entries();

// Main function
int main() {
    printf("*** Welcome to My Digital Diary ***\n\n");
    load_entries();
    while (1) {
        print_menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                save_entries();
                printf("Entries saved successfully!\n");
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

// Prints menu options
void print_menu() {
    printf("\n--- Menu ---\n");
    printf("1. Add entry\n");
    printf("2. View entries\n");
    printf("3. Save entries\n");
    printf("4. Exit\n");
}

// Adds a new entry
void add_entry() {
    // Get current date and time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[50];
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", t);
    
    // Get entry text
    printf("\nEnter your entry:\n");
    getchar(); // Consume newline character left over from scanf
    fgets(entries[num_entries].text, sizeof(entries[num_entries].text), stdin);
    
    // Save entry
    strcpy(entries[num_entries].date, date);
    num_entries++;
}

// Views all entries
void view_entries() {
    if (num_entries == 0) {
        printf("\nNo entries to display.\n");
        return;
    }
    printf("\nAll Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("\n%s\n%s", entries[i].date, entries[i].text);
    }
}

// Saves all entries to a file
void save_entries() {
    FILE *file = fopen("entries.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to create file.\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s\n%s\n", entries[i].date, entries[i].text);
    }
    fclose(file);
}

// Loads entries from file on program start-up
void load_entries() {
    FILE *file = fopen("entries.txt", "r");
    if (file == NULL) {
        return;
    }
    char line[1000];
    while (fgets(line, sizeof(line), file) != NULL) {
        strcpy(entries[num_entries].date, strtok(line, "\n"));
        fgets(entries[num_entries].text, sizeof(entries[num_entries].text), file);
        num_entries++;
    }
    fclose(file);
}