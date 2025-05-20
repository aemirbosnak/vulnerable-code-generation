//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_NUMBER 15
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME];
    char number[MAX_NUMBER];
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
    int index;
    printf("Enter index of entry to delete: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_entries) {
        for (int i = index; i < num_entries - 1; i++) {
            strcpy(phonebook[i].name, phonebook[i + 1].name);
            strcpy(phonebook[i].number, phonebook[i + 1].number);
        }
        num_entries--;
    } else {
        printf("Invalid index.\n");
    }
}

void search_entry() {
    char search_name[MAX_NAME];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    int index = -1;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(search_name, phonebook[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index >= 0) {
        printf("Name: %s\nNumber: %s\n", phonebook[index].name, phonebook[index].number);
    } else {
        printf("Entry not found.\n");
    }
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Print entries\n5. Exit\n");
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
                print_entries();
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