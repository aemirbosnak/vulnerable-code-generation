//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 50
#define ENTRY_SIZE 256

typedef struct {
    char title[100];
    char description[150];
    time_t timestamp;
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int current_entry = 0;

void print_header() {
    printf("\n-------------------------------------\n");
    printf("|      Grateful Digital Diary        |\n");
    printf("|-----------------------------------|\n");
}

void save_entry() {
    if (current_entry >= MAX_ENTRIES) {
        printf("Maximum number of entries reached. Delete an old one to add a new one.\n");
        return;
    }

    strcpy(entries[current_entry].title, "New Entry");
    time(&entries[current_entry].timestamp);

    printf("Enter title for your entry: ");
    scanf("%s", entries[current_entry].title);

    printf("Enter description for your entry: ");
    scanf("%[^\n]", entries[current_entry].description);

    printf("Entry saved successfully!\n");
    current_entry++;
}

void load_entry(int index) {
    if (index < 0 || index >= current_entry) {
        printf("Invalid index\n");
        return;
    }

    struct tm *localTime;
    char time_string[100];

    localTime = localtime(&(entries[index].timestamp));

    printf("\nTitle: %s", entries[index].title);
    printf("\nDescription: %s", entries[index].description);
    printf("\nDate: %s", asctime(localTime));
}

void list_entries() {
    int i;

    printf("\nListing all entries:\n");
    for (i = 0; i < current_entry; i++) {
        load_entry(i);
    }
}

int main() {
    int choice, index;
    print_header();

    while (1) {
        printf("\n1. Save new entry\n");
        printf("2. Load entry\n");
        printf("3. List all entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                save_entry();
                break;
            case 2:
                printf("Enter index of the entry to load: ");
                scanf("%d", &index);
                load_entry(index);
                break;
            case 3:
                list_entries();
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}