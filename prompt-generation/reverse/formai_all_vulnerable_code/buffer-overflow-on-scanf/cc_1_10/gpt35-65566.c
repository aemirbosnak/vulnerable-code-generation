//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum size of the mailing list
#define MAX_SIZE 100

// Define the structure of each email
typedef struct {
    char name[50];
    char email[50];
} Email;

// Define the structure of the mailing list
typedef struct {
    Email emails[MAX_SIZE];
    int length;
} MailingList;

// Function to add a new email to the mailing list
void addEmail(MailingList *list, char name[], char email[]) {
    if (list->length == MAX_SIZE) {
        printf("Error: The mailing list is already full!\n");
    } else {
        Email newEmail;
        strcpy(newEmail.name, name);
        strcpy(newEmail.email, email);
        list->emails[list->length] = newEmail;
        list->length++;
        printf("New email added:\n");
        printf("Name: %s\n", name);
        printf("Email: %s\n", email);
    }
}

// Function to print all emails in the mailing list
void printEmails(MailingList list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list.length; i++) {
        printf("Name: %s\n", list.emails[i].name);
        printf("Email: %s\n", list.emails[i].email);
    }
}

int main() {
    MailingList list;
    list.length = 0;
    char option;
    char name[50];
    char email[50];
    bool exit = false;
    while (!exit) {
        printf("Welcome to the Mailing List Manager!\n");
        printf("Select an Option:\n");
        printf("a. Add an email to the mailing list.\n");
        printf("b. Print all emails in the mailing list.\n");
        printf("c. Exit.\n");
        printf("Option: ");
        scanf(" %c", &option);
        switch (option) {
            case 'a':
                printf("Enter the name: ");
                scanf("%s", name);
                printf("Enter the email: ");
                scanf("%s", email);
                addEmail(&list, name, email);
                break;
            case 'b':
                printEmails(list);
                break;
            case 'c':
                exit = true;
                break;
            default:
                printf("Error: Invalid option selected!\n");
                break;
        }
    }
    return 0;
}