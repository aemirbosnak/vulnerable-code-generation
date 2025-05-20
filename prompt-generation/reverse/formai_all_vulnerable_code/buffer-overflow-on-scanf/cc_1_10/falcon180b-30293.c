//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[15];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* phone) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }
    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].phone, phone);
    num_entries++;
    printf("Entry added successfully.\n");
}

void search_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }
    printf("Entry not found.\n");
}

void delete_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memset(phonebook[i].name, 0, sizeof(phonebook[i].name));
            memset(phonebook[i].phone, 0, sizeof(phonebook[i].phone));
            num_entries--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    int choice;
    char name[50], phone[15];

    printf("Welcome to the Phone Book!\n");
    while (1) {
        printf("\n1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone number: ");
            scanf("%s", phone);
            add_entry(name, phone);
            break;
        case 2:
            printf("Enter name to search: ");
            scanf("%s", name);
            search_entry(name);
            break;
        case 3:
            printf("Enter name to delete: ");
            scanf("%s", name);
            delete_entry(name);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}