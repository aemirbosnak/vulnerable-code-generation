//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    struct node* next;
} node;

node* head = NULL;
int count = 0;

void add_email(char* email) {
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    count++;
}

void remove_email(char* email) {
    node* temp = head;
    node* prev = NULL;

    while (temp!= NULL) {
        if (strcmp(temp->email, email) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            count--;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

void print_emails() {
    node* temp = head;

    printf("Total emails: %d\n", count);

    while (temp!= NULL) {
        printf("%s\n", temp->email);
        temp = temp->next;
    }
}

int main() {
    char choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add email address\n");
        printf("2. Remove email address\n");
        printf("3. Print all email addresses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1': {
                char email[MAX_EMAIL_LENGTH];
                printf("Enter email address: ");
                scanf("%s", email);
                add_email(email);
                break;
            }
            case '2': {
                char email[MAX_EMAIL_LENGTH];
                printf("Enter email address to remove: ");
                scanf("%s", email);
                remove_email(email);
                break;
            }
            case '3': {
                print_emails();
                break;
            }
            case '4': {
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    } while (choice!= '4');

    return 0;
}