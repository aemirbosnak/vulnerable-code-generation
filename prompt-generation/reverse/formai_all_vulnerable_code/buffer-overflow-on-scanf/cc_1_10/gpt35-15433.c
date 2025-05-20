//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
// Mailing List Manager Program - An Ada Lovelace Style Example

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function prototypes
void add_email();
void remove_email();
void display_list();
void search_email();

// Define the linked list structure
struct node {
    char email[50];
    struct node *next;
} *head, *tail;

// Main function
int main() {
    int choice;
    head = NULL;
    tail = NULL;

    printf("Welcome to Mailing List Manager Program!\n");

    do {
        printf("\n");
        printf("1. Add email to list\n");
        printf("2. Remove email from list\n");
        printf("3. Display list\n");
        printf("4. Search for email\n");
        printf("5. Exit program\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email(); // Calls function to add an email to the list
                break;
            case 2:
                remove_email(); // Calls function to remove an email from the list
                break;
            case 3:
                display_list(); // Calls function to print the list of emails
                break;
            case 4:
                search_email(); // Calls function to search for an email in the list
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add email to the list
void add_email() {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("Failed to allocate memory!\n");
        return;
    }

    printf("\nEnter email to be added: ");
    scanf("%s", temp->email);
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = tail->next;
    }

    printf("%s added to list!\n", tail->email);
}

// Function to remove email from the list
void remove_email() {
    char email[50];
    struct node *temp, *prev;

    printf("\nEnter email to be removed: ");
    scanf("%s", email);

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (strcmp(head->email, email) == 0) {
        temp = head;
        head = head->next;
        free(temp);
        printf("%s removed from list!\n", email);
        return;
    }

    prev = head;
    temp = head->next;

    while (temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%s not found in list!\n", email);
        return;
    }

    if (temp == tail) {
        tail = prev;
        tail->next = NULL;
    }

    prev->next = temp->next;
    free(temp);
    printf("%s removed from list!\n", email);
}

// Function to print the list of emails
void display_list() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    while (temp != NULL) {
        printf("%s\n", temp->email);
        temp = temp->next;
    }
}

// Function to search for an email in the list
void search_email() {
    char email[50];
    struct node *temp;
    int found = 0;

    printf("\nEnter email to be searched: ");
    scanf("%s", email);

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0) {
            printf("%s found in list!\n", email);
            found = 1;
            break;
        }

        temp = temp->next;
    }

    if (found == 0) {
        printf("%s not found in list!\n", email);
    }
}