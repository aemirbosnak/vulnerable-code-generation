//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct MailList {
    char name[MAX];
    struct MailList *next;
} MailList;

void addMail(MailList **head) {
    MailList *newNode = (MailList *)malloc(sizeof(MailList));
    printf("Enter name: ");
    scanf("%s", newNode->name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void displayMail(MailList *head) {
    while (head) {
        printf("Name: %s\n", head->name);
        head = head->next;
    }
}

int main() {
    MailList *head = NULL;

    while (1) {
        printf("1. Add Mail\n");
        printf("2. Display Mail\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMail(&head);
                break;
            case 2:
                displayMail(head);
                break;
            default:
                exit(0);
        }
    }

    return 0;
}