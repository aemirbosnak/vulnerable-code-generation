//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[15];
} entry;

entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(entry e) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }
    strcpy(phonebook[num_entries].name, e.name);
    strcpy(phonebook[num_entries].phone, e.phone);
    num_entries++;
}

void display_entries() {
    printf("Phone Book Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

void search_entry(char* name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Found entry for %s:\n", name);
            printf("Phone number: %s\n", phonebook[i].phone);
            return;
        }
    }
    printf("Entry not found!\n");
}

int main() {
    char choice;
    while (1) {
        printf("Phone Book Menu:\n");
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
        case '1':
            {
                entry e;
                printf("Enter name: ");
                scanf("%s", e.name);
                printf("Enter phone number: ");
                scanf("%s", e.phone);
                add_entry(e);
                break;
            }
        case '2':
            display_entries();
            break;
        case '3':
            {
                char name[50];
                printf("Enter name to search: ");
                scanf("%s", name);
                search_entry(name);
                break;
            }
        case '4':
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}