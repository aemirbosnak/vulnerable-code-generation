//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 200

struct entry {
    char name[50];
    int phone;
};

void add_entry(struct entry *phonebook, char *name, int phone) {
    int i = 0;
    while (i < MAX_ENTRIES && strcmp(phonebook[i].name, name)!= 0) {
        i++;
    }
    if (i == MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(phonebook[i].name, name);
    phonebook[i].phone = phone;
}

void delete_entry(struct entry *phonebook, char *name) {
    int i = 0;
    while (i < MAX_ENTRIES && strcmp(phonebook[i].name, name)!= 0) {
        i++;
    }
    if (i == MAX_ENTRIES) {
        printf("Entry not found.\n");
        return;
    }
    memset(&phonebook[i], 0, sizeof(struct entry));
}

void search_entry(struct entry *phonebook, char *name) {
    int i = 0;
    while (i < MAX_ENTRIES && strcmp(phonebook[i].name, name)!= 0) {
        i++;
    }
    if (i == MAX_ENTRIES) {
        printf("Entry not found.\n");
        return;
    }
    printf("Phone number: %d\n", phonebook[i].phone);
}

int main() {
    struct entry phonebook[MAX_ENTRIES];
    memset(phonebook, 0, sizeof(phonebook));
    int choice, num_entries = 0;
    char name[50];
    while (1) {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%d", &phonebook[num_entries].phone);
                add_entry(phonebook, name, phonebook[num_entries].phone);
                num_entries++;
                break;
            case 2:
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_entry(phonebook, name);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                search_entry(phonebook, name);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}