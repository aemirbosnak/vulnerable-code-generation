//FormAI DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold password information
struct Password {
    char username[20];
    char password[20];
    struct Password *next;
};

// function declarations
void addPassword(struct Password **head, char *username, char *password);
void displayPasswords(struct Password *head);
void deletePassword(struct Password **head, char *username);

int main() {
    struct Password *head = NULL;
    int choice;

    printf("Welcome to Password Manager!\n\n");

    do {
        printf("Please choose an option:\n");
        printf("1. Add a password\n");
        printf("2. Display all passwords\n");
        printf("3. Delete a password\n");
        printf("4. Exit\n\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char username[20], password[20];
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                addPassword(&head, username, password);
                printf("\nPassword added successfully!\n\n");
                break;
            }
            case 2: {
                printf("\nAll passwords:\n\n");
                displayPasswords(head);
                printf("\n");
                break;
            }
            case 3: {
                char username[20];
                printf("\nEnter the username of the password you want to delete: ");
                scanf("%s", username);
                deletePassword(&head, username);
                printf("\nPassword deleted successfully!\n\n");
                break;
            }
            case 4: {
                printf("\nGoodbye!\n");
                break;
            }
            default: {
                printf("\nInvalid choice, please try again.\n\n");
                break;
            }
        }
    } while (choice != 4);

    return 0;
}

// function to add a password to the linked list
void addPassword(struct Password **head, char *username, char *password) {
    // create new Password node
    struct Password *newPassword = malloc(sizeof(struct Password));

    // set node values
    strcpy(newPassword->username, username);
    strcpy(newPassword->password, password);
    newPassword->next = NULL;

    if (*head == NULL) {
        // list is empty, so set head to new node
        *head = newPassword;
    } else {
        // traverse list to find end and add new node
        struct Password *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPassword;
    }
}

// function to display all passwords in the linked list
void displayPasswords(struct Password *head) {
    if (head == NULL) {
        // list is empty
        printf("There are no passwords to display.\n\n");
    } else {
        // traverse list and print each node
        while (head != NULL) {
            printf("Username: %s\n", head->username);
            printf("Password: %s\n\n", head->password);
            head = head->next;
        }
    }
}

// function to delete a password from the linked list
void deletePassword(struct Password **head, char *username) {
    if (*head == NULL) {
        // list is empty
        printf("There are no passwords to delete.\n\n");
    } else {
        // traverse list and delete node if username matches
        struct Password *current = *head;
        struct Password *previous = NULL;
        while (current != NULL) {
            if (strcmp(current->username, username) == 0) {
                // match found, so delete node and update pointers
                if (previous == NULL) {
                    // first node matched, so set head to next node
                    *head = current->next;
                } else {
                    // set previous node to next node
                    previous->next = current->next;
                }
                free(current);
                return;
            }
            previous = current;
            current = current->next;
        }
        printf("Password not found.\n\n");
    }
}