//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Entry structure to store individual diary entries
typedef struct Entry {
    char title[50];
    char content[500];
    struct Entry *next;
} Entry;

// Function to create a new entry
Entry* createEntry() {
    Entry *entry = (Entry*)malloc(sizeof(Entry));
    printf("Yay! Let's write something memorable!\n");
    printf("Give your entry a catchy title: ");
    scanf("%s", entry->title);
    printf("Alright, now pour your heart out (max 500 characters): ");
    scanf(" %[^\n]%*c", entry->content);
    entry->next = NULL;
    return entry;
}

// Function to add an entry to the diary
void addEntry(Entry **diary, Entry *entry) {
    if (*diary == NULL) {
        *diary = entry;
        printf("Ta-da! Your first entry is safe and sound.\n");
    } else {
        Entry *current = *diary;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = entry;
        printf("Another masterpiece added to your diary!\n");
    }
}

// Function to read all entries from the diary
void readDiary(Entry *diary) {
    if (diary == NULL) {
        printf("Oops, your diary is empty. Time to fill it up!\n");
        return;
    }
    Entry *current = diary;
    while (current != NULL) {
        printf("------------------------------------\n");
        printf("Title: %s\n", current->title);
        printf("Content: %s\n", current->content);
        printf("------------------------------------\n");
        current = current->next;
    }
}

// Function to delete an entry from the diary by title
void deleteEntry(Entry **diary, char *title) {
    Entry *current = *diary;
    Entry *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (previous == NULL) {
                *diary = current->next;
                free(current);
                printf("Entry '%s' deleted. We'll miss it dearly.\n", title);
                return;
            } else {
                previous->next = current->next;
                free(current);
                printf("Entry '%s' deleted. Farewell, my friend.\n", title);
                return;
            }
        }
        previous = current;
        current = current->next;
    }
    printf("No worries, you can always try deleting another entry.\n");
}

// Function to search for an entry in the diary by title
void searchEntry(Entry *diary, char *title) {
    Entry *current = diary;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("------------------------------------\n");
            printf("Title: %s\n", current->title);
            printf("Content: %s\n", current->content);
            printf("------------------------------------\n");
            printf("Found it! Your memory is impeccable.\n");
            return;
        }
        current = current->next;
    }
    printf("Hmm, couldn't find that entry. Maybe try searching again?\n");
}

// Main function to interact with the user
int main() {
    Entry *diary = NULL;
    int choice = 0;
    char title[50];

    while (choice != 5) {
        printf("\nWelcome to your digital diary, where memories bloom!\n");
        printf("1. Write a new entry\n");
        printf("2. Read all entries\n");
        printf("3. Delete an entry\n");
        printf("4. Search for an entry\n");
        printf("5. Exit\n");
        printf("Make your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                addEntry(&diary, createEntry());
                break;
            case 2:
                readDiary(diary);
                break;
            case 3:
                printf("Tell me the title of the entry you want to delete: ");
                scanf(" %s", title);
                deleteEntry(&diary, title);
                break;
            case 4:
                printf("Search for an entry by title: ");
                scanf(" %s", title);
                searchEntry(diary, title);
                break;
            case 5:
                printf("Farewell, dear diarist! May your memories continue to shine.\n");
                break;
            default:
                printf("Oops, invalid choice. Let's try again.\n");
                break;
        }
    }

    return 0;
}