//FormAI DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Entry {
    int year;
    int month;
    int day;
    char *title;
    char *content;
};

int main() {
    struct Entry *entries;
    int num_entries = 0;
    int max_entries = 5; // Start with space for 5 entries
    entries = malloc(max_entries * sizeof(struct Entry));

    printf("--- Welcome to your digital diary! ---\n");
    printf("Type 'exit' at any time to quit.\n\n");

    while (1) {
        // Get the date
        int year, month, day;
        printf("Enter the date of the entry (yyyy/mm/dd): ");
        char date_str[11];
        fgets(date_str, 11, stdin); // Read up to 11 characters (10 + null terminator)
        if (strcmp(date_str, "exit\n") == 0) {
            break;
        }
        int num = sscanf(date_str, "%d/%d/%d", &year, &month, &day);
        if (num != 3) {
            printf("Invalid date format, please try again.\n");
            continue;
        }

        // Get the title
        printf("Enter a title for the entry: ");
        char title[100];
        fgets(title, 100, stdin);
        if (strcmp(title, "exit\n") == 0) {
            break;
        }
        title[strcspn(title, "\n")] = 0; // Remove newline character

        // Get the content
        printf("Enter the content of the entry: ");
        char *content = malloc(1000 * sizeof(char));
        fgets(content, 1000, stdin);
        if (strcmp(content, "exit\n") == 0) {
            break;
        }
        content[strcspn(content, "\n")] = 0;

        // Add the entry to the diary
        struct Entry new_entry = {year, month, day, title, content};
        if (num_entries >= max_entries) {
            max_entries *= 2; // Double the allocated space
            entries = realloc(entries, max_entries * sizeof(struct Entry));
        }
        entries[num_entries] = new_entry;
        num_entries++;

        printf("Entry added.\n\n");
    }

    // Print out all the entries
    printf("\n--- Your diary entries ---\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d/%02d/%02d: %s\n", entries[i].year, entries[i].month, entries[i].day, entries[i].title);
        printf("%s\n\n", entries[i].content);
    }

    // Free memory
    for (int i = 0; i < num_entries; i++) {
        free(entries[i].title);
        free(entries[i].content);
    }
    free(entries);

    return 0;
}