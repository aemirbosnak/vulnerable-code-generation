//FormAI DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_NUMBER_LENGTH 11

typedef struct phonebook {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
    struct phonebook* next;
} Phonebook;

/* The head of our linked list */
Phonebook* head = NULL;

void print_phonebook() {
    if (head == NULL) {
        printf("Phonebook is empty.\n");
        return;
    }

    Phonebook* current = head;
    int i = 1;
    while (current != NULL) {
        printf("%d. %s: %s\n", i, current->name, current->number);
        current = current->next;
        i++;
    }
}

void add_entry(char* name, char* number) {
    Phonebook* new_entry = (Phonebook*)malloc(sizeof(Phonebook));
    if (new_entry == NULL) {
        printf("Error: Unable to allocate memory for new entry.\n");
        return;
    }

    strncpy(new_entry->name, name, MAX_NAME_LENGTH - 1);
    strncpy(new_entry->number, number, MAX_NUMBER_LENGTH - 1);
    new_entry->next = head;
    head = new_entry;
}

void search_for_entry(char* name) {
    Phonebook* current = head;
    int i = 1;
    while (current != NULL) {
        if (strncmp(current->name, name, MAX_NAME_LENGTH - 1) == 0) {
            printf("%d. %s: %s\n", i, current->name, current->number);
            return;
        }
        current = current->next;
        i++;
    }
    printf("Entry for %s not found.\n", name);
}

void delete_entry(char* name) {
    Phonebook *current = head, *previous = NULL;
    while (current != NULL) {
        if (strncmp(current->name, name, MAX_NAME_LENGTH - 1) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Entry for %s deleted from phonebook.\n", name);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Entry for %s not found.\n", name);
}

int main() {
    char command;
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    while (1) {
        printf("\nEnter command (a - add, s - search, d - delete, p - print, q - quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'a':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_entry(name, number);
                break;
            case 's':
                printf("Enter name to search for: ");
                scanf("%s", name);
                search_for_entry(name);
                break;
            case 'd':
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_entry(name);
                break;
            case 'p':
                print_phonebook();
                break;
            case 'q':
                printf("Quitting phonebook.\n");
                exit(0);
            default:
                printf("Invalid command.\n");
                break;
        }
    }
    return 0;
}