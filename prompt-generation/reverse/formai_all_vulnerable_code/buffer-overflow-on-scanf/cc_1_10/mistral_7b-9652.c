//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct _PhoneBookEntry {
    char name[NAME_LENGTH];
    char number[20];
} PhoneBookEntry;

PhoneBookEntry phoneBook[MAX_ENTRIES];
int emptySlots = MAX_ENTRIES;

int _isNameValid(char *name) {
    int len = strlen(name);
    if (len > NAME_LENGTH - 1) {
        return 0;
    }
    for (int i = 0; i < len; ++i) {
        if (name[i] < 'A' || name[i] > 'Z' ||
            (name[i] > 'Z' && name[i] < 'a') || name[i] > 'z') {
            return 0;
        }
    }
    return 1;
}

int _addEntry(PhoneBookEntry *entry, char *name, char *number) {
    if (!_isNameValid(name)) {
        return -1;
    }
    if (emptySlots == 0) {
        printf("Phone book is full.\n");
        return -1;
    }
    strcpy(entry->name, name);
    strcpy(entry->number, number);
    --emptySlots;
    return 1;
}

int _searchByName(char *name) {
    for (int i = 0; i < emptySlots; ++i) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s, Number: %s\n", phoneBook[i].name, phoneBook[i].number);
            return 1;
        }
    }
    printf("Name not found.\n");
    return -1;
}

int main(int argc, char *argv[]) {
    char command[20], name[NAME_LENGTH], number[20];

    while (1) {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "exit") == 0) {
            break;
        }
        if (strcmp(command, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);
            _addEntry(phoneBook, name, number);
        } else if (strcmp(command, "search") == 0) {
            printf("Enter name to search: ");
            scanf("%s", name);
            _searchByName(name);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}