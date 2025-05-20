//FormAI DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
/*
Post-apocalyptic Mailing List Manager
By: [Your Name Here]

This program allows users to manage their mailing lists in a world torn apart by apocalyptic disaster.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

// Struct to hold subscriber information
struct Subscriber {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

// Global array of subscribers
struct Subscriber subscribers[MAX_EMAILS];

// Function prototypes
void addSubscriber();
void removeSubscriber();
void printList();

// Main function
int main() {
    int choice;
    printf("Welcome to the Post-Apocalyptic Mailing List Manager!\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Print List\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addSubscriber();
                break;
            case 2:
                removeSubscriber();
                break;
            case 3:
                printList();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}

// Function to add a subscriber to the list
void addSubscriber() {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    printf("\nEnter subscriber name: ");
    scanf("%s", name);
    printf("Enter subscriber email address: ");
    scanf("%s", email);
    // Check if list is full
    if (sizeof(subscribers) / sizeof(subscribers[0]) >= MAX_EMAILS) {
        printf("Sorry, the mailing list is full!\n");
        return;
    }
    // Check if subscriber already exists
    for (int i = 0; i < sizeof(subscribers) / sizeof(subscribers[0]); i++) {
        if (strcmp(name, subscribers[i].name) == 0) {
            printf("Sorry, that subscriber is already on the list!\n");
            return;
        }
    }
    // Add subscriber to list
    for (int i = 0; i < sizeof(subscribers) / sizeof(subscribers[0]); i++) {
        if (strlen(subscribers[i].name) == 0) {
            strncpy(subscribers[i].name, name, MAX_NAME_LEN);
            strncpy(subscribers[i].email, email, MAX_EMAIL_LEN);
            printf("%s has been added to the mailing list!\n", name);
            return;
        }
    }
}

// Function to remove a subscriber from the list
void removeSubscriber() {
    char name[MAX_NAME_LEN];
    printf("Enter the name of the subscriber to be removed: ");
    scanf("%s", name);
    // Find subscriber in list
    for (int i = 0; i < sizeof(subscribers) / sizeof(subscribers[0]); i++) {
        if (strcmp(name, subscribers[i].name) == 0) {
            subscribers[i].name[0] = '\0';
            subscribers[i].email[0] = '\0';
            printf("%s has been removed from the mailing list!\n", name);
            return;
        }
    }
    printf("Sorry, that subscriber is not on the list.\n");
}

// Function to print the entire list of subscribers
void printList() {
    printf("Current mailing list:\n");
    for (int i = 0; i < sizeof(subscribers) / sizeof(subscribers[0]); i++) {
        if (strlen(subscribers[i].name) != 0) {
            printf("%s - %s\n", subscribers[i].name, subscribers[i].email);
        }
    }
}