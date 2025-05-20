//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 10

struct entry {
    char name[20];
    char phone[10];
    struct entry* next;
};

struct entry* head = NULL;

void addEntry(char name[], char phone[]) {
    struct entry* newEntry = (struct entry*) malloc(sizeof(struct entry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->phone, phone);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
        return;
    }

    struct entry* current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newEntry;
}

void searchEntry(char name[]) {
    struct entry* current = head;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s\n", current->name);
            printf("Phone: %s\n", current->phone);
            printf("---------------------------\n");
        }
        current = current->next;
    }
}

void updateEntry(char name[], char phone[]) {
    struct entry* current = head;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            strcpy(current->phone, phone);
            return;
        }
        current = current->next;
    }
    printf("Entry not found\n");
}

void deleteEntry(char name[]) {
    struct entry* current = head;
    struct entry* previous = NULL;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Entry not found\n");
}

int main() {
    char name[20];
    char phone[10];

    while (1) {
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Update entry\n");
        printf("4. Delete entry\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                addEntry(name, phone);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                searchEntry(name);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter new phone: ");
                scanf("%s", phone);
                updateEntry(name, phone);
                break;
            case 4:
                printf("Enter name: ");
                scanf("%s", name);
                deleteEntry(name);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}