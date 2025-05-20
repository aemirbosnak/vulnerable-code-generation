//FormAI DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <string.h>

// Structure to hold contact information
struct contact {
    char name[30];
    char phone[10];
};

// Array to store contacts
struct contact medieval[100];

// Count to keep track of number of contacts in phone book
int count = 0;

int main() {
    int choice;
    char name[30];
    char phone[10];

    printf("Welcome to the Medieval Phone Book!\n");

    // Loop for menu
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add contact\n");
        printf("2. List contacts\n");
        printf("3. Search contact\n");
        printf("0. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {

            // Add contact
            case 1:
                printf("Enter name : ");
                scanf("%s", medieval[count].name);
                printf("Enter phone number : ");
                scanf("%s", medieval[count].phone);
                count++;
                printf("Contact added successfully!\n");
                break;

            // List contacts
            case 2:
                if (count == 0) {
                    printf("No contacts found.\n");
                } else {
                    printf("List of contacts:\n");
                    for (int i = 0; i < count; i++) {
                        printf("Name: %s\nPhone: %s\n", medieval[i].name, medieval[i].phone);
                    }
                }
                break;

            // Search contact
            case 3:
                printf("Enter name to search : ");
                scanf("%s", name);
                for (int i = 0; i < count; i++) {
                    if (strcmp(medieval[i].name, name) == 0) {
                        printf("Contact found!\nName: %s\nPhone: %s\n", medieval[i].name, medieval[i].phone);
                        break;
                    }
                    if (i == count - 1) {
                        printf("Contact not found.\n");
                    }
                }
                break;

            // Quit
            case 0:
                printf("Goodbye!\n");
                return 0;

            // Invalid choice
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}