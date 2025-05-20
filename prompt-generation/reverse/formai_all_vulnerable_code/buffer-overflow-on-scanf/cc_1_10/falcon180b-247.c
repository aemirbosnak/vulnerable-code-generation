//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char number[15];
} entry;

entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
}

void delete_entry() {
    printf("Enter name to delete: ");
    char name[50];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], sizeof(entry) * (num_entries - i - 1));
            num_entries--;
            break;
        }
    }
}

void search_entry() {
    printf("Enter name to search: ");
    char name[50];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
            break;
        }
    }
}

void print_all_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Print all entries\n5. Exit\n");
        printf("Enter your choice: ");
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
                print_all_entries();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}