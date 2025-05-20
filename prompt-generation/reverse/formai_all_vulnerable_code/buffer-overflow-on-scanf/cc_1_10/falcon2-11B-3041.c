//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct PhoneBook {
    char name[50];
    char number[20];
};

void add_contact(struct PhoneBook *book, char *name, char *number) {
    if (name == NULL || number == NULL) {
        fprintf(stderr, "Error: Invalid input\n");
        return;
    }
    book->name[0] = '\0';
    strcpy(book->name, name);
    book->number[0] = '\0';
    strcpy(book->number, number);
}

void display_contact(struct PhoneBook *book) {
    printf("Name: %s\n", book->name);
    printf("Number: %s\n", book->number);
}

int main() {
    struct PhoneBook phone_book[100];
    int num_contacts = 0;

    while (1) {
        printf("Menu:\n");
        printf("1. Add contact\n");
        printf("2. Display contact\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                char name[50];
                scanf("%s", name);
                printf("Enter number: ");
                char number[20];
                scanf("%s", number);
                add_contact(phone_book + num_contacts, name, number);
                num_contacts++;
                break;
            case 2:
                if (num_contacts == 0) {
                    printf("No contacts found\n");
                    break;
                }
                printf("Enter contact number to display: ");
                char contact_number[20];
                scanf("%s", contact_number);
                for (int i = 0; i < num_contacts; i++) {
                    if (strcmp(phone_book[i].number, contact_number) == 0) {
                        display_contact(phone_book + i);
                        break;
                    }
                }
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}