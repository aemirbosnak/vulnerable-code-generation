//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[15];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* phone) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full.\n");
        return;
    }

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].phone, phone);
    num_entries++;
}

void delete_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid entry index.\n");
        return;
    }

    num_entries--;
    for (int i = index; i < num_entries; i++) {
        phonebook[i] = phonebook[i+1];
    }
}

void search_entry(char* name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }

    printf("Entry not found.\n");
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Print entries\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                char name[50];
                scanf("%s", name);

                printf("Enter phone: ");
                char phone[15];
                scanf("%s", phone);

                add_entry(name, phone);
                break;

            case 2:
                printf("Enter entry index to delete: ");
                int index;
                scanf("%d", &index);

                delete_entry(index);
                break;

            case 3:
                printf("Enter name to search: ");
                char search_name[50];
                scanf("%s", search_name);

                search_entry(search_name);
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