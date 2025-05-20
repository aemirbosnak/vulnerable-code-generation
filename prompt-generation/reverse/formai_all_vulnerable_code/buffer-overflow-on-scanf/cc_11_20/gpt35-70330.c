//FormAI DATASET v1.0 Category: Phone Book ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
};

int main() {
    struct Contact phonebook[10];
    int choice, size = 0;
    char temp[50], search[50];
    do {
        printf("-----C PHONE BOOK-----\n");
        printf("1. Add new contact\n");
        printf("2. Search for contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if (size >= 10) {
                    printf("Phone book is full.\n");
                    break;
                }
                printf("Enter name: ");
                scanf("%s", phonebook[size].name);
                printf("Enter phone number (format xxx-xxx-xxxx): ");
                scanf("%s", phonebook[size].phone);
                printf("Contact added!\n");
                size++;
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", search);
                for (int i=0; i<size; i++) {
                    if (strcmp(phonebook[i].name, search) == 0) {
                        printf("Contact found:\n");
                        printf("Name: %s\n", phonebook[i].name);
                        printf("Phone number: %s\n", phonebook[i].phone);
                        break;
                    }
                    if (i == size - 1) {
                        printf("Contact not found.\n");
                    }
                }
                break;
            case 3:
                printf("All contacts:\n");
                for (int i=0; i<size; i++) {
                    printf("%d. Name: %s\n", i+1, phonebook[i].name);
                    printf("   Phone number: %s\n", phonebook[i].phone);
                }
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}