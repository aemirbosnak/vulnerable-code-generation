//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 256

typedef struct _entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
} entry;

entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *text) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Your diary is full! Delete some entries to make room.");
        return;
    }

    entry new_entry;
    new_entry.timestamp = time(NULL);
    strcpy(new_entry.text, text);

    entries[num_entries++] = new_entry;

    printf("Your entry has been added! :D\n");
}

void list_entries() {
    if (num_entries == 0) {
        printf("Your diary is empty. Write something today?");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        struct tm *time_info = localtime(&entries[i].timestamp);
        printf("%s: %s\n", asctime(time_info), entries[i].text);
    }
}

void delete_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid entry index!");
        return;
    }

    for (int i = index; i < num_entries - 1; i++) {
        entries[i] = entries[i + 1];
    }

    num_entries--;

    printf("Your entry has been deleted. :(\n");
}

void search_entries(char *keyword) {
    int found = 0;

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].text, keyword) != NULL) {
            struct tm *time_info = localtime(&entries[i].timestamp);
            printf("%s: %s\n", asctime(time_info), entries[i].text);
            found = 1;
        }
    }

    if (!found) {
        printf("No entries found with that keyword. :(\n");
    }
}

int main() {
    int choice;
    char text[MAX_ENTRY_LENGTH];

    printf("Welcome to your digital diary! :D\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. List all entries\n");
        printf("3. Delete an entry\n");
        printf("4. Search for entries\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("What would you like to write today? :D\n");
                fgets(text, MAX_ENTRY_LENGTH, stdin);
                add_entry(text);
                break;
            case 2:
                list_entries();
                break;
            case 3:
                printf("Which entry would you like to delete? (enter index)\n");
                int index;
                scanf("%d", &index);
                delete_entry(index);
                break;
            case 4:
                printf("What keyword would you like to search for?\n");
                char keyword[MAX_ENTRY_LENGTH];
                fgets(keyword, MAX_ENTRY_LENGTH, stdin);
                search_entries(keyword);
                break;
            case 5:
                printf("Goodbye! :)\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}