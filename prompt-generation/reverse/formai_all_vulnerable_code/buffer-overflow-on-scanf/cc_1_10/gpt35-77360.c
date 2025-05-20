//FormAI DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    char email[50];
    struct ListNode* next;
} ListNode;

ListNode* head = NULL;

void addToList(char* email) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        ListNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList() {
    printf("Current Mailing List:\n");
    ListNode* current = head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

void removeFromList(char* email) {
    ListNode* current = head;
    ListNode* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }
            free(current);
            printf("%s has been removed from the list.\n", email);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("%s was not found in the list.\n", email);
}

int main() {
    printf("Welcome to the Greatest Mailing List Manager Ever! (patent pending)\n");
    printf("Enter 1 to add an email to the list.\n");
    printf("Enter 2 to remove an email from the list.\n");
    printf("Enter 3 to view the current mailing list.\n");
    printf("Enter 4 to quit.\n");
    int choice;
    char email[50];
    while (1) {
        printf("Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addToList(email);
                printf("%s has been added to the list.\n", email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeFromList(email);
                break;
            case 3:
                printList();
                break;
            case 4:
                printf("Thanks for using the Greatest Mailing List Manager Ever! (patent pending)\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}