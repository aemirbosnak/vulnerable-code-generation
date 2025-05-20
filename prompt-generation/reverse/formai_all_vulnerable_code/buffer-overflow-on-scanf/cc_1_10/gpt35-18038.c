//FormAI DATASET v1.0 Category: Mailing list manager ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100 // maximum number of emails in the mailing list
#define MAX_LENGTH 50  // maximum length of an email address

/* struct to hold information about an email */
struct Email {
    char address[MAX_LENGTH]; // the email address
    int subscribed;           // whether or not the email is subscribed (1 = yes, 0 = no)
};

/* function to add a new email to the mailing list */
void add_email(struct Email *mailing_list, int *num_emails) {
    if (*num_emails == MAX_EMAILS) { // check if the mailing list is already full
        printf("Mailing list is full. Cannot add any more emails.\n");
        return;
    }

    struct Email new_email; // create a new email struct to hold the new email address

    printf("Enter email address: ");
    scanf("%s", new_email.address); // read in the email address

    // check if a duplicate email address already exists in the mailing list
    for (int i = 0; i < *num_emails; i++) {
        if (strcmp(mailing_list[i].address, new_email.address) == 0) {
            printf("Email address already exists in mailing list.\n");
            return;
        }
    }

    new_email.subscribed = 1; // set the new email to subscribed by default
    mailing_list[*num_emails] = new_email; // add the new email to the mailing list
    (*num_emails)++; // increment the number of emails in the mailing list

    printf("Email address successfully added to mailing list.\n");
}

/* function to remove an email from the mailing list */
void remove_email(struct Email *mailing_list, int *num_emails) {
    char address[MAX_LENGTH];

    printf("Enter email address to remove: ");
    scanf("%s", address); // read in the email address to remove

    // find the email's index in the mailing list
    int i = 0;
    while (i < *num_emails && strcmp(mailing_list[i].address, address) != 0) {
        i++;
    }

    if (i == *num_emails) { // email address was not found in the mailing list
        printf("Email address not found in mailing list.\n");
        return;
    }

    // shift all emails after the removed email down one index in the mailing list
    for (int j = i; j < *num_emails - 1; j++) {
        mailing_list[j] = mailing_list[j + 1];
    }

    (*num_emails)--; // decrement the number of emails in the mailing list

    printf("Email address successfully removed from mailing list.\n");
}

/* function to toggle a specific email's subscription status */
void toggle_subscription(struct Email *mailing_list, int num_emails) {
    char address[MAX_LENGTH];

    printf("Enter email address to toggle subscription status: ");
    scanf("%s", address); // read in the email address to toggle

    // find the email's index in the mailing list
    int i = 0;
    while (i < num_emails && strcmp(mailing_list[i].address, address) != 0) {
        i++;
    }

    if (i == num_emails) { // email address was not found in the mailing list
        printf("Email address not found in mailing list.\n");
        return;
    }

    if (mailing_list[i].subscribed) { // if email is currently subscribed
        mailing_list[i].subscribed = 0; // unsubscribe the email
        printf("Email address has been unsubscribed from the mailing list.\n");
    } else { // if email is currently unsubscribed
        mailing_list[i].subscribed = 1; // resubscribe the email
        printf("Email address has been subscribed to the mailing list.\n");
    }
}

/* function to print out all emails in the mailing list */
void print_mailing_list(struct Email *mailing_list, int num_emails) {
    if (num_emails == 0) {
        printf("There are no emails in the mailing list.\n");
        return;
    }

    printf("Mailing list:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s - %s\n", mailing_list[i].address, mailing_list[i].subscribed ? "subscribed" : "unsubscribed");
    }
}

int main() {
    struct Email mailing_list[MAX_EMAILS]; // array to hold all emails in the mailing list
    int num_emails = 0; // number of emails currently in the mailing list

    while (1) { // repeat indefinitely until the user chooses to exit
        int choice;

        printf("\n1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Toggle subscription status\n");
        printf("4. View mailing list\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email(mailing_list, &num_emails);
                break;
            case 2:
                remove_email(mailing_list, &num_emails);
                break;
            case 3:
                toggle_subscription(mailing_list, num_emails);
                break;
            case 4:
                print_mailing_list(mailing_list, num_emails);
                break;
            case 5:
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    }
}