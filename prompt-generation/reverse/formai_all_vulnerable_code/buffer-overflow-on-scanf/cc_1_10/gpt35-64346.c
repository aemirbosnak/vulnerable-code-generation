//FormAI DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold the details of a subscriber
typedef struct subscriber {
    char name[50];
    char email[50];
    int active;
    struct subscriber* next;
} Subscriber;

// helper function to get user input
void getInput(char* prompt, char* buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // remove new line character
}

// function to add a new subscriber to the mailing list
void addSubscriber(Subscriber** head) {
    Subscriber* newSubscriber = (Subscriber*) malloc(sizeof(Subscriber));
    if (newSubscriber == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }

    getInput("Enter subscriber name: ", newSubscriber->name, sizeof(newSubscriber->name));
    getInput("Enter subscriber email: ", newSubscriber->email, sizeof(newSubscriber->email));
    newSubscriber->active = 1;
    newSubscriber->next = NULL;

    if (*head == NULL) {
        *head = newSubscriber;
    } else {
        Subscriber* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSubscriber;
    }

    printf("Subscriber added successfully!\n");
}

// function to remove a subscriber from the mailing list
void removeSubscriber(Subscriber** head) {
    char email[50];
    getInput("Enter subscriber email: ", email, sizeof(email));

    Subscriber* current = *head;
    Subscriber* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Subscriber removed successfully!\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Error: Subscriber not found!\n");
}

// function to display the details of all subscribers in the mailing list
void displaySubscribers(Subscriber* head) {
    if (head == NULL) {
        printf("Mailing list is empty.\n");
        return;
    }

    printf("Name\tEmail\t\tStatus\n");
    printf("----\t-----\t\t------\n");

    Subscriber* current = head;
    while (current != NULL) {
        printf("%s\t%s\t%s\n", current->name, current->email, current->active ? "Active" : "Inactive");
        current = current->next;
    }
}

// function to update the status of a subscriber
void updateSubscriber(Subscriber* head) {
    char email[50];
    getInput("Enter subscriber email: ", email, sizeof(email));

    Subscriber* current = head;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            int choice;
            printf("Update %s's status:\n", current->name);
            printf("1. Active\n");
            printf("2. Inactive\n");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                current->active = 1;
                printf("%s's status updated to active.\n", current->name);
                return;
            case 2:
                current->active = 0;
                printf("%s's status updated to inactive.\n", current->name);
                return;
            default:
                printf("Invalid choice!\n");
                return;
            }
        }
        current = current->next;
    }

    printf("Error: Subscriber not found!\n");
}

int main() {
    Subscriber* mailingList = NULL;
    int choice;

    do {
        printf("\n");
        printf("Mailing List Manager\n");
        printf("====================\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Update Subscriber Status\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        getchar(); // clear newline character from input buffer

        switch (choice) {
        case 1:
            addSubscriber(&mailingList);
            break;
        case 2:
            removeSubscriber(&mailingList);
            break;
        case 3:
            displaySubscribers(mailingList);
            break;
        case 4:
            updateSubscriber(mailingList);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 5);

    return 0;
}