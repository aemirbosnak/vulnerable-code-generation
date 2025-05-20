//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIST_SIZE 1000

// Node structure for linked list implementation
struct node {
    char name[50];
    char email[100];
    struct node *next;
};

struct node *head = NULL;
int count = 0;

void add_node(char *name, char *email) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    }
    else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    count++;
}

void remove_node(char *email) {
    struct node *temp = head;
    struct node *prev = NULL;

    while (temp!= NULL) {
        if (strcmp(temp->email, email) == 0) {
            if (prev == NULL) {
                head = temp->next;
            }
            else {
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

void display_list() {
    struct node *temp = head;
    printf("\nMailing List:\n");
    printf("Name\tEmail\n");

    while (temp!= NULL) {
        printf("%s\t%s\n", temp->name, temp->email);
        temp = temp->next;
    }
}

int main() {
    char choice;
    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Contact\n2. Remove Contact\n3. Display List\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", head->name);
                printf("Enter email: ");
                scanf("%s", head->email);
                add_node(head->name, head->email);
                break;
            case '2':
                printf("Enter email to remove: ");
                scanf("%s", head->email);
                remove_node(head->email);
                break;
            case '3':
                display_list();
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '4');

    return 0;
}