//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000    // maximum number of emails that can be stored
#define MAX_NAME 50        // maximum length for a name
#define MAX_EMAIL 100      // maximum length for an email

// define an Email struct to store each email and name
typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
} Email;

// function to add a new email to the list
void add_email(Email *list, int *count) {
    if (*count >= MAX_EMAILS) {    // check if we've reached the maximum number of emails
        printf("Unable to add new email, limit reached.\n");
        return;
    }

    char name[MAX_NAME];
    char email[MAX_EMAIL];

    // get input from the user
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);

    // create a new Email struct and add it to the list
    Email new_email = { .name = name, .email = email };
    list[*count] = new_email;
    (*count)++;    // increment the counter for the number of emails in the list

    printf("Email added successfully!\n");
}

// function to print out all emails in the list
void print_emails(Email *list, int count) {
    printf("Email List:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", list[i].name, list[i].email);
    }
}

// function to search for an email by name
void search_email(Email *list, int count) {
    char search_name[MAX_NAME];

    // get input from the user
    printf("Enter name to search: ");
    scanf("%s", search_name);

    // search for the email in the list and print it out if found
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].name, search_name) == 0) {
            printf("%s: %s\n", list[i].name, list[i].email);
            return;
        }
    }

    printf("No email found for that name.\n");
}

int main() {
    Email list[MAX_EMAILS];    // create an array of Emails to store our mailing list
    int count = 0;             // set the initial count of emails to 0

    int choice = 0;
    while (1) {
        // print out the menu of options for the user
        printf("\nMailing List Manager\n");
        printf("1. Add new email\n");
        printf("2. Print all emails\n");
        printf("3. Search for email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email(list, &count);
                break;
            case 2:
                print_emails(list, count);
                break;
            case 3:
                search_email(list, count);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}