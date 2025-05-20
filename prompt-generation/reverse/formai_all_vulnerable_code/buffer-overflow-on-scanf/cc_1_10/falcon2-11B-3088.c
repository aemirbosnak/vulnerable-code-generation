//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define structure for digital diary entry
struct diary_entry {
    int id;
    char date[20];
    char content[1000];
};

// Function to create a new diary entry
void create_entry(struct diary_entry *entry) {
    // Get current date and time
    time_t now = time(NULL);
    struct tm *info = localtime(&now);

    // Format date
    strftime(entry->date, sizeof(entry->date), "%Y-%m-%d", info);

    // Prompt user for entry content
    printf("Enter diary entry content: ");
    fgets(entry->content, sizeof(entry->content), stdin);

    // Increment entry ID
    entry->id = (entry->id == 0)? 1 : entry->id + 1;
}

// Function to display all diary entries
void display_entries() {
    FILE *fp;
    fp = fopen("diary.txt", "r");

    if (fp == NULL) {
        printf("Error opening diary file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        struct diary_entry entry;
        sscanf(line, "%d %s %s", &entry.id, entry.date, entry.content);
        printf("%d: %s - %s\n", entry.id, entry.date, entry.content);
    }

    fclose(fp);
}

// Function to save diary entries to file
void save_entries(struct diary_entry *entries, int num_entries) {
    FILE *fp;
    fp = fopen("diary.txt", "w");

    if (fp == NULL) {
        printf("Error opening diary file.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        fprintf(fp, "%d %s %s\n", entries[i].id, entries[i].date, entries[i].content);
    }

    fclose(fp);
}

// Function to load diary entries from file
void load_entries(struct diary_entry *entries, int *num_entries) {
    FILE *fp;
    fp = fopen("diary.txt", "r");

    if (fp == NULL) {
        printf("Error opening diary file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        struct diary_entry entry;
        sscanf(line, "%d %s %s", &entry.id, entry.date, entry.content);
        entries[*num_entries].id = entry.id;
        strcpy(entries[*num_entries].date, entry.date);
        strcpy(entries[*num_entries].content, entry.content);
        (*num_entries)++;
    }

    fclose(fp);
}

// Main program
int main() {
    struct diary_entry entries[100];
    int num_entries = 0;

    while (1) {
        printf("1. Create new entry\n");
        printf("2. Display all entries\n");
        printf("3. Save entries to file\n");
        printf("4. Load entries from file\n");
        printf("5. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_entry(&entries[num_entries]);
                num_entries++;
                break;
            case 2:
                display_entries();
                break;
            case 3:
                save_entries(entries, num_entries);
                break;
            case 4:
                load_entries(entries, &num_entries);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}