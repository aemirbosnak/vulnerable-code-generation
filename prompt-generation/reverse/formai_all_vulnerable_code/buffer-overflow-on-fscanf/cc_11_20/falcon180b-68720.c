//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Contact {
    char name[50];
    char number[15];
};

int main() {
    FILE *file;
    struct Contact contacts[100];
    int count = 0;
    char choice;

    file = fopen("phonebook.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %s", contacts[count].name, contacts[count].number)!= EOF) {
        count++;
    }

    fclose(file);

    do {
        printf("\nPhonebook Menu:\n");
        printf("1. Search contact\n");
        printf("2. Add contact\n");
        printf("3. Delete contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the name of the contact you want to search: ");
                scanf(" %[^\n]", contacts[0].name);
                printf("\n");
                for (int i = 0; i < count; i++) {
                    if (strcmp(contacts[i].name, contacts[0].name) == 0) {
                        printf("Name: %s\n", contacts[i].name);
                        printf("Number: %s\n", contacts[i].number);
                        printf("\n");
                    }
                }
                break;
            case '2':
                printf("Enter the name of the contact: ");
                scanf(" %[^\n]", contacts[count].name);
                printf("Enter the phone number of the contact: ");
                scanf(" %[^\n]", contacts[count].number);
                count++;
                printf("\n");
                printf("Contact added successfully.\n");
                break;
            case '3':
                printf("Enter the name of the contact you want to delete: ");
                scanf(" %[^\n]", contacts[0].name);
                for (int i = 0; i < count; i++) {
                    if (strcmp(contacts[i].name, contacts[0].name) == 0) {
                        for (int j = i; j < count - 1; j++) {
                            strcpy(contacts[j].name, contacts[j + 1].name);
                            strcpy(contacts[j].number, contacts[j + 1].number);
                        }
                        count--;
                        printf("\n");
                        printf("Contact deleted successfully.\n");
                    }
                }
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');

    return 0;
}