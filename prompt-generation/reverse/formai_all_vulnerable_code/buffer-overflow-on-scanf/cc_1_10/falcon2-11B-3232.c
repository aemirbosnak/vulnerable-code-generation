//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to store mailing list information
struct MailingList {
    char name[50];
    char email[100];
    char comments[100];
};

// Define a function to create a new mailing list
void createMailingList(struct MailingList* ml) {
    printf("Enter the name of the mailing list: ");
    fgets(ml->name, sizeof(ml->name), stdin);

    // Trim the trailing newline character from the input
    ml->name[strcspn(ml->name, "\n")] = '\0';

    printf("Enter the email address of the mailing list: ");
    fgets(ml->email, sizeof(ml->email), stdin);

    // Trim the trailing newline character from the input
    ml->email[strcspn(ml->email, "\n")] = '\0';

    printf("Enter the comments for the mailing list: ");
    fgets(ml->comments, sizeof(ml->comments), stdin);

    // Trim the trailing newline character from the input
    ml->comments[strcspn(ml->comments, "\n")] = '\0';
}

// Define a function to display a mailing list
void displayMailingList(struct MailingList* ml) {
    printf("Name: %s\n", ml->name);
    printf("Email: %s\n", ml->email);
    printf("Comments: %s\n", ml->comments);
}

// Define a function to add a new mailing list
void addMailingList(struct MailingList* ml) {
    printf("Enter the name of the new mailing list: ");
    fgets(ml->name, sizeof(ml->name), stdin);

    // Trim the trailing newline character from the input
    ml->name[strcspn(ml->name, "\n")] = '\0';

    printf("Enter the email address of the new mailing list: ");
    fgets(ml->email, sizeof(ml->email), stdin);

    // Trim the trailing newline character from the input
    ml->email[strcspn(ml->email, "\n")] = '\0';

    printf("Enter the comments for the new mailing list: ");
    fgets(ml->comments, sizeof(ml->comments), stdin);

    // Trim the trailing newline character from the input
    ml->comments[strcspn(ml->comments, "\n")] = '\0';

    printf("New mailing list added successfully!\n");
}

// Define a function to search for a mailing list by name
void searchMailingList(struct MailingList* ml, char* name) {
    printf("Enter the name of the mailing list to search for: ");
    fgets(name, sizeof(name), stdin);

    // Trim the trailing newline character from the input
    name[strcspn(name, "\n")] = '\0';

    int i;
    for (i = 0; i < sizeof(ml) / sizeof(struct MailingList); i++) {
        if (strcmp(name, ml[i].name) == 0) {
            printf("Mailing list found!\n");
            displayMailingList(&ml[i]);
        }
    }
}

// Define a function to delete a mailing list by name
void deleteMailingList(struct MailingList* ml, char* name) {
    printf("Enter the name of the mailing list to delete: ");
    fgets(name, sizeof(name), stdin);

    // Trim the trailing newline character from the input
    name[strcspn(name, "\n")] = '\0';

    int i;
    for (i = 0; i < sizeof(ml) / sizeof(struct MailingList); i++) {
        if (strcmp(name, ml[i].name) == 0) {
            memmove(&ml[i], &ml[i + 1], (sizeof(struct MailingList) * (i + 1)) - (sizeof(struct MailingList) * i));
            printf("Mailing list deleted successfully!\n");
            break;
        }
    }
}

int main() {
    struct MailingList ml[10]; // Create a dynamic array of mailing lists
    int choice, i = 0;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Create a new mailing list\n");
        printf("2. Add a new mailing list\n");
        printf("3. Display all mailing lists\n");
        printf("4. Search for a mailing list\n");
        printf("5. Delete a mailing list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createMailingList(&ml[i]);
                break;
            case 2:
                addMailingList(&ml[i]);
                break;
            case 3:
                for (i = 0; i < sizeof(ml) / sizeof(struct MailingList); i++) {
                    displayMailingList(&ml[i]);
                }
                break;
            case 4:
                printf("Enter the name of the mailing list to search for: ");
                fgets(ml[i].name, sizeof(ml[i].name), stdin);

                searchMailingList(&ml[i], ml[i].name);
                break;
            case 5:
                printf("Enter the name of the mailing list to delete: ");
                fgets(ml[i].name, sizeof(ml[i].name), stdin);

                deleteMailingList(&ml[i], ml[i].name);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice!= 6);

    return 0;
}