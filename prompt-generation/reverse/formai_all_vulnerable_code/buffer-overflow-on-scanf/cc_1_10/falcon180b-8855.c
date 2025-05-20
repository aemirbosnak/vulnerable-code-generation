//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} phone_entry;

phone_entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(phone_entry* entry) {
    strcpy(phonebook[num_entries].name, entry->name);
    strcpy(phonebook[num_entries].number, entry->number);
    num_entries++;
}

void remove_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(&phonebook[i], &phonebook[i + 1], (num_entries - i - 1) * sizeof(phone_entry));
            num_entries--;
            break;
        }
    }
}

void search_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            break;
        }
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
    int choice;

    do {
        printf("Phone Book\n");
        printf("1. Add Entry\n2. Remove Entry\n3. Search Entry\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_entry(&(phone_entry){.name = name,.number = number});
                break;
            case 2:
                printf("Enter name to remove: ");
                scanf("%s", name);
                remove_entry(name);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                search_entry(name);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}