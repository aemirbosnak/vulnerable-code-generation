//FormAI DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 30
#define MAX_EMAIL 50
#define MAX_ENTRIES 100

struct contact {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
};

// Function to validate email address
int validate_email(const char* email) {
    const char* at = strchr(email, '@');
    if (at == NULL) {
        return 0;
    }
    const char* dot = strchr(at, '.');
    if (dot == NULL) {
        return 0;
    }
    return 1;
}

// Function to add contact to mailing list
void add_contact(struct contact* mailing_list, int* num_entries) {
    if (*num_entries == MAX_ENTRIES) {
        printf("Mailing list is full\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", mailing_list[*num_entries].name);

    printf("Enter email: ");
    scanf("%s", mailing_list[*num_entries].email);

    if (!validate_email(mailing_list[*num_entries].email)) {
        printf("Invalid email address\n");
        return;
    }

    (*num_entries)++;
    printf("Contact added to mailing list\n");
}

// Function to remove contact from mailing list
void remove_contact(struct contact* mailing_list, int* num_entries) {
    if (*num_entries == 0) {
        printf("Mailing list is empty\n");
        return;
    }

    char name[MAX_NAME];
    printf("Enter name: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < *num_entries; i++) {
        if (strcmp(name, mailing_list[i].name) == 0) {
            break;
        }
    }

    if (i == *num_entries) {
        printf("Contact not found in mailing list\n");
        return;
    }

    (*num_entries)--;
    for (; i < *num_entries; i++) {
        strcpy(mailing_list[i].name, mailing_list[i + 1].name);
        strcpy(mailing_list[i].email, mailing_list[i + 1].email);
    }

    printf("Contact removed from mailing list\n");
}

// Function to display mailing list
void display_mailing_list(const struct contact* mailing_list, int num_entries) {
    printf("Mailing list:\n");
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", mailing_list[i].name, mailing_list[i].email);
    }
}

int main() {
    struct contact mailing_list[MAX_ENTRIES];
    int num_entries = 0;

    printf("Mailing List Manager\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Display mailing list\n");
        printf("4. Quit\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact(mailing_list, &num_entries);
            break;
        case 2:
            remove_contact(mailing_list, &num_entries);
            break;
        case 3:
            display_mailing_list(mailing_list, num_entries);
            break;
        case 4:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}