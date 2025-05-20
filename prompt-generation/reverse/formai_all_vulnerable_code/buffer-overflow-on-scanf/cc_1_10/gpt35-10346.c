//FormAI DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_NUM_LEN 10
#define MAX_ENTRIES 100

struct phonebook_entry {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
};

void add_entry(struct phonebook_entry* entries, int* num_entries);
void delete_entry(struct phonebook_entry* entries, int* num_entries);
void find_entry(struct phonebook_entry* entries, int num_entries);
void print_entries(struct phonebook_entry* entries, int num_entries);

int main() {
    struct phonebook_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    
    printf("WELCOME TO C PHONE BOOK!\n\n");

    while (1) {
        char choice;
        printf("Enter 'a' to add a new entry, 'd' to delete an entry, 'f' to find an entry, 'p' to print all entries, or 'q' to quit: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                add_entry(entries, &num_entries);
                break;
            case 'd':
                delete_entry(entries, &num_entries);
                break;
            case 'f':
                find_entry(entries, num_entries);
                break;
            case 'p':
                print_entries(entries, num_entries);
                break;
            case 'q':
                printf("GOODBYE!\n");
                return 0;
            default:
                printf("INVALID CHOICE. PLEASE TRY AGAIN.\n");
                break;
        }
    }
}

void add_entry(struct phonebook_entry* entries, int* num_entries) {
    if (*num_entries >= MAX_ENTRIES) {
        printf("PHONE BOOK IS FULL. CANNOT ADD NEW ENTRY.\n");
        return;
    }

    struct phonebook_entry new_entry;

    printf("ENTER NAME (UP TO %d CHARACTERS): ", MAX_NAME_LEN);
    scanf("%s", new_entry.name);

    printf("ENTER NUMBER (UP TO %d DIGITS): ", MAX_NUM_LEN);
    scanf("%s", new_entry.number);

    entries[*num_entries] = new_entry;
    (*num_entries)++;

    printf("\nENTRY ADDED SUCCESSFULLY!\n\n");
}

void delete_entry(struct phonebook_entry* entries, int* num_entries) {
    if (*num_entries == 0) {
        printf("PHONE BOOK IS EMPTY. CANNOT DELETE ENTRY.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    printf("ENTER NAME TO DELETE: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < *num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("DELETING ENTRY FOR %s...\n", entries[i].name);
            memmove(&entries[i], &entries[i+1], (*num_entries - i - 1) * sizeof(struct phonebook_entry));
            (*num_entries)--;
            printf("DELETE SUCCESSFUL!\n\n");
            return;
        }
    }

    printf("ENTRY FOR %s NOT FOUND. DELETE FAILED.\n\n", name);
}

void find_entry(struct phonebook_entry* entries, int num_entries) {
    if (num_entries == 0) {
        printf("PHONE BOOK IS EMPTY. CANNOT FIND ENTRY.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    printf("ENTER NAME TO FIND: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("ENTRY FOUND!\n");
            printf("NAME: %s\n", entries[i].name);
            printf("NUMBER: %s\n\n", entries[i].number);
            return;
        }
    }

    printf("ENTRY FOR %s NOT FOUND.\n\n", name);
}

void print_entries(struct phonebook_entry* entries, int num_entries) {
    if (num_entries == 0) {
        printf("PHONE BOOK IS EMPTY. NOTHING TO PRINT.\n");
        return;
    }

    int i;
    for (i = 0; i < num_entries; i++) {
        printf("ENTRY #%d\n", i+1);
        printf("NAME: %s\n", entries[i].name);
        printf("NUMBER: %s\n\n", entries[i].number);
    }
}