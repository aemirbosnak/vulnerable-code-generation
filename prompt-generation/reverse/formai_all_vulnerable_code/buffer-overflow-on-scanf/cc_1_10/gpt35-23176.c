//FormAI DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold each subscriber's information
typedef struct {
    char email[50];
    int status;
} Subscriber;

/*
 * This function displays the main menu with options to:
 * 1. Add a subscriber
 * 2. Remove a subscriber
 * 3. List all subscribers
 * 4. Exit the program
 */
void display_menu() {
    printf("Welcome to the Mailing List Manager!\n");
    printf("Please choose an option:\n");
    printf("1. Add a subscriber\n");
    printf("2. Remove a subscriber\n");
    printf("3. List all subscribers\n");
    printf("4. Exit the program\n");
}

/*
 * This function adds a subscriber to the mailing list
 */
void add_subscriber(Subscriber *list, int *num_subscribers) {
    printf("Please enter the email address of the subscriber: ");
    char email[50];
    scanf("%s", email);
    int duplicate = 0;
    for (int i = 0; i < *num_subscribers; i++) {
        if (strcmp(list[i].email, email) == 0) {
            duplicate = 1;
            printf("Error: This email address is already subscribed.\n");
            break;
        }
    }
    if (!duplicate) {
        strcpy(list[*num_subscribers].email, email);
        list[*num_subscribers].status = 1;
        (*num_subscribers)++;
        printf("Subscriber added successfully.\n");
    }
}

/*
 * This function removes a subscriber from the mailing list
 */
void remove_subscriber(Subscriber *list, int *num_subscribers) {
    printf("Please enter the email address of the subscriber to remove: ");
    char email[50];
    scanf("%s", email);
    int found = 0;
    for (int i = 0; i < *num_subscribers; i++) {
        if (strcmp(list[i].email, email) == 0) {
            found = 1;
            list[i].status = 0;
            printf("Subscriber removed successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Error: Subscriber not found.\n");
    }
}

/*
 * This function lists all subscribers
 */
void list_subscribers(Subscriber *list, int *num_subscribers) {
    printf("List of subscribers:\n");
    for (int i = 0; i < *num_subscribers; i++) {
        if (list[i].status) {
            printf("%s\n", list[i].email);
        }
    }
}

int main() {
    Subscriber list[100];
    int num_subscribers = 0;
    int choice = 0;
    while (choice != 4) {
        display_menu();
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_subscriber(list, &num_subscribers);
                break;
            case 2:
                remove_subscriber(list, &num_subscribers);
                break;
            case 3:
                list_subscribers(list, &num_subscribers);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}