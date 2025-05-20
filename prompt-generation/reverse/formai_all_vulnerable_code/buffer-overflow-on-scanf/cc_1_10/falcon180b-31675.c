//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 100
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);
    num_entries++;
}

void delete_entry() {
    printf("Enter name to delete: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], sizeof(entry_t) * (num_entries - i - 1));
            num_entries--;
            break;
        }
    }
}

void search_entry() {
    printf("Enter name to search: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            break;
        }
    }
}

int main() {
    printf("Welcome to the Post-Apocalyptic Phonebook!\n");
    while (1) {
        printf("\n1. Add Entry\n2. Delete Entry\n3. Search Entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                delete_entry();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}