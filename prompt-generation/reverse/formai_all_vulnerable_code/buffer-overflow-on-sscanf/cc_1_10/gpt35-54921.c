//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char email[100];
    struct node *next;
} Node;

Node *list = NULL;

void addEmailToList(char email[]) {
    Node *temp = list;
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    if (!list) {
        list = newNode;
        return;
    }
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void removeEmailFromList(char email[]) {
    Node *temp = list;
    Node *prev = NULL;
    while (temp) {
        if (strcmp(temp->email, email) == 0) {
            if (!prev) {
                list = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void printEmailList() {
    printf("Mailing List:\n");
    Node *temp = list;
    while (temp) {
        printf("%s\n", temp->email);
        temp = temp->next;
    }
}

int main() {
    printf("Enter your commands:\n");
    printf("To add an email to the list, enter '+ email'\n");
    printf("To remove an email from the list, enter '- email'\n");
    printf("To print the current mailing list, enter 'p'\n");
    printf("To quit, enter 'q'\n");

    char input[100];
    char email[100];
    char sign;
    int quit = 0;

    while (!quit) {
        printf("> ");
        fgets(input, 100, stdin);
        sscanf(input, "%c %s", &sign, email);
        switch (sign) {
            case '+':
                addEmailToList(email);
                printf("Added %s to the mailing list.\n", email);
                break;
            case '-':
                removeEmailFromList(email);
                printf("Removed %s from the mailing list.\n", email);
                break;
            case 'p':
                printEmailList();
                break;
            case 'q':
                quit = 1;
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    printf("Goodbye!\n");

    // free memory allocated
    Node *temp = list;
    Node *prev = NULL;
    while (temp) {
        prev = temp;
        temp = temp->next;
        free(prev);
    }

    return 0;
}