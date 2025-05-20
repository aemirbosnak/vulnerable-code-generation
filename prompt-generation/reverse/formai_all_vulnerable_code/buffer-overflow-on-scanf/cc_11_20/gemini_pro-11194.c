//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char number[20];
} contact;

int main() {
    contact phoneBook[100];
    int numContacts = 0;
    char name[50];
    char number[20];
    int choice;

    do {
        printf("1. Add a contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]%*c", name);
                printf("Enter number: ");
                scanf(" %[^\n]%*c", number);
                strcpy(phoneBook[numContacts].name, name);
                strcpy(phoneBook[numContacts].number, number);
                numContacts++;
                break;
            case 2:
                for (int i = 0; i < numContacts; i++) {
                    printf("%s\t%s\n", phoneBook[i].name, phoneBook[i].number);
                }
                break;
            case 3:
                printf("Enter name to search for: ");
                scanf(" %[^\n]%*c", name);
                int found = 0;
                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(phoneBook[i].name, name) == 0) {
                        printf("Number: %s\n", phoneBook[i].number);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Contact not found.\n");
                }
                break;
            case 4:
                printf("Enter name to delete: ");
                scanf(" %[^\n]%*c", name);
                int deleted = 0;
                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(phoneBook[i].name, name) == 0) {
                        for (int j = i; j < numContacts - 1; j++) {
                            phoneBook[j] = phoneBook[j + 1];
                        }
                        numContacts--;
                        deleted = 1;
                    }
                }
                if (!deleted) {
                    printf("Contact not found.\n");
                }
                break;
            case 5:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}