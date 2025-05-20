//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone_entry {
    char *name;
    char *number;
    struct phone_entry *next;
} phone_entry_t;

phone_entry_t *head = NULL;

void add_entry(char *name, char *number) {
    phone_entry_t *new_entry = malloc(sizeof(phone_entry_t));
    new_entry->name = strdup(name);
    new_entry->number = strdup(number);
    new_entry->next = head;
    head = new_entry;
}

void find_entry(char *name) {
    phone_entry_t *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s: %s\n", current->name, current->number);
            return;
        }
        current = current->next;
    }
    printf("%s not found.\n", name);
}

void remove_entry(char *name) {
    phone_entry_t *current = head;
    phone_entry_t *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current->number);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("%s not found.\n", name);
}

void print_all_entries() {
    phone_entry_t *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }
}

int main() {
    int choice;
    char name[100];
    char number[100];

    while (1) {
        printf("1. Add entry\n");
        printf("2. Find entry\n");
        printf("3. Remove entry\n");
        printf("4. Print all entries\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_entry(name, number);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                find_entry(name);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                remove_entry(name);
                break;
            case 4:
                print_all_entries();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}