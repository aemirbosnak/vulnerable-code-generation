//FormAI DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phonebook {
    char name[30];
    char number[12];
    struct phonebook *next;
};

void addEntry(struct phonebook **head, char *name, char *number) {
    struct phonebook *newEntry = malloc(sizeof(struct phonebook));
    strncpy(newEntry->name, name, 30);
    strncpy(newEntry->number, number, 12);
    newEntry->next = *head;
    *head = newEntry;
}

void printPhonebook(struct phonebook *head) {
    printf("Name\t\tNumber\n");
    printf("-------------------------\n");
    while (head != NULL) {
        printf("%s\t\t%s\n", head->name, head->number);
        head = head->next;
    }
}

struct phonebook* searchEntry(struct phonebook *head, char *name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void deleteEntry(struct phonebook **head, char *name) {
    struct phonebook *current = *head;
    struct phonebook *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Entry not found in phonebook.\n");
}

int main() {
    struct phonebook *head = NULL;
    int choice;
    char name[30];
    char number[12];
    while (1) {
        printf("1. Add entry\n");
        printf("2. Print phonebook\n");
        printf("3. Search for entry\n");
        printf("4. Delete entry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                addEntry(&head, name, number);
                break;
            case 2:
                printPhonebook(head);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                struct phonebook *entry = searchEntry(head, name);
                if (entry != NULL) {
                    printf("Number for %s: %s\n", entry->name, entry->number);
                } else {
                    printf("Entry not found in phonebook.\n");
                }
                break;
            case 4:
                printf("Enter name: ");
                scanf("%s", name);
                deleteEntry(&head, name);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    }
    return 0;
}