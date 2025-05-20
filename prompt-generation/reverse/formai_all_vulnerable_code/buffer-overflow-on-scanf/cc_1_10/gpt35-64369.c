//FormAI DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CONTACTS 100 // Maximum contacts that can be stored

struct contact { // Contact structure to hold a contact's information
    char name[50];
    char phone[20];
};

struct phone_book {
    int count;
    struct contact contacts[MAX_CONTACTS];
};

struct phone_book create_phone_book() { // Function to create a new phone book
    struct phone_book pb;
    pb.count = 0;
    return pb;
}

void add_contact(struct phone_book* pb, char* name, char* phone) { // Function to add a new contact to the phone book
    if (pb->count >= MAX_CONTACTS) {
        printf("Cannot add contact. Phone book is full.\n");
        return;
    }
    struct contact c;
    strcpy(c.name, name);
    strcpy(c.phone, phone);
    pb->contacts[pb->count++] = c;
    printf("Contact added successfully.\n");
}

void search_contact(struct phone_book* pb, char* name) { // Function to search for a contact in the phone book
    int i;
    for (i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void delete_contact(struct phone_book* pb, char* name) { // Function to delete a contact from the phone book
    int i;
    for (i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            int j;
            for (j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void print_phone_book(struct phone_book* pb) { // Function to print the entire phone book
    int i;
    for (i = 0; i < pb->count; i++) {
        printf("Name: %s\nPhone: %s\n\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
}

int main() {
    struct phone_book pb = create_phone_book();
    while (1) {
        printf("Phone Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Print Phone Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Enter name: ");
                char name[50];
                scanf("%s", name);
                printf("Enter phone number: ");
                char phone[20];
                scanf("%s", phone);
                add_contact(&pb, name, phone);
                break;
            }
            case 2: {
                printf("Enter name: ");
                char name[50];
                scanf("%s", name);
                search_contact(&pb, name);
                break;
            }
            case 3: {
                printf("Enter name: ");
                char name[50];
                scanf("%s", name);
                delete_contact(&pb, name);
                break;
            }
            case 4: {
                print_phone_book(&pb);
                break;
            }
            case 5: {
                printf("Exiting phone book.\n");
                exit(0);
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
    return 0;
}