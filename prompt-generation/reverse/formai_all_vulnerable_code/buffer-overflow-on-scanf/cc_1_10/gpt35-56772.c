//FormAI DATASET v1.0 Category: Mailing list manager ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct subscriber {
    char name[100];
    char email[100];
    struct subscriber *next;
} Subscriber;

Subscriber *head = NULL;

void addSubscriber(char *name, char *email) {
    Subscriber *newSub = (Subscriber*)malloc(sizeof(Subscriber));
    strcpy(newSub->name, name);
    strcpy(newSub->email, email);
    newSub->next = NULL;

    if (head == NULL) {
        head = newSub;
    } else {
        Subscriber *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSub;
    }
}

void printList() {
    Subscriber *current = head;
    printf("Mailing List:\n");
    printf("----------------------------------------------------\n");
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->email);
        current = current->next;
    }
}

void deleteSubscriber(char *email) {
    if (head == NULL) {
        printf("Mailing list is empty.\n");
    } else {
        Subscriber *current = head;
        Subscriber *previous = NULL;

        while (current != NULL) {
            if (strcmp(current->email, email) == 0) { // found subscriber
                if (current == head) { // if head needs to be removed
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                printf("Subscriber with email %s has been removed.\n", email);
                free(current);
                return;
            }
            previous = current;
            current = current->next;
        }

        printf("Subscriber with email %s was not found.\n", email);
    }
}

void clearList() {
    Subscriber *current = head;
    while (current != NULL) {
        Subscriber *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    printf("Mailing list has been cleared.\n");
}

int main() {
    char name[100], email[100];
    int choice;
    while(1) {
        printf("\n==============================\n");
        printf("Mailing list manager:\n");
        printf("1. Add subscriber\n");
        printf("2. Print list\n");
        printf("3. Delete subscriber\n");
        printf("4. Clear list\n");
        printf("5. Quit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter subscriber name: ");
                scanf("%s", name);
                printf("Enter subscriber email: ");
                scanf("%s", email);
                addSubscriber(name, email);
                printf("Subscriber %s added to mailing list.\n", name);
                break;
            case 2:
                printList();
                break;
            case 3:
                printf("Enter subscriber email to be removed: ");
                scanf("%s", email);
                deleteSubscriber(email);
                break;
            case 4:
                clearList();
                break;
            case 5:
                printf("Quitting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}