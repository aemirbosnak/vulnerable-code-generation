//FormAI DATASET v1.0 Category: Phone Book ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 12

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Entry;

Entry phonebook[MAX_ENTRIES];
int num_entries = 0;

int add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full\n");
        return 0;
    }
    Entry e;
    printf("Enter name: ");
    fgets(e.name, MAX_NAME_LENGTH, stdin);
    e.name[strcspn(e.name, "\n")] = '\0';
    printf("Enter phone number (e.g. 123-4567): ");
    fgets(e.phone, MAX_PHONE_LENGTH, stdin);
    e.phone[strcspn(e.phone, "\n")] = '\0';
    phonebook[num_entries] = e;
    num_entries++;
    return 1;
}

void display_phonebook() {
    printf("Phonebook:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

int delete_entry(char* name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            for (int j = i; j < num_entries-1; j++) {
                phonebook[j] = phonebook[j+1];
            }
            num_entries--;
            return 1;
        }
    }
    printf("Could not find entry for %s\n", name);
    return 0;
}

void search_phonebook(char* name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s: %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }
    printf("Could not find entry for %s\n", name);
}

int main() {
    while (1) {
        printf("Select an option:\n");
        printf("1. Add an entry\n");
        printf("2. Delete an entry\n");
        printf("3. Search for a name\n");
        printf("4. Display phonebook\n");
        printf("5. Exit\n");
        int option;
        scanf("%d", &option);
        getchar();
        switch (option) {
            case 1:
                add_entry();
                break;
            case 2: {
                char name[MAX_NAME_LENGTH];
                printf("Enter name to delete: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';
                delete_entry(name);
                break;
            }
            case 3: {
                char name[MAX_NAME_LENGTH];
                printf("Enter name to search: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';
                search_phonebook(name);
                break;
            }
            case 4:
                display_phonebook();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}