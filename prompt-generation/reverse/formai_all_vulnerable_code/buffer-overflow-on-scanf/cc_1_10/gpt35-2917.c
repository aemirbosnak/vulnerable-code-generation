//FormAI DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

struct PhoneBook {
    struct Contact contacts[MAX_CONTACTS];
    int num_contacts;
};

// function prototypes
void add_contact(struct PhoneBook *book);
void edit_contact(struct PhoneBook *book);
void delete_contact(struct PhoneBook *book);
void search_contact(struct PhoneBook book);
void display_contacts(struct PhoneBook book);

int main() {
    struct PhoneBook book;
    book.num_contacts = 0;

    int choice;
    do {
        printf("\nWelcome to the Peaceful Phone Book\n");
        printf("-----------------------------------\n");
        printf("1. Add Contact\n");
        printf("2. Edit Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n");
        printf("5. Display All Contacts\n");
        printf("6. Exit\n");
        printf("Enter Your Choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(&book);
                break;
            case 2:
                edit_contact(&book);
                break;
            case 3:
                delete_contact(&book);
                break;
            case 4:
                search_contact(book);
                break;
            case 5:
                display_contacts(book);
                break;
            case 6:
                printf("\nThanks for using Peaceful Phone Book\n");
                break;
            default:
                printf("\nInvalid choice! Try Again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void add_contact(struct PhoneBook *book) {
    if (book->num_contacts == MAX_CONTACTS) {
        printf("\nThe phone book is full. Cannot add new contact.\n");
        return;
    }

    printf("\nEnter Contact Details:\n");
    printf("Name: ");
    scanf("%s", book->contacts[book->num_contacts].name);
    printf("Phone Number: ");
    scanf("%s", book->contacts[book->num_contacts].phone);
    printf("Email: ");
    scanf("%s", book->contacts[book->num_contacts].email);

    book->num_contacts++;
    printf("\nContact Added Successfully!\n");
}

void edit_contact(struct PhoneBook *book) {
    if (book->num_contacts == 0) {
        printf("\nNo contacts in phone book. Nothing to edit.\n");
        return;
    }

    printf("\nEnter the name of the contact to edit: ");
    char name[50];
    scanf("%s", name);

    int i, found = 0;
    for (i = 0; i < book->num_contacts; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            printf("\nEnter updated details:\n");
            printf("Name: ");
            scanf("%s", book->contacts[i].name);
            printf("Phone Number: ");
            scanf("%s", book->contacts[i].phone);
            printf("Email: ");
            scanf("%s", book->contacts[i].email);
            found = 1;
            printf("\nContact updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nContact not found. Cannot update.\n");
    }
}

void delete_contact(struct PhoneBook *book) {
    if (book->num_contacts == 0) {
        printf("\nNo contacts in phone book. Nothing to delete.\n");
        return;
    }

    printf("\nEnter the name of the contact to delete: ");
    char name[50];
    scanf("%s", name);

    int i, found = 0;
    for (i = 0; i < book->num_contacts; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            memmove(&book->contacts[i], &book->contacts[i+1], (book->num_contacts-i-1) * sizeof(struct Contact));
            book->num_contacts--;
            found = 1;
            printf("\nContact deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nContact not found. Cannot delete.\n");
    }
}

void search_contact(struct PhoneBook book) {
    if (book.num_contacts == 0) {
        printf("\nNo contacts in the phone book. Cannot search.\n");
        return;
    }

    printf("\nEnter a name or phone number to search: ");
    char search_term[50];
    scanf("%s", search_term);

    int i, found = 0;
    printf("\nSearch Results:\n");
    printf("-----------------\n");
    for (i = 0; i < book.num_contacts; i++) {
        if (strstr(book.contacts[i].name, search_term) != NULL || strstr(book.contacts[i].phone, search_term) != NULL) {
            printf("\nName: %s\nPhone: %s\nEmail: %s\n", book.contacts[i].name, book.contacts[i].phone, book.contacts[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo contacts found matching your search term.\n");
    }
}

void display_contacts(struct PhoneBook book) {
    int i;
    if (book.num_contacts == 0) {
        printf("\nNo contacts in phone book.\n");
        return;
    }

    printf("\nPhone Book Contacts:\n");
    printf("--------------------\n");
    for (i = 0; i < book.num_contacts; i++) {
        printf("\nContact %d:\n", i+1);
        printf("Name: %s\nPhone Number: %s\nEmail: %s\n", book.contacts[i].name, book.contacts[i].phone, book.contacts[i].email);
    }
}