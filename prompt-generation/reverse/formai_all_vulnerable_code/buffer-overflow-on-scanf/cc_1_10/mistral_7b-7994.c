//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 10
#define ENTRY_LEN 100

typedef struct entry {
    char title[50];
    char content[ENTRY_LEN];
    struct entry *next;
} Entry;

Entry *head = NULL;
Entry diary[MAX_ENTRIES];

void add_entry(const char *title, const char *content) {
    Entry *new_entry = (Entry *)malloc(sizeof(Entry));

    if (new_entry == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(new_entry->title, title);
    strcpy(new_entry->content, content);
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        Entry *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_entry;
    }

    printf("Entry added successfully!\n");
}

void view_entries() {
    Entry *current = head;

    if (head == NULL) {
        printf("No entries found!\n");
        return;
    }

    printf("\nDiary Entries:\n\n");

    while (current != NULL) {
        printf("%s\n", current->title);
        printf("%s\n\n", current->content);
        current = current->next;
    }
}

void delete_entry(const char *title) {
    Entry *current = head, *prev = NULL;

    if (head == NULL) {
        printf("No entries found!\n");
        return;
    }

    while (current != NULL && strcmp(current->title, title) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Entry not found!\n");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Entry deleted successfully!\n");
}

int main() {
    int choice;
    char title[50], content[ENTRY_LEN];

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter content: ");
                fgets(content, ENTRY_LEN, stdin);
                add_entry(title, content);
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Enter title of the entry to delete: ");
                scanf("%s", title);
                delete_entry(title);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}