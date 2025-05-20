//FormAI DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char name[50];
    int age;
    char phone[15];
    char address[100];
} Contact;

void clearConsole() {
    printf("\e[1;1H\e[2J");
}

void addContact(Contact *contacts, int *count) {
    char buf[250];
    char choice;

    clearConsole();
    printf("Enter name: ");
    fgets(contacts[*count].name, sizeof(contacts[*count].name), stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0;
    printf("Enter age: ");
    fgets(buf, sizeof(buf), stdin);
    contacts[*count].age = atoi(buf);
    printf("Enter phone number: ");
    fgets(contacts[*count].phone, sizeof(contacts[*count].phone), stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0;
    printf("Enter address: ");
    fgets(contacts[*count].address, sizeof(contacts[*count].address), stdin);
    contacts[*count].address[strcspn(contacts[*count].address, "\n")] = 0;

    printf("Do you want to add another contact? (Y)es or (N)o: ");
    fgets(buf, sizeof(buf), stdin);
    choice = buf[0];

    if (choice == 'Y' || choice == 'y') {
        (*count)++;
        addContact(contacts, count);
    }
}

void viewContact(Contact *contacts, int count) {
    int i;
    char buf[5];

    clearConsole();
    printf("==============================\n");
    printf("      Sherlock's Phone Book      \n");
    printf("==============================\n\n");

    for (i = 0; i < count; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Age: %d\n", contacts[i].age);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Address: %s\n\n", contacts[i].address);
    }

    printf("Press enter to return to the main menu.");
    fgets(buf, sizeof(buf), stdin);
}

int main() {
    int choice;
    int count = 0;
    Contact *contacts = malloc(sizeof(Contact) * 100);

    while (1) {
        clearConsole();
        printf("==============================\n");
        printf("      Sherlock's Phone Book      \n");
        printf("==============================\n\n");
        printf("Please choose an option:\n");
        printf("1. Add contact\n");
        printf("2. View contacts\n");
        printf("3. Exit\n");

        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                viewContact(contacts, count);
                break;
            case 3:
                free(contacts);
                return 0;
            default:
                printf("Invalid choice. Press enter to try again.");
                getchar();
                break;
        }
    }
}