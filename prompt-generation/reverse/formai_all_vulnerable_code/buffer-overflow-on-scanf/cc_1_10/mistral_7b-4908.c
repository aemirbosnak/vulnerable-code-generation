//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char phone[20];
} Entry;

Entry phonebook[MAX_ENTRIES];
int count = 0;

void add_contact(Entry *entry, char *name, char *phone) {
    if (count == MAX_ENTRIES) {
        printf("Phonebook is full.\n");
        return;
    }
    strcpy(entry->name, name);
    strcpy(entry->phone, phone);
    count++;
}

void search_contact(Entry *phonebook, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s, Phone: %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    char command[20];
    char name[NAME_LENGTH];
    char phone[20];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Name: ");
            scanf("%s", name);
            printf("Phone: ");
            scanf("%s", phone);
            add_contact(phonebook, name, phone);
        } else if (strcmp(command, "search") == 0) {
            printf("Name: ");
            scanf("%s", name);
            search_contact(phonebook, count, name);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}