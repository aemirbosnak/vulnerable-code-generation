//FormAI DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <string.h>
#define MAX_CONTACTS 100

struct contact {
    char name[30];
    long int phone;
};

void print_menu() {
    printf("******************\n");
    printf("** Phone Book  **\n");
    printf("******************\n");
    printf("1. Add a contact\n");
    printf("2. Search a contact\n");
    printf("3. Remove a contact\n");
    printf("4. Print all contacts\n");
    printf("5. Quit\n");
    printf("\n");
}

int add_contact(struct contact phone_book[], int num_contacts) {
    if (num_contacts == MAX_CONTACTS) {
        printf("Error: Phone book is full.\n");
        return num_contacts;
    }

    printf("Enter new contact's name: ");
    scanf("%s", phone_book[num_contacts].name);
    printf("Enter new contact's phone number: ");
    scanf("%ld", &phone_book[num_contacts].phone);
    printf("Contact added successfully.\n");

    return num_contacts + 1;
}

int search_contact(struct contact phone_book[], int num_contacts) {
    char search_name[30];
    int i;
    int found = 0;

    printf("Enter name to search for: ");
    scanf("%s", search_name);

    for (i = 0; i < num_contacts; i++) {
        if (!strcmp(search_name, phone_book[i].name)) {
            printf("Name: %s, Phone: %ld\n", phone_book[i].name, phone_book[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }

    return num_contacts;
}

int remove_contact(struct contact phone_book[], int num_contacts) {
    char delete_name[30];
    int i, j;
    int found = 0;

    printf("Enter name to delete: ");
    scanf("%s", delete_name);

    for (i = 0; i < num_contacts; i++) {
        if (!strcmp(delete_name, phone_book[i].name)) {
            found = 1;
            printf("Deleted: %s, %ld\n", phone_book[i].name, phone_book[i].phone);
            for (j = i; j < num_contacts - 1; j++) {
                strcpy(phone_book[j].name, phone_book[j+1].name);
                phone_book[j].phone = phone_book[j+1].phone;
            }
            num_contacts--;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }

    return num_contacts;
}

void print_contacts(struct contact phone_book[], int num_contacts) {
    int i;

    printf("Contacts:\n");

    for (i = 0; i < num_contacts; i++) {
        printf("Name: %s, Phone: %ld\n", phone_book[i].name, phone_book[i].phone);
    }
}

int main() {
    struct contact phone_book[MAX_CONTACTS];
    int num_contacts = 0;
    int choice;

    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                num_contacts = add_contact(phone_book, num_contacts);
                break;
            case 2:
                num_contacts = search_contact(phone_book, num_contacts);
                break;
            case 3:
                num_contacts = remove_contact(phone_book, num_contacts);
                break;
            case 4:
                print_contacts(phone_book, num_contacts);
                break;
            case 5:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid selection.\n");
                break;
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}