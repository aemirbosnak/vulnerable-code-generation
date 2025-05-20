//FormAI DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
};

int main() {
    int option, size = 0;
    struct Contact book[100];

    do {
        printf("*********** PHONE BOOK ***********\n");
        printf("1. Add a contact\n");
        printf("2. View a contact\n");
        printf("3. Edit a contact\n");
        printf("4. Delete a contact\n");
        printf("5. View all contacts\n");
        printf("6. Exit\n");
        printf("**********************************\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n*********** ADD CONTACT ***********\n");
                printf("Enter name: ");
                scanf("%s", book[size].name);
                printf("Enter phone number: ");
                scanf("%s", book[size].phone);
                size++;
                printf("Contact added successfully.\n");
                break;

            case 2:
                if (size == 0) {
                    printf("\nPhone book is empty.\n");
                    break;
                }
                printf("\n*********** VIEW CONTACT ***********\n");
                printf("Enter name: ");
                char search_name[50];
                scanf("%s", search_name);
                int found = 0; // check if search_name is found
                for (int i = 0; i < size; i++) {
                    if (!strcmp(search_name, book[i].name)) {
                        printf("Name: %s\nPhone number: %s\n", book[i].name, book[i].phone);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Contact not found.\n");
                }
                break;

            case 3:
                if (size == 0) {
                    printf("\nPhone book is empty.\n");
                    break;
                }
                printf("\n*********** EDIT CONTACT ***********\n");
                printf("Enter name: ");
                char edit_name[50];
                scanf("%s", edit_name);
                found = 0; // check if edit_name is found
                for (int i = 0; i < size; i++) {
                    if (!strcmp(edit_name, book[i].name)) {
                        printf("Current Name: %s\nCurrent Phone number: %s\n", book[i].name, book[i].phone);
                        printf("Enter new name (or same name to skip): ");
                        scanf("%s", book[i].name);
                        printf("Enter new phone number (or same number to skip): ");
                        scanf("%s", book[i].phone);
                        printf("Contact updated successfully.\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Contact not found.\n");
                }
                break;

            case 4:
                if (size == 0) {
                    printf("\nPhone book is empty.\n");
                    break;
                }
                printf("\n*********** DELETE CONTACT ***********\n");
                printf("Enter name: ");
                char delete_name[50];
                scanf("%s", delete_name);
                found = 0; // check if delete_name is found
                for (int i = 0; i < size; i++) {
                    if (!strcmp(delete_name, book[i].name)) {
                        for (int j = i; j < size - 1; j++) {
                            strcpy(book[j].name, book[j + 1].name);
                            strcpy(book[j].phone, book[j + 1].phone);
                        }
                        size--;
                        printf("Contact deleted successfully.\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Contact not found.\n");
                }
                break;

            case 5:
                if (size == 0) {
                    printf("\nPhone book is empty.\n");
                    break;
                }
                printf("\n*********** VIEW ALL CONTACTS ***********\n");
                for (int i = 0; i < size; i++) {
                    printf("Name: %s\nPhone number: %s\n", book[i].name, book[i].phone);
                }
                break;

            case 6:
                printf("\nExiting Phone Book...\n");
                break;

            default:
                printf("\nInvalid Option!\n");
                break;
        }
        printf("\nPress Enter to continue...\n");
        getchar();
        getchar();
    } while (option != 6);

    return 0;
}