//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char number[15];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void print_phonebook() {
    printf("Name\t\tNumber\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t\t%s\n", phonebook[i].name, phonebook[i].number);
    }
}

void add_entry() {
    char name[50];
    char number[15];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter number: ");
    scanf("%s", number);

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);

    num_entries++;
}

void delete_entry() {
    int index;

    printf("Enter index of entry to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_entries) {
        for (int i = index; i < num_entries - 1; i++) {
            strcpy(phonebook[i].name, phonebook[i+1].name);
            strcpy(phonebook[i].number, phonebook[i+1].number);
        }
        num_entries--;
    } else {
        printf("Invalid index.\n");
    }
}

void search_entry() {
    char name[50];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Number: %s\n", phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;

    printf("Welcome to the Post-Apocalyptic Phone Book!\n");
    printf("1. Add entry\n");
    printf("2. Delete entry\n");
    printf("3. Search entry\n");
    printf("4. Print phonebook\n");
    printf("5. Exit\n");

    while (1) {
        printf("Enter choice: ");
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
                print_phonebook();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}