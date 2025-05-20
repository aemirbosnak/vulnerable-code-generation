//FormAI DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of emails allowed in the mailing list
#define MAX_EMAILS 1000

// Define the maximum length of each email address
#define MAX_EMAIL_LENGTH 50

// Define the structure of each email address
struct email {
    char address[MAX_EMAIL_LENGTH];
};

// Define the structure of the mailing list
struct mailing_list {
    struct email list[MAX_EMAILS];
    int count;
};

// Function to add an email address to the mailing list
void add_email(struct mailing_list *list, char new_email[MAX_EMAIL_LENGTH]) {
    if (list->count < MAX_EMAILS) {
        strcpy(list->list[list->count].address, new_email);
        list->count++;
        printf("New email added!\n");
    }
    else {
        printf("Mailing list is full. Could not add email.\n");
    }
}

// Function to remove an email address from the mailing list
void remove_email(struct mailing_list *list, char email_to_remove[MAX_EMAIL_LENGTH]) {
    int i, found_index;
    for (i = 0; i < list->count; i++) {
        if (strcmp(list->list[i].address, email_to_remove) == 0) {
            found_index = i;
            break;
        }
    }
    if (i == list->count) {
        printf("Email not found in mailing list.\n");
    }
    else {
        for (i = found_index; i < list->count - 1; i++) {
            strcpy(list->list[i].address, list->list[i+1].address);
        }
        list->count--;
        printf("Email removed!\n");
    }
}

// Function to print all the email addresses in the mailing list
void print_mailing_list(struct mailing_list *list) {
    printf("Mailing list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i+1, list->list[i].address);
    }
}

int main() {
    // Initialize the mailing list structure
    struct mailing_list list = {
        .list = {},
        .count = 0
    };

    // Display the menu options
    printf("Mailing list manager\n");
    printf("--------------------\n");
    printf("1. Add email to mailing list\n");
    printf("2. Remove email from mailing list\n");
    printf("3. Print mailing list\n");
    printf("4. Quit\n");

    // Start the main loop
    int option = 0;
    while (option != 4) {
        printf("Enter option: ");
        scanf("%d", &option);

        // Execute the chosen menu option
        switch (option) {
            case 1:
                printf("Enter email address to add: ");
                char new_email[MAX_EMAIL_LENGTH];
                scanf("%s", new_email);
                add_email(&list, new_email);
                break;
            case 2:
                printf("Enter email address to remove: ");
                char email_to_remove[MAX_EMAIL_LENGTH];
                scanf("%s", email_to_remove);
                remove_email(&list, email_to_remove);
                break;
            case 3:
                print_mailing_list(&list);
                break;
            case 4:
                printf("Exiting Mailing List Manager\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}