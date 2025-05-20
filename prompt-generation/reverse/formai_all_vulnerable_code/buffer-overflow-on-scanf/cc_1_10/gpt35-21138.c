//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure for the mailing list
struct email {
    char name[100];
    char email_address[100];
};

// Function to add a new email to the list
void add_email(struct email *list, int *size) {
    printf("Enter name: ");
    scanf("%s", list[*size].name);
    printf("Enter email address: ");
    scanf("%s", list[*size].email_address);
    (*size)++;
}

// Function to display all emails in the list
void display_emails(struct email *list, int size) {
    if (size == 0) {
        printf("Mailing list is empty.\n");
        return;
    }
    printf("Mailing list:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", list[i].name, list[i].email_address);
    }
}

// Function to search for an email address from the list
void search_email(struct email *list, int size) {
    if (size == 0) {
        printf("Mailing list is empty.\n");
        return;
    }
    char search[100];
    printf("Enter email address to search: ");
    scanf("%s", search);
    for (int i = 0; i < size; i++) {
        if (strcmp(search, list[i].email_address) == 0) {
            printf("%s: %s\n", list[i].name, list[i].email_address);
            return;
        }
    }
    printf("Email address not found.\n");
}

int main() {
    struct email list[100];
    int size = 0;
    int choice;

    do {
        printf("MENU\n");
        printf("1. Add email\n");
        printf("2. Display all emails\n");
        printf("3. Search email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email(list, &size);
                break;
            case 2:
                display_emails(list, size);
                break;
            case 3:
                search_email(list, size);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}