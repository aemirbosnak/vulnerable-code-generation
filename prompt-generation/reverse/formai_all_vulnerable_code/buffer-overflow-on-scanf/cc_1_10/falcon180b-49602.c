//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// struct to hold phone book entry
typedef struct {
    char name[50];
    char phone[15];
} phone_entry;

// function to add an entry to the phone book
void add_entry(phone_entry entries[], int count) {
    char name[50];
    char phone[15];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    strcpy(entries[count].name, name);
    strcpy(entries[count].phone, phone);

    printf("Entry added.\n");
}

// function to search for an entry in the phone book
int search_entry(phone_entry entries[], int count, char search_name[]) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
            return 1;
        }
    }

    return 0;
}

// function to display all entries in the phone book
void display_entries(phone_entry entries[], int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
    }
}

int main() {
    phone_entry entries[MAX_ENTRIES];
    int count = 0;

    while (count < MAX_ENTRIES) {
        int choice;

        printf("\nPhone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Display all entries\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry(entries, count);
            break;
        case 2:
            printf("Enter name to search: ");
            char search_name[50];
            scanf("%s", search_name);
            search_entry(entries, count, search_name);
            break;
        case 3:
            display_entries(entries, count);
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}