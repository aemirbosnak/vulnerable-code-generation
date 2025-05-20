//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

struct PhoneBookEntry {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
};

struct PhoneBook {
    struct PhoneBookEntry entries[MAX_ENTRIES];
    int count;
};

void addEntry(struct PhoneBook *pb) {
    if (pb->count >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }
    
    printf("Enter name: ");
    scanf("%s", pb->entries[pb->count].name);
    printf("Enter phone number: ");
    scanf("%s", pb->entries[pb->count].phone);
    pb->count++;
    printf("Entry added successfully!\n");
}

void searchEntry(struct PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            printf("Found: %s - %s\n", pb->entries[i].name, pb->entries[i].phone);
            return;
        }
    }
    printf("Entry not found!\n");
}

void deleteEntry(struct PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            for (int j = i; j < pb->count - 1; j++) {
                pb->entries[j] = pb->entries[j + 1];
            }
            pb->count--;
            printf("Entry deleted successfully!\n");
            return;
        }
    }
    printf("Entry not found!\n");
}

void displayEntries(struct PhoneBook *pb) {
    if (pb->count == 0) {
        printf("Phone book is empty!\n");
        return;
    }

    printf("Phone Book Entries:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d: %s - %s\n", i + 1, pb->entries[i].name, pb->entries[i].phone);
    }
}

void menu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Entry\n");
    printf("2. Search Entry\n");
    printf("3. Delete Entry\n");
    printf("4. Display Entries\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    struct PhoneBook myPhoneBook;
    myPhoneBook.count = 0;
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(&myPhoneBook);
                break;
            case 2:
                searchEntry(&myPhoneBook);
                break;
            case 3:
                deleteEntry(&myPhoneBook);
                break;
            case 4:
                displayEntries(&myPhoneBook);
                break;
            case 5:
                printf("Exiting the Phone Book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}