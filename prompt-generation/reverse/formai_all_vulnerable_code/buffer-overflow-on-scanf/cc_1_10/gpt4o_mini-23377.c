//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} PhoneBook;

void add_contact(PhoneBook *pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("My dear Watson, we seem to have reached our limit of contacts!\n");
        return;
    }

    Contact new_contact;
    printf("Enter the name of the new contact: ");
    fgets(new_contact.name, NAME_LENGTH, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0; // Remove trailing newline

    printf("Enter the phone number of %s: ", new_contact.name);
    fgets(new_contact.phone, PHONE_LENGTH, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = 0; // Remove trailing newline

    pb->contacts[pb->count++] = new_contact;
    printf("Contact %s has been added to the phone book!\n", new_contact.name);
}

void search_contact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name to search for: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Found: %s - %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Alas, dear Watson, no such contact found!\n");
}

void delete_contact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            printf("The contact %s has been deleted!\n", name);
            return;
        }
    }
    printf("We have failed to locate the contact to delete, Watson!\n");
}

void display_contacts(PhoneBook *pb) {
    if (pb->count == 0) {
        printf("The phone book is empty, my friend!\n");
        return;
    }
    printf("Here are the contacts in your phone book:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d. %s - %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

int main() {
    PhoneBook pb;
    pb.count = 0;

    int choice;
    while (1) {
        printf("\n--- Sherlock's Phone Book ---\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline leftover

        switch (choice) {
            case 1:
                add_contact(&pb);
                break;
            case 2:
                search_contact(&pb);
                break;
            case 3:
                delete_contact(&pb);
                break;
            case 4:
                display_contacts(&pb);
                break;
            case 5:
                printf("Goodbye, Watson! Until next time!\n");
                exit(0);
            default:
                printf("That is not an option I can consider, my good fellow!\n");
        }
    }
    return 0;
}