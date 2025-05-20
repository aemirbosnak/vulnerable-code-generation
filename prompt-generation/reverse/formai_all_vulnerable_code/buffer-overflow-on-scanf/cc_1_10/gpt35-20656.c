//FormAI DATASET v1.0 Category: Mailing list manager ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct emailSubscriber {
    char name[50];
    char email[50];
    struct emailSubscriber *next;
} Subscriber;

Subscriber* createSubscriber(char name[], char email[]) {
    Subscriber *sub = (Subscriber*)malloc(sizeof(Subscriber));
    strcpy(sub->name, name);
    strcpy(sub->email, email);
    sub->next = NULL;
    return sub;
}

void addSubscriber(Subscriber **head_ref, char name[], char email[]) {
    Subscriber *new_sub = createSubscriber(name, email);
    if (*head_ref == NULL) {
        *head_ref = new_sub;
        return;
    }
    Subscriber *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_sub;
}

void printSubscribers(Subscriber *sub) {
    while (sub != NULL) {
        printf("%s <%s>\n", sub->name, sub->email);
        sub = sub->next;
    }
}

void deleteSubscriber(Subscriber **head_ref, char email[]) {
    Subscriber *temp = *head_ref, *prev;
    if (temp != NULL && strcmp(temp->email, email) == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nSubscriber with email id %s not found!\n", email);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void updateSubscriber(Subscriber *sub, char email[], char newName[], char newEmail[]) {
    while (sub != NULL) {
        if (strcmp(sub->email, email) == 0) {
            strcpy(sub->name, newName);
            strcpy(sub->email, newEmail);
            printf("\nSubscriber updated successfully!\n");
            return;
        }
        sub = sub->next;
    }
    printf("\nSubscriber with email id %s not found!\n", email);
}

void searchSubscriber(Subscriber *sub, char name[]) {
    int found = 0;
    while (sub != NULL) {
        if (strcmp(sub->name, name) == 0) {
            printf("%s <%s>\n", sub->name, sub->email);
            found = 1;
        }
        sub = sub->next;
    }
    if (!found) {
        printf("\nSubscriber with name %s not found!\n", name);
    }
}

int main() {
    Subscriber *head = NULL;
    int choice;
    do {
        printf("\nMENU:\n");
        printf("1. Add subscriber\n");
        printf("2. Delete subscriber\n");
        printf("3. Update subscriber\n");
        printf("4. Search subscriber\n");
        printf("5. View all subscribers\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char name[50], email[50];
                printf("\nEnter subscriber's name: ");
                scanf("%s", name);
                printf("Enter subscriber's email: ");
                scanf("%s", email);
                addSubscriber(&head, name, email);
                printf("\nSubscriber added successfully!\n");
                break;
            }
            case 2: {
                char email[50];
                printf("\nEnter subscriber's email to be deleted: ");
                scanf("%s", email);
                deleteSubscriber(&head, email);
                break;
            }
            case 3: {
                char email[50], newName[50], newEmail[50];
                printf("\nEnter subscriber's email to be updated: ");
                scanf("%s", email);
                printf("Enter subscriber's new name: ");
                scanf("%s", newName);
                printf("Enter subscriber's new email: ");
                scanf("%s", newEmail);
                updateSubscriber(head, email, newName, newEmail);
                break;
            }
            case 4: {
                char name[50];
                printf("\nEnter subscriber's name to be searched: ");
                scanf("%s", name);
                searchSubscriber(head, name);
                break;
            }
            case 5: {
                printf("\nViewing all subscribers:\n");
                printSubscribers(head);
                break;
            }
            case 6: {
                printf("\nExiting...\n");
                break;
            }
            default: {
                printf("\nInvalid choice, please try again.\n");
            }
        }
    } while (choice != 6);
    return 0;
}