//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct EmailList {
    char email[50];
    struct EmailList *next;
}EmailList;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addEmail(EmailList **head, char *email) {
    EmailList *newEmail = (EmailList*) malloc(sizeof(EmailList));

    if(newEmail == NULL) {
        printf("Could not allocate memory for new email\n");
        return;
    }

    strcpy(newEmail->email, email);
    newEmail->next = NULL;

    if(*head == NULL) {
        *head = newEmail;
        return;
    }

    EmailList *temp = *head;

    while(temp->next != NULL) {
        if(strcmp(temp->email, email) == 0) {
            printf("Email already exists in the list\n");
            free(newEmail);
            return;
        }
        temp = temp->next;
    }

    if(strcmp(temp->email, email) == 0) {
        printf("Email already exists in the list\n");
        free(newEmail);
        return;
    }

    temp->next = newEmail;
}

void removeEmail(EmailList **head, char *email) {
    if(*head == NULL) {
        printf("Email list is already empty\n");
        return;
    }

    EmailList *temp = *head;
    EmailList *prev = NULL;

    while(temp != NULL) {
        if(strcmp(temp->email, email) == 0) {
            if(prev == NULL) {
                *head = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            free(temp);
            printf("%s was removed from the list\n", email);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("%s does not exist in the list\n", email);
}

void printEmailList(EmailList *head) {
    if(head == NULL) {
        printf("Email list is empty\n");
        return;
    }

    printf("Email list:\n");
    while(head != NULL) {
        printf("%s\n", head->email);
        head = head->next;
    }
}

int main() {
    EmailList *head = NULL;

    int choice;
    char email[50];

    while(1) {
        printf("-----------MENU-----------\n");
        printf("[1] Add Email\n");
        printf("[2] Remove Email\n");
        printf("[3] Print Email List\n");
        printf("[4] Exit\n");
        printf("--------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter email to add: ");
                clearBuffer();
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;
                addEmail(&head, email);
                break;
            }

            case 2: {
                printf("Enter email to remove: ");
                clearBuffer();
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;
                removeEmail(&head, email);
                break;
            }

            case 3: {
                printEmailList(head);
                break;
            }

            case 4: {
                printf("Thank you for using the Email List Manager!\n");
                exit(0);
            }

            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}