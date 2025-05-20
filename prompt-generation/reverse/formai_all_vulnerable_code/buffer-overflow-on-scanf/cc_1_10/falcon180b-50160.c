//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for mailing list
typedef struct {
    char name[50];
    char email[100];
} MailingList;

// Function to add a new subscriber to the mailing list
void addSubscriber(MailingList* list) {
    int size = sizeof(list->name);
    printf("Enter the name of the subscriber: ");
    scanf("%s", list->name);

    size = sizeof(list->email);
    printf("Enter the email address of the subscriber: ");
    scanf("%s", list->email);
}

// Function to remove a subscriber from the mailing list
void removeSubscriber(MailingList* list) {
    int size = sizeof(list->name);
    printf("Enter the name of the subscriber to remove: ");
    scanf("%s", list->name);

    for (int i = 0; i < 10; i++) {
        if (strcmp(list->name, list[i].name) == 0) {
            strcpy(list[i].name, "");
            strcpy(list[i].email, "");
            printf("Subscriber removed successfully.\n");
            break;
        }
    }
}

// Function to display the mailing list
void displayList(MailingList* list) {
    printf("Mailing List:\n");
    for (int i = 0; i < 10; i++) {
        if (list[i].name[0]!= '\0') {
            printf("%s - %s\n", list[i].name, list[i].email);
        }
    }
}

// Main function
int main() {
    MailingList list[10];

    int choice;
    do {
        printf("Mailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Display mailing list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addSubscriber(list);
            break;

        case 2:
            removeSubscriber(list);
            break;

        case 3:
            displayList(list);
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}