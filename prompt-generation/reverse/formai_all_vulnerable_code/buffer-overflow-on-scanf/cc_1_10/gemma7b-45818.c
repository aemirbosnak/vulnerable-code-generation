//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_ Mailing_LIST_SIZE 100

typedef struct MailingList {
    char name[MAX_NAME_LENGTH];
    struct MailingList* next;
} MailingList;

MailingList* addNewMailingListEntry(MailingList* head) {
    MailingList* newNode = (MailingList*)malloc(sizeof(MailingList));
    newNode->next = NULL;

    printf("Enter the name of the recipient: ");
    scanf("%s", newNode->name);

    head = newNode;

    return head;
}

void printMailingList(MailingList* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        head = head->next;
    }
}

int main() {
    MailingList* head = NULL;

    printf("Welcome to the Jolly Mailing List Manager!\n");

    while (1) {
        printf("What would you like to do? (Add/Print/Exit): ");
        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                addNewMailingListEntry(head);
                break;
            case 'p':
                printMailingList(head);
                break;
            case 'e':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}