//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
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

void print_entries() {
    printf("Phonebook:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

void delete_entry() {
    printf("Enter name to delete: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            memmove(&phonebook[i], &phonebook[i + 1], (num_entries - i - 1) * sizeof(entry_t));
            num_entries--;
            break;
        }
    }
}

void search_entry() {
    printf("Enter name to search: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            printf("Number: %s\n", phonebook[i].number);
            break;
        }
    }
}

int main() {
    printf("Phonebook\n");
    while (1) {
        printf("1. Add entry\n2. Print entries\n3. Delete entry\n4. Search entry\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                print_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                search_entry();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}