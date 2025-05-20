//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: thoughtful
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

int add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].phone);
    num_entries++;
    return 0;
}

int delete_entry() {
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);
    int i = 0;
    while (i < num_entries) {
        if (strcmp(name, phonebook[i].name) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].phone, "");
            printf("Entry deleted.\n");
            num_entries--;
            return 0;
        }
        i++;
    }
    printf("Entry not found.\n");
    return 0;
}

int search_entry() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    int i = 0;
    while (i < num_entries) {
        if (strcmp(name, phonebook[i].name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
            return 0;
        }
        i++;
    }
    printf("Entry not found.\n");
    return 0;
}

int main() {
    int choice;
    do {
        printf("Phone book:\n1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}