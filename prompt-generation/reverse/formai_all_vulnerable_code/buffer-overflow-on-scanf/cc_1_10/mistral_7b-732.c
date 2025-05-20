//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_ENTRY_LENGTH 200

typedef struct DiaryEntry {
    char name[MAX_NAME_LENGTH];
    char entry[MAX_ENTRY_LENGTH];
    struct DiaryEntry *next;
} DiaryEntry;

DiaryEntry *head = NULL;

void addEntry(const char *name, const char *entry) {
    DiaryEntry *newEntry = (DiaryEntry *) malloc(sizeof(DiaryEntry));

    if (newEntry == NULL) {
        printf("Error: Could not allocate memory for new entry.\n");
        return;
    }

    strcpy(newEntry->name, name);
    strcpy(newEntry->entry, entry);
    newEntry->next = head;
    head = newEntry;
}

void viewEntries() {
    DiaryEntry *current = head;

    if (head == NULL) {
        printf("Your digital diary is empty.\n");
        return;
    }

    printf("\nDigital Diary Entries:\n");
    while (current != NULL) {
        printf("%s:\n%s\n", current->name, current->entry);
        current = current->next;
    }
}

void deleteEntry(const char *name) {
    DiaryEntry *previous = NULL;
    DiaryEntry *current = head;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Entry not found.\n");
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

int main() {
    char command[10];
    char name[MAX_NAME_LENGTH];
    char entry[MAX_ENTRY_LENGTH];

    while (1) {
        printf("\nDigital Diary > ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Name: ");
            scanf("%s", name);
            printf("Entry: ");
            scanf("%[^\n]", entry);
            addEntry(name, entry);
        } else if (strcmp(command, "view") == 0) {
            viewEntries();
        } else if (strcmp(command, "delete") == 0) {
            printf("Name: ");
            scanf("%s", name);
            deleteEntry(name);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}