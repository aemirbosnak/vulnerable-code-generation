//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PHONES 100
#define MAX_NAME 20
#define MAX_NUM 15

struct PhoneBook {
    char name[MAX_NAME];
    char phone[MAX_NUM];
};

void print_menu();
void add_contact(struct PhoneBook *book);
void delete_contact(struct PhoneBook *book);
void search_contact(struct PhoneBook *book);
void list_all_contacts(struct PhoneBook *book);

int main() {
    struct PhoneBook book[MAX_PHONES];
    int num_contacts = 0;
    int choice;

    print_menu();
    scanf("%d", &choice);

    while (choice != 4) {
        switch (choice) {
            case 1:
                add_contact(&book[num_contacts]);
                num_contacts++;
                break;
            case 2:
                delete_contact(&book[num_contacts]);
                break;
            case 3:
                search_contact(&book[num_contacts]);
                break;
            case 4:
                list_all_contacts(&book[num_contacts]);
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
        print_menu();
        scanf("%d", &choice);
    }

    return 0;
}

void print_menu() {
    printf("---------------------------------------------\n");
    printf("Phone Book\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact\n");
    printf("4. List All Contacts\n");
    printf("5. Exit\n");
    printf("---------------------------------------------\n");
    printf("Enter your choice: ");
}

void add_contact(struct PhoneBook *book) {
    printf("Enter the name: ");
    scanf("%s", book->name);
    printf("Enter the phone number: ");
    scanf("%s", book->phone);
}

void delete_contact(struct PhoneBook *book) {
    printf("Enter the name of the contact to delete: ");
    char name[MAX_NAME];
    scanf("%s", name);
    int i;
    for (i = 0; i < MAX_PHONES; i++) {
        if (strcmp(name, book[i].name) == 0) {
            book[i].name[0] = '\0';
            book[i].phone[0] = '\0';
            break;
        }
    }
    if (i == MAX_PHONES) {
        printf("Contact not found.\n");
    }
}

void search_contact(struct PhoneBook *book) {
    printf("Enter the name of the contact to search: ");
    char name[MAX_NAME];
    scanf("%s", name);
    int i;
    for (i = 0; i < MAX_PHONES; i++) {
        if (strcmp(name, book[i].name) == 0) {
            printf("Name: %s\nPhone: %s\n", book[i].name, book[i].phone);
            break;
        }
    }
    if (i == MAX_PHONES) {
        printf("Contact not found.\n");
    }
}

void list_all_contacts(struct PhoneBook *book) {
    int i;
    for (i = 0; i < MAX_PHONES; i++) {
        if (book[i].name[0] != '\0') {
            printf("Name: %s\nPhone: %s\n", book[i].name, book[i].phone);
        }
    }
}