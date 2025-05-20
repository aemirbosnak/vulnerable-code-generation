//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the structure for a phone book entry
typedef struct {
    char name[50];
    char phone[15];
} phonebook_entry;

// Define the structure for the phone book
typedef struct {
    int num_entries;
    phonebook_entry entries[100];
} phonebook;

// Function to add a new entry to the phone book
void add_entry(phonebook* pb, char* name, char* phone) {
    if (pb->num_entries == 100) {
        printf("Phone book is full. Cannot add more entries.\n");
        return;
    }
    int i;
    for (i = 0; i < pb->num_entries; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            printf("Entry already exists. Cannot add duplicate entries.\n");
            return;
        }
    }
    strcpy(pb->entries[pb->num_entries].name, name);
    strcpy(pb->entries[pb->num_entries].phone, phone);
    pb->num_entries++;
}

// Function to search for an entry in the phone book
int search_entry(phonebook* pb, char* name) {
    int i;
    for (i = 0; i < pb->num_entries; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to display all entries in the phone book
void display_entries(phonebook* pb) {
    int i;
    for (i = 0; i < pb->num_entries; i++) {
        printf("%s - %s\n", pb->entries[i].name, pb->entries[i].phone);
    }
}

int main() {
    phonebook pb;
    pb.num_entries = 0;
    char choice;
    do {
        printf("\nPhone Book\n");
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Display Entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
        case '1':
            printf("Enter name: ");
            char name[50];
            scanf("%s", name);
            printf("Enter phone number: ");
            char phone[15];
            scanf("%s", phone);
            add_entry(&pb, name, phone);
            break;
        case '2':
            printf("Enter name to search: ");
            char search_name[50];
            scanf("%s", search_name);
            int index = search_entry(&pb, search_name);
            if (index!= -1) {
                printf("Phone number for %s: %s\n", pb.entries[index].name, pb.entries[index].phone);
            } else {
                printf("Entry not found.\n");
            }
            break;
        case '3':
            display_entries(&pb);
            break;
        case '4':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');
    return 0;
}