//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TITLE_LENGTH 50
#define MAX_BODY_LENGTH 100

typedef struct Entry {
    char title[MAX_TITLE_LENGTH];
    char body[MAX_BODY_LENGTH];
    struct Entry *next;
} Entry;

Entry *head = NULL;

void displayMenu() {
    printf("\nDigital Diary\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

void addEntry(char title[], char body[]) {
    Entry *newEntry = (Entry *)malloc(sizeof(Entry));
    strcpy(newEntry->title, title);
    strcpy(newEntry->body, body);
    newEntry->next = head;
    head = newEntry;
}

void viewEntries() {
    Entry *current = head;
    if (head == NULL) {
        printf("No entries found.\n");
        return;
    }

    printf("\n----------------------\n");
    printf("Title\t\tDate\t\tBody\n");
    printf("----------------------\n");

    while (current != NULL) {
        time_t now = time(NULL);
        char dt[20];
        strftime(dt, sizeof(dt), "%Y-%m-%d %H:%M:%S", localtime(&now));
        printf("%s\t%s\t%s\n", current->title, dt, current->body);
        current = current->next;
    }
}

void deleteEntry(char title[]) {
    Entry *current = head;
    Entry *previous = NULL;

    if (head == NULL) {
        printf("No entries found.\n");
        return;
    }

    while (current != NULL && strcmp(current->title, title) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Entry not found.\n");
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
    char title[MAX_TITLE_LENGTH], body[MAX_BODY_LENGTH];
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter body: ");
                scanf("%[^\n]s", body);
                addEntry(title, body);
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("Enter title to delete: ");
                scanf("%s", title);
                deleteEntry(title);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}