//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Entry {
    char title[100];
    char content[500];
    struct Entry *next;
} Entry;

Entry *head = NULL;

void addEntry(char *title, char *content) {
    Entry *newEntry = (Entry *)malloc(sizeof(Entry));
    strcpy(newEntry->title, title);
    strcpy(newEntry->content, content);
    newEntry->next = head;
    head = newEntry;
}

void displayMenu() {
    printf("\nDigital Diary\n");
    printf("-------------------------\n");
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("3. Search Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Quit\n");
}

void displayEntries() {
    Entry *current = head;
    int i = 1;
    while (current != NULL) {
        printf("%d. %s\n", i, current->title);
        i++;
        current = current->next;
    }
}

void searchEntry(int index) {
    Entry *current = head;
    int i = 1;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Entry not found.\n");
    } else {
        printf("\nTitle: %s\nContent: %s\n", current->title, current->content);
    }
}

void deleteEntry(int index) {
    Entry *current = head;
    Entry *previous = NULL;

    int i = 1;
    while (current != NULL && i < index) {
        previous = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Entry not found.\n");
    } else {
        if (previous == NULL) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

int main() {
    char title[100], content[500];
    int choice;
    int index;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter content: ");
                scanf("%[^\n]s", content);
                addEntry(title, content);
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                printf("Enter index to search: ");
                scanf("%d", &index);
                searchEntry(index);
                break;
            case 4:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteEntry(index);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}