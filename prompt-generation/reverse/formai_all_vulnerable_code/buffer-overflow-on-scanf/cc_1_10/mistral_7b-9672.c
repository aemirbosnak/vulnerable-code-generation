//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char number[20];
    char sentiment[20];
} Contact;

bool is_full(Contact contacts[MAX_CONTACTS]) {
    int i;
    for (i = 0; i < MAX_CONTACTS; i++) {
        if (contacts[i].name[0] == '\0') {
            return false;
        }
    }
    return true;
}

bool add_contact(Contact *contacts, const char *name, const char *number, const char *sentiment) {
    if (is_full(contacts)) {
        printf("Your heart is full, cannot add more love.\n");
        return false;
    }

    strcpy(contacts->name, name);
    strcpy(contacts->number, number);
    strcpy(contacts->sentiment, sentiment);

    contacts++;
    return true;
}

void search_contact(const Contact contacts[MAX_CONTACTS], const char *name) {
    int i;
    for (i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Number: %s\n", contacts[i].number);
            printf("Sentiment: %s\n", contacts[i].sentiment);
            return;
        }
    }

    printf("Love of your life not found.\n");
}

void delete_contact(Contact *contacts, const char *name) {
    int i;
    for (i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            memset(&(contacts[i]), 0, sizeof(Contact));
            return;
        }
    }

    printf("Love not found to be deleted.\n");
}

int main() {
    Contact my_contacts[MAX_CONTACTS];
    char name[50];
    char number[20];
    char sentiment[20];

    while (true) {
        printf("\nWhat would you like to do, my love?\n");
        printf("1. Add a new contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of your new love: ");
                scanf("%s", name);
                printf("Enter the number of your new love: ");
                scanf("%s", number);
                printf("Enter the sentiment for your new love: ");
                scanf("%s", sentiment);

                add_contact(my_contacts, name, number, sentiment);
                break;

            case 2:
                printf("Enter the name of the love you are looking for: ");
                scanf("%s", name);
                search_contact(my_contacts, name);
                break;

            case 3:
                printf("Enter the name of the love you want to delete: ");
                scanf("%s", name);
                delete_contact(my_contacts, name);
                break;

            case 4:
                printf("I understand, my love. Goodbye.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}