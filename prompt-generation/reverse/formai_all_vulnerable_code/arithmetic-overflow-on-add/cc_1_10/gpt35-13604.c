//FormAI DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000 // Maximum number of emails the mailing list can hold

struct user {
    char name[50];
    char email[50];
};

struct mailing_list {
    struct user users[MAX_EMAILS]; // Array to hold user information
    int count; // Keeps track of the number of emails in the list
};

void add_user(struct mailing_list *list);
void remove_user(struct mailing_list *list);
void print_list(struct mailing_list *list);

int main() {
    struct mailing_list list;
    list.count = 0; // Initialize count to 0

    int choice;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("--------------------\n");
        printf("1. Add User\n");
        printf("2. Remove User\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user(&list);
                break;
            case 2:
                remove_user(&list);
                break;
            case 3:
                print_list(&list);
                break;
            case 4:
                printf("\nGoodbye!\n\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_user(struct mailing_list *list) {
    if (list->count == MAX_EMAILS) { // Check if mailing list is full
        printf("\nMailing list is full. Cannot add anymore users.\n");
        return;
    }

    printf("\nEnter user name: ");
    scanf("%s", list->users[list->count].name);

    printf("Enter user email: ");
    scanf("%s", list->users[list->count].email);

    list->count++; // Increment count
    printf("\nUser added successfully!\n");
}

void remove_user(struct mailing_list *list) {
    if (list->count == 0) { // Check if mailing list is empty
        printf("\nMailing list is empty. Cannot remove users.\n");
        return;
    }

    char email[50];
    printf("\nEnter email address of user to remove: ");
    scanf("%s", email);

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->users[i].email, email) == 0) { // Check if email matches
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->users[j].name, list->users[j+1].name); // Shift names left by one
                strcpy(list->users[j].email, list->users[j+1].email); // Shift emails left by one
            }
            list->count--; // Decrement count
            printf("\nUser removed successfully!\n");
            return;
        }
    }

    printf("\nUser with email %s not found.\n", email);
}

void print_list(struct mailing_list *list) {
    if (list->count == 0) { // Check if mailing list is empty
        printf("\nMailing list is empty. Nothing to print.\n");
        return;
    }

    printf("\nMailing list:\n");
    printf("--------------\n");

    for (int i = 0; i < list->count; i++) {
        printf("%s, %s\n", list->users[i].name, list->users[i].email);
    }
}