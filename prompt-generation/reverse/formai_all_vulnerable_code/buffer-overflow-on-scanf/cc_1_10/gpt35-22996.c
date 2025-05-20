//FormAI DATASET v1.0 Category: Phone Book ; Style: funny
#include<stdio.h>
#include<string.h>
#define MAX_CONTACTS 100

struct contact {
    char name[50];
    char phone_number[15];
    char email[50];
};

int count = 0;
struct contact contacts[MAX_CONTACTS];

int add_contact() {
    if (count == MAX_CONTACTS) {
        printf("Sorry, the phonebook is full!\n");
        return 1;
    }
    printf("Enter the name: ");
    scanf("%s", contacts[count].name);
    printf("Enter the phone number: ");
    scanf("%s", contacts[count].phone_number);
    printf("Enter the email: ");
    scanf("%s", contacts[count].email);

    count++;
    printf("Contact added!\n");
    return 0;
}

int delete_contact() {
    char name[50];
    printf("Enter the name of the contact you wish to delete: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (!strcmp(name, contacts[i].name)) {
            printf("Contact deleted!");
            contacts[i] = contacts[count - 1];
            count--;
            return 0;
        }
    }

    printf("Sorry, the contact was not found.\n");
    return 1;
}

void print_contact(struct contact c) {
    printf("\nName: %s\n", c.name);
    printf("Phone number: %s\n", c.phone_number);
    printf("Email: %s\n", c.email);
}

int search_contact() {
    char name[50];
    printf("Enter the name of the contact you wish to find: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (!strcmp(name, contacts[i].name)) {
            printf("Contact found!\n");
            print_contact(contacts[i]);
            return 0;
        }
    }

    printf("Sorry, the contact was not found.\n");
    return 1;
}

void list_contacts() {
    if (count == 0) {
        printf("The phonebook is empty!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        print_contact(contacts[i]);
        printf("\n");
    }
}

int main() {
    int choice, result;
    printf("Welcome to the Funny Phonebook!\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search for a contact\n");
        printf("4. List all contacts\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                result = add_contact();
                break;
            case 2:
                result = delete_contact();
                break;
            case 3:
                result = search_contact();
                break;
            case 4:
                list_contacts();
                result = 0;
                break;
            case 5:
                result = 0;
                break;
            default:
                printf("Invalid choice, please try again.\n");
                result = 1;
        }
    } while(result != 0);

    printf("Goodbye!\n");
    
    return 0;
}