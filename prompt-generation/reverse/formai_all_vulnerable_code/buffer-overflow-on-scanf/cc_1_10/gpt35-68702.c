//FormAI DATASET v1.0 Category: Phone Book ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    long int number;
    char email[50];
};

void addContact(struct Contact *book, int *bookSize) {
    printf("Enter name: ");
    scanf("%s", book[*bookSize].name);
    printf("Enter phone number: ");
    scanf("%ld", &book[*bookSize].number);
    printf("Enter email: ");
    scanf("%s", book[*bookSize].email);
    *bookSize = *bookSize + 1;
}

void printContacts(struct Contact *book, int bookSize) {
    if (bookSize == 0) {
        printf("Your Phone Book is Empty!\n");
        return;
    }
    printf("%-30s%-20s%-30s\n", "Name", "Phone Number", "Email");
    for (int i = 0; i < bookSize; i++) {
        printf("%-30s%-20ld%-30s\n", book[i].name, book[i].number, book[i].email);
    }
}

int searchContact(struct Contact *book, int bookSize, char *name) {
    for (int i = 0; i < bookSize; i++) {
        if (strcmp(book[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteContact(struct Contact *book, int *bookSize, char *name) {
    int index = searchContact(book, *bookSize, name);
    if (index == -1) {
        printf("Contact not found!\n");
        return;
    }
    for (int i = index; i < *bookSize - 1; i++) {
        strcpy(book[i].name, book[i+1].name);
        book[i].number = book[i+1].number;
        strcpy(book[i].email, book[i+1].email);
    }
    printf("Contact deleted successfully!\n");
    *bookSize = *bookSize - 1;
}

int main() {
    printf("Welcome to your Phone Book!\n");

    int bookSize = 0;
    struct Contact *book = (struct Contact*) malloc(10 * sizeof(struct Contact));

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Add a Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search for a Contact\n");
        printf("4. Delete a Contact\n");
        printf("5. Exit\n");

        int option;
        scanf("%d", &option);

        if (option == 1) {
            addContact(book, &bookSize);
        } else if (option == 2) {
            printContacts(book, bookSize);
        } else if (option == 3) {
            printf("Enter name: ");
            char name[50];
            scanf("%s", name);
            int index = searchContact(book, bookSize, name);
            if (index == -1) {
                printf("Contact not found!\n");
            } else {
                printf("%-30s%-20s%-30s\n", "Name", "Phone Number", "Email");
                printf("%-30s%-20ld%-30s\n", book[index].name, book[index].number, book[index].email);
            }
        } else if (option == 4) {
            printf("Enter name: ");
            char name[50];
            scanf("%s", name);
            deleteContact(book, &bookSize, name);
        } else if (option == 5) {
            printf("Thank you for using Phone Book!\n");
            free(book);
            exit(0);
        } else {
            printf("Invalid option!\n");
        }
    }

    return 0;
}