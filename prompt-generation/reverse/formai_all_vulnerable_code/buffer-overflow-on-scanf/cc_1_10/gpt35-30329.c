//FormAI DATASET v1.0 Category: Mailing list manager ; Style: invasive
#include <stdio.h>
#include <string.h>

#define MAX_EMAILS 100 // maximum number of emails that can be stored in the program

// structure to store email details
struct Email {
    char name[50]; // name of the recipient
    char address[100]; // email address
};

// function to add a new email to the mailing list
void add_email(struct Email list[], int *size) {
    // check if the maximum number of emails has been reached
    if (*size >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }
    // get email details from the user
    struct Email new_email;
    printf("Enter recipient name: ");
    scanf("%s", new_email.name);
    printf("Enter email address: ");
    scanf("%s", new_email.address);
    // add new email to the list
    list[*size] = new_email;
    (*size)++;
    printf("Email added successfully!\n");
}

// function to delete an email from the mailing list
void delete_email(struct Email list[], int *size) {
    // check if the mailing list is empty
    if (*size == 0) {
        printf("Error: Mailing list is empty.\n");
        return;
    }
    // get email address to delete from the user
    char email_address[100];
    printf("Enter email address to delete: ");
    scanf("%s", email_address);
    // search for email in the list
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp(list[i].address, email_address) == 0) {
            index = i;
            break;
        }
    }
    // check if email was found
    if (index == -1) {
        printf("Error: Email address not found in mailing list.\n");
        return;
    }
    // shift emails to fill the gap left by the deleted email
    for (int i = index; i < (*size)-1; i++) {
        list[i] = list[i+1];
    }
    (*size)--;
    printf("Email deleted successfully!\n");
}

// function to print all emails in the mailing list
void print_emails(struct Email list[], int size) {
    // check if the mailing list is empty
    if (size == 0) {
        printf("Mailing list is empty.\n");
        return;
    }
    printf("Mailing list:\n");
    for (int i = 0; i < size; i++) {
        printf("%s <%s>\n", list[i].name, list[i].address);
    }
}

// main function
int main() {
    struct Email mailing_list[MAX_EMAILS]; // array to store mailing list
    int list_size = 0; // number of emails currently in the list
    char option;
    // program menu
    do {
        printf("\nMailing list manager:\n");
        printf("1. Add email\n");
        printf("2. Delete email\n");
        printf("3. Print all emails\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf(" %c", &option);
        switch(option) {
            case '1':
                add_email(mailing_list, &list_size);
                break;
            case '2':
                delete_email(mailing_list, &list_size);
                break;
            case '3':
                print_emails(mailing_list, list_size);
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != '4');
    return 0;
}